/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:12:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/31 19:00:36 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main(void) 
{
	Fixed a;					// Default constructor
	Fixed const b(10);			// Int constructor
	Fixed const c(42.42f);		// Float constructor
	Fixed const d(b);			// Copy constructor
	
	a = Fixed(1234.4321f);		// Float constructor + assignment operator
	std::cout << "#################"<<std::endl;
	// Output using overloaded << operator
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "#################"<<std::endl;
	
	// Output integer conversions
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	std::cout << "#################"<<std::endl;
	// to float example
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	
	// std::cout << "#################"<<std::endl;
	// // extra test for 3.33333f
	// std::cout << "extra test"<<std::endl;
	// Fixed z(3.33333f);
	// std::cout << "z is " << z << std::endl;
	// std::cout << "z is " << z.toInt() << " as integer" << std::endl;
	// std::cout << "z is " << z.toFloat() << " as float" << std::endl;
	return 0;
}
