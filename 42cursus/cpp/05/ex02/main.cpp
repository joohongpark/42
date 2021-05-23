/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:57 by joopark           #+#    #+#             */
/*   Updated: 2021/05/22 17:13:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void form_odd_value_test() {
	try {
		Form a("joopark", -20, 30);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	try {
		Form b("joopark", 1000, 30);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	try {
		Form b("joopark", 10, -30);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
	try {
		Form b("joopark", 10, 200);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
}

void form_sign_test() {
	try {
		Form a("Checker", 30, 120);
		Bureaucrat b("joopark", 31);
		b.signForm(a);
		b.gradeInc();
		b.signForm(a);
	} catch (const std::exception & e) {
		std::cerr << "Exception : " << e.what() << '\n';
	}
}

int main(void) {
	form_odd_value_test();
	form_sign_test();
	return (0);
}