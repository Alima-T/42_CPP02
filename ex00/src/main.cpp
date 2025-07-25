/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:26:47 by aokhapki          #+#    #+#             */
/*   Updated: 2025/07/25 18:16:12 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main(void) 
{
	Fixed a;			// Calls default constructor
	Fixed b(a);			// Calls copy constructor
	Fixed c;			// Calls default constructor again

	c = b;				// Calls copy assignment operator

	std::cout << a.getRawBits() << std::endl;	// Shows raw bits of 'a'
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;			// Destructors will be called for a, b, and c automatically
}
