/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:49:05 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 21:33:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & robotomyrequestform) :
	Form(robotomyrequestform) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & robotomyrequestform) {
	if (this != &robotomyrequestform)
		this->Form::operator=(robotomyrequestform);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		Form::execute(executor);
		std::cout << "[Drilling Sounds] Drill....Drill....Drill........" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << "The operation was successful." << std::endl;
		else
			std::cout << "The operation failed." << std::endl;
	} catch (const std::exception & e) {
		std::cout << "Exception : " << e.what() << " at " << this->getName() << std::endl;
	}
}
