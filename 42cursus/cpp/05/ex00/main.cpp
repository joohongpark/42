/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:57 by joopark           #+#    #+#             */
/*   Updated: 2021/05/22 13:09:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat a("joopark", -1);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	try {
		Bureaucrat b("joopark", 151);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	try {
		Bureaucrat c("joopark", 1);
		std::cout << c;
		c.gradeInc();
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}

	try {
		Bureaucrat d("joopark", 150);
		std::cout << d;
		d.gradeDec();
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	return (0);
}