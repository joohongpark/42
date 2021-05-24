/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:41:34 by joopark           #+#    #+#             */
/*   Updated: 2021/05/24 01:13:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & intern) {
	(void) intern;
}

Intern & Intern::operator=(const Intern & intern) {
	(void) intern;
	return (*this);
}

Intern::~Intern() {}

Form* Intern::makeForm(std::string name, std::string target) {
	static std::string classes[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	static Form* (*funcPtr[3])(std::string const & target) = {
		genRobotomyRequestForm,
		genPresidentialPardonForm,
		genShrubberyCreationForm
	};
	for (int i = 0; i < 3; i++) {
		if (classes[i] == name) {
			std::cout << "Intern creates <";
			std::cout << name;
			std::cout << ">";
			std::cout << std::endl;
			return (funcPtr[i](target));
		}
	}
	std::cout << "Intern can't generate ordered form." << std::endl;
	return (NULL);
}

Form* genPresidentialPardonForm(std::string const & target) {
	return (new PresidentialPardonForm(target));
}

Form* genRobotomyRequestForm(std::string const & target) {
	return (new RobotomyRequestForm(target));
}

Form* genShrubberyCreationForm(std::string const & target) {
	return (new ShrubberyCreationForm(target));
}
