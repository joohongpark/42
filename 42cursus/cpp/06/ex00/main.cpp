/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:02:23 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 00:37:36 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "Print.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	Convert* converter;
	Print printer;
	if (argc != 2) {
		std::cerr << "[error] argument error!" << std::endl;
		return (-1);
	}
	converter = new Convert(argv[1]);
	printer.printNumber(converter->charAvailable(), converter->getChar());
	printer.printNumber(converter->intAvailable(), converter->getInt());
	printer.printNumber(converter->floatAvailable(), converter->getFloat());
	printer.printNumber(converter->doubleAvailable(), converter->getDouble());
	delete converter;
	return (0);
}
