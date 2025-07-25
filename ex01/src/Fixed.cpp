/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:14:16 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/25 17:55:03 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath> // For roundf function

// Default constructor: Initializes raw bits to 0
Fixed::Fixed() : m_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Integer constructor: Converts integer to fixed-point value
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	// Convert int to fixed-point: value * 2^8
	// Shift integer left by 8 bits to create fixed-point value
	// Example: 10 becomes 10 * 256 = 2560
	m_rawBits = intValue << m_fractionalBits;
}

// Float constructor: Converts float to fixed-point value
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	// Multiply float by 2^8 (256) and round to nearest integer
	// Example: 42.42 * 256 = 10859.52 → rounded to 10860
	m_rawBits = roundf(floatValue * (1 << m_fractionalBits));
}

// Copy constructor: Creates a new object as a copy of an existing one
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// Delegate to assignment operator for actual copying
	*this = src;
}

// Assignment operator: Assigns values from one object to another
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{                              // Check for self-assignment
		m_rawBits = rhs.m_rawBits; // Copy the raw bits
	}
	return (*this); // Return reference to current object
}

// Destructor: Clean up resources (none in this case)
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Convert fixed-point value to float
float Fixed::toFloat(void) const
{
	// Divide raw bits by 256 (2^8) to get float value
	// Example: 2560 → 2560 / 256 = 10.0
	return (static_cast<float>(m_rawBits) / (1 << m_fractionalBits));
}

// Convert fixed-point value to integer
int Fixed::toInt(void) const
{
	// Shift right by 8 bits to get integer part (truncates fractional part)
	// Example: 2560 → 2560 >> 8 = 10
	return (m_rawBits >> m_fractionalBits);
}

// Overload of insertion operator for easy output
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	// Output the float representation of the fixed-point value
	out << fixed.toFloat();
	return (out);
}