/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:42:39 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/31 13:07:37 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int m_rawBits;
	static const int m_fractionalBits = 8;

public:
//Required by Rule of Three
   	Fixed();                        // Default constructor
    Fixed(const int intValue);      // Int constructor
    Fixed(const float floatValue);  // Float constructor
    Fixed(const Fixed& src);        // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy Assignment Operator 
	~Fixed();                       // Destructor
	
//NOT Required by Rule of Three
    // Comparison operators
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // Increment and decrement
    Fixed &operator++();       // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed &operator--();       // Pre-decrement
    Fixed operator--(int);     // Post-decrement

    // Static min and max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

	   // Conversion functions
    float toFloat() const;
    int toInt() const;
};
//This is a free-standing function (not a member of the class).
// It is declared outside the class and only uses Fixed, usually as a friend or through its public API.
//we overload it to make it easy to print Fixed objects with std::cout or any output stream.
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
