/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:15:51 by joopark           #+#    #+#             */
/*   Updated: 2021/05/28 18:25:36 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(const char* str) {
	number = atof(str);
}

Convert::Convert(const Convert & convert) {
	if (this != &convert)
		*this = convert;
}

Convert & Convert::operator=(const Convert & convert) {
	if (this != &convert)
		this->number = convert.number;
	return (*this);
}

Convert::~Convert() {}

bool Convert::charAvailable(void) {
	if (isnan<double>(number) == true
		|| isinf<double>(number) == true
		|| static_cast<double>(std::numeric_limits<char>::max()) < number
		|| static_cast<double>(std::numeric_limits<char>::min()) > number)
		return (false);
	return (true);
}

bool Convert::intAvailable(void) {
	if (isnan<double>(number) == true
		|| isinf<double>(number) == true
		|| static_cast<double>(std::numeric_limits<int>::max()) < number
		|| static_cast<double>(std::numeric_limits<int>::min()) > number)
		return (false);
	return (true);
}

bool Convert::floatAvailable(void) {
	float tmp;
	if (isnan<double>(number) == false && isinf<double>(number) == false) {
		tmp = static_cast<float>(number);
		if (static_cast<double>(tmp) - number > 0.1 || static_cast<double>(tmp) - number < -0.1)
			return (false);
	}
	return (true);
}

bool Convert::doubleAvailable(void) {
	return (true);
}

char Convert::getChar(void) {
	return (static_cast<char>(number));
}

int Convert::getInt(void) {
	return (static_cast<int>(number));
}

float Convert::getFloat(void) {
	return (static_cast<float>(number));
}

double Convert::getDouble(void) {
	return (number);
}

