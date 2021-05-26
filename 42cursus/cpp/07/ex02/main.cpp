/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:58:05 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 22:47:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	Array<int> arrInt(10);
	Array<std::string> arrStr(3);

	for (unsigned int i = 0; i < 10; i++)
		arrInt[i] = i * 10;
	arrStr[0] = "hello";
	arrStr[1] = "Array";
	arrStr[2] = "Templete";

	std::cout << "length of arrInt : " << arrInt.size() << std::endl;
	std::cout << "length of arrStr : " << arrStr.size() << std::endl;

	std::cout << "arrInt[0] : " << arrInt[0] << std::endl;
	std::cout << "arrStr[0] : " << arrStr[0] << std::endl;

	try {
		std::cout << "arrStr[0] : " << arrStr[10] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
