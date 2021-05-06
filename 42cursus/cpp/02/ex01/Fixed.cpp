/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:58:41 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:11:32 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : RawBits() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	RawBits = i << fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	RawBits = int(roundf(f * float(1 << fractional_bits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
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
	return (RawBits);
}

void Fixed::setRawBits(int const raw) {
	RawBits = raw;
}

float Fixed::toFloat(void) const {
	return (float(RawBits) / float(1 << fractional_bits));
}

int Fixed::toInt(void) const {
	return (RawBits >> fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
