/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:42:35 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/31 15:33:14 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath>

// Constructors & Destructor
Fixed::Fixed() : m_rawBits(0) {}

Fixed::Fixed(const int value) { m_rawBits = value << m_fractionalBits; }

Fixed::Fixed(const float value) { m_rawBits = roundf(value * (1 << m_fractionalBits)); }

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed() {}

// Copy assignment
/*
	Объект — это дом 🏠
✔️ this — это указатель на весь дом (текущий объект left-hand side).
✔️ this->m_rawBits — это "моя кухня".
✔️ rhs.m_rawBits — "кухня другого дома" (куда копируем right-hand side).
✔️ this != &rhs — проверка на самоприсваивание.
✔️ this != &rhs нужен только когда ты работаешь с ресурсами (*ptr указателями, файлами, памятью) и прописываем delete().
  Без проверки можно случайно потерять данные или даже получить мусор, если освободили память и пытаемся что-то из неё копировать.
✔️ Если поле — int, float, bool, и прочие примитивы — происходит перезапись без удаления, самоприсваивание не опасно, и проверку можно пропустить.
*/
Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		m_rawBits = rhs.m_rawBits;
	return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const { return m_rawBits > rhs.m_rawBits; }

bool Fixed::operator<(const Fixed &rhs) const { return m_rawBits < rhs.m_rawBits; }

bool Fixed::operator>=(const Fixed &rhs) const { return m_rawBits >= rhs.m_rawBits; }

bool Fixed::operator<=(const Fixed &rhs) const { return m_rawBits <= rhs.m_rawBits; }

bool Fixed::operator==(const Fixed &rhs) const { return m_rawBits == rhs.m_rawBits; }

bool Fixed::operator!=(const Fixed &rhs) const { return m_rawBits != rhs.m_rawBits; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.m_rawBits = m_rawBits + rhs.m_rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.m_rawBits = m_rawBits - rhs.m_rawBits;
	return result;
}

// static_cast is a C++ type conversion operator that safely converts one type to another at compile time.
//The result might overflow 32 bits because multiplication of two 32-bit(int) numbers can require up to 64 bits (long)
//Значение хранится как целое * 2^(-m_fractionalBits), где m_fractionalBits — количество бит для дробной части.
//При умножении двух int масштаб увеличивается до 2^(2 * m_fractionalBits), надо компенсировать сдвигом обратно, чтобы вернуть правильный масштаб.
Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	result.m_rawBits = (static_cast<long>(m_rawBits) * rhs.m_rawBits) >> m_fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	// check for division by zero, not necessary in this ex according to the subject
	// if (rhs.m_rawBits == 0)
	// {
	// 	throw std::runtime_error("Division by zero");
	// } // but catch it in the main
	result.m_rawBits = (static_cast<long>(m_rawBits) << m_fractionalBits) / rhs.m_rawBits;
	return result;
}

// pre-increment ++i
//Fixed& (reference) - To avoid copying and allow chaining
Fixed &Fixed::operator++()
{ 
	++m_rawBits;
	return *this;
}

// post-increment i++
/*
Fixed (by value) - Must return the old value (copy before increment)
Fixed temp(*this); // we made a copy of the current object
++(*this); // increment the current object
return temp; // return the copy before increament
*/
Fixed Fixed::operator++(int)
{ 
	Fixed temp(*this);
	++(*this);
	return temp;
}

// pre-decrement --i
Fixed &Fixed::operator--()
{
	--m_rawBits;
	return *this;
}

// post-decrement i--
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

// in c++ projects it is possible to use ternary operator
// ternary operator (a < b) ? a : b;
// returns the smaller of a and b
// Calls overloaded < operator
// Returns a reference, not a copy
// Min/Max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// static_cast is a C++ type conversion operator for safely converting
// Conversions
float Fixed::toFloat() const
{
	return static_cast<float>(m_rawBits) / (1 << m_fractionalBits);
}

int Fixed::toInt() const
{
	return m_rawBits >> m_fractionalBits;
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
