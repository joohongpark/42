/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:55:01 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:46:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string str("HI THIS IS BRAIN");

	std::string *ref_pointer = &str;
	std::string& str_reference = str;
	std::cout << *ref_pointer << std::endl;
	std::cout << str_reference << std::endl;
	return (0);
}
