/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:58:41 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:10:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : RawBits() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	RawBits = fixed.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->RawBits = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (RawBits);
}

void Fixed::setRawBits(int const raw) {
	RawBits = raw;
}
