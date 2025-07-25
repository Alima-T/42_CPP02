/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:42:35 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/25 18:19:35 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath>

// Constructors & Destructor
Fixed::Fixed() : m_rawBits(0) {}

Fixed::Fixed(const int value) {
    m_rawBits = value << m_fractionalBits;
}

Fixed::Fixed(const float value) {
    m_rawBits = roundf(value * (1 << m_fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed::~Fixed() {}

// Copy assignment
Fixed &Fixed::operator=(const Fixed &rhs) {
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
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.m_rawBits = m_rawBits + rhs.m_rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.m_rawBits = m_rawBits - rhs.m_rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result.m_rawBits = (static_cast<long>(m_rawBits) * rhs.m_rawBits) >> m_fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    result.m_rawBits = (static_cast<long>(m_rawBits) << m_fractionalBits) / rhs.m_rawBits;
    return result;
}

// Increment/Decrement
Fixed &Fixed::operator++() {
    ++m_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    --m_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// ternary operator (a < b) ? a : b;
// returns the smaller of a and b
// Calls overloaded < operator
// Returns a reference, not a copy
// Min/Max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b; // TODO ask if it is possible to use ternary operator?
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// static_cast is a C++ type conversion operator that safely converts one type to another at compile time.
// Conversions
float Fixed::toFloat() const {
    return static_cast<float>(m_rawBits) / (1 << m_fractionalBits);
}

int Fixed::toInt() const {
    return m_rawBits >> m_fractionalBits;
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
