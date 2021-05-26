/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:57 by joopark           #+#    #+#             */
/*   Updated: 2021/05/26 19:51:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat signer("joopark", 15);
	Bureaucrat executor("polarbear", 5);
	Form* a = new ShrubberyCreationForm("Home");
	Form* b = new RobotomyRequestForm("Robot");
	Form* c = new PresidentialPardonForm("killer");

	signer.signForm(*a);
	signer.signForm(*b);
	signer.signForm(*c);

	executor.executeForm(*a);
	executor.executeForm(*b);
	executor.executeForm(*c);

	delete a;
	delete b;
	delete c;

	return (0);
}