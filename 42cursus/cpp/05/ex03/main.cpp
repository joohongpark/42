/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:57 by joopark           #+#    #+#             */
/*   Updated: 2021/05/24 11:15:50 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat signer("joopark", 15);
	Bureaucrat executor("polarbear", 10);
	Intern  someRandomIntern;
	Form* a = someRandomIntern.makeForm("robotomy request", "Robot");
	Form* b = someRandomIntern.makeForm("presidential pardon", "killer");
	Form* c = someRandomIntern.makeForm("shrubbery creation", "Home");

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