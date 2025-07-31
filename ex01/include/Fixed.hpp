/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:09:58 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/31 13:08:35 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int m_rawBits;
    static const int m_fractionalBits = 8;

public:
    Fixed();                        	// Default constructor
    Fixed(const int intValue);     
    Fixed(const float floatValue); 
    Fixed(const Fixed& src);        	// Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy Assignment Operator 
	~Fixed();                     		

    float toFloat(void) const;
    int toInt(void) const;
};
/*
The operator<< for std::ostream cannot be a member of my class because the left operand (std::ostream) is not my class.
It must be a non-member function, but it should have access to my class’s public interface (toFloat() etc).
the subject expects that it should be declared in the header file outside the class definition.
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
