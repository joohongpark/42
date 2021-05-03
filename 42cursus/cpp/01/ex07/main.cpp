/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:37:29 by joopark           #+#    #+#             */
/*   Updated: 2021/05/03 17:16:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	Replace replace;
	std::string filename;
	std::string s1;
	std::string s2;

	if (argc != 4) {
		std::cerr << "[error] argument error!" << std::endl;
		return (-1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!replace.open(filename)) {
		std::cerr << "[error] file open error!" << std::endl;
		return (-1);
	}
	replace.replace(s1, s2);
	if (!replace.save(filename + ".replace")) {
		std::cerr << "[error] file save error!" << std::endl;
		return (-1);
	}
	return (0);
}