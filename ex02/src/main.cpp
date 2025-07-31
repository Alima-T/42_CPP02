/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:41:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/31 19:02:54 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// === Extended tests ===
	Fixed c(2);
	Fixed d(5.05f);

	std::cout << "\n--- Arithmetic ---\n";
	std::cout << "d + c = " << (d + c) << std::endl;
	std::cout << "d - c = " << (d - c) << std::endl;
	std::cout << "d * c = " << (d * c) << std::endl;
	std::cout << "d / c = " << (d / c) << std::endl;

	std::cout << "\n--- Comparison ---\n";
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "\n--- Increment / Decrement ---\n";
	Fixed e;
	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "--e = " << --e << std::endl;
	std::cout << "e-- = " << e-- << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "\n--- Min / Max ---\n";
	Fixed f(10);
	Fixed g(20);
	const Fixed h(42.42f);
	const Fixed i(42.43f);

	std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;
	std::cout << "min(h, i) = " << Fixed::min(h, i) << std::endl;
	std::cout << "max(h, i) = " << Fixed::max(h, i) << std::endl;

	// std::cout << "\n--- Division by Zero (optional test) ---\n";
	// Fixed zero;
	// // Uncomment below to test crash behavior (acceptable by subject)
	// std::cout << "d / zero = " << (d / zero) << std::endl;
	return 0;
}
