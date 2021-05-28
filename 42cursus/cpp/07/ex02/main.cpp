/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:58:05 by joopark           #+#    #+#             */
/*   Updated: 2021/05/28 17:29:54 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	Array<int> arrInt(10);
	Array<std::string> arrStr(3);
	Array<std::string> arrStrAssign;

	for (unsigned int i = 0; i < 10; i++)
		arrInt[i] = i * 10;
	arrStr[0] = "hello";
	arrStr[1] = "Array";
	arrStr[2] = "Templete";

	std::cout << "length of arrInt : " << arrInt.size() << std::endl;
	std::cout << "length of arrStr : " << arrStr.size() << std::endl;

	std::cout << "arrInt[0] : " << arrInt[0] << std::endl;
	std::cout << "arrStr[0] : " << arrStr[0] << std::endl;

	arrStrAssign = arrStr;
	Array<std::string> arrStrCopy(arrStr);

	try {
		for (unsigned int i = 0; i < 10; i++)
			std::cout << "arrStrAssign[" << i << "] : " << arrStrAssign[i] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		for (unsigned int i = 0; i < 10; i++)
			std::cout << "arrStrCopy[" << i << "] : " << arrStrCopy[i] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	
	return (0);
}
