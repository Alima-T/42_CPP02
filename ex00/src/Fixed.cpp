/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:51:35 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/29 21:17:51 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

// Define and initialize the static constant member (fractional bits count)
const int Fixed::m_fractionalBits = 8;

// Default constructor
// Initializes the raw fixed-point value to 0
Fixed::Fixed() : m_rawBits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
// Initializes a new object by copying the state of another Fixed object
Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Use the copy assignment operator
	// this->m_rawBits = other.getRawBits(); // Copy the internal raw value
}

// Copy assignment operator
// Assigns the value from another Fixed object to the current object
Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
	{ // Prevent self-assignment
		this->m_rawBits = other.getRawBits(); // Copy the internal raw value
	}
	return *this; // Return reference to current object
}

// Destructor
// Called when a Fixed object goes out of scope or is deleted
Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

// Returns the internal raw value (m_rawBits) and logs a message
int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->m_rawBits;
}

// Sets the internal raw value to the given raw integer
void Fixed::setRawBits(int const raw) 
{
	this->m_rawBits = raw;
}
