/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:27:03 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/29 20:59:21 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

// Fixed class represents a fixed-point number
class Fixed
{
private:
	int m_rawBits;							// The raw integer value to store the fixed-point number
	static const int m_fractionalBits;		// The number of fractional bits(кол-во битов под дробную часть ) (always 8)

public:
	Fixed();								// Default constructor
	Fixed(const Fixed &other);				// Copy constructor
	Fixed &operator=(const Fixed &other);	// Copy assignment operator for =
	~Fixed();								// Destructor

	int getRawBits(void) const;				// Returns the raw value of the fixed-point number
	void setRawBits(int const raw);			// Sets the raw value of the fixed-point number
};

#endif