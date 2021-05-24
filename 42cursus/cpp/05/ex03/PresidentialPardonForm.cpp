/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:49:03 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 21:33:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : Form(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & presidentialpardonform) :
	Form(presidentialpardonform) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & presidentialpardonform) {
	if (this != &presidentialpardonform)
		this->Form::operator=(presidentialpardonform);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		Form::execute(executor);
		std::cout << "<";
		std::cout << this->getName();
		std::cout << "> got an amnesty from Zafod Beeblebrox.";
		std::cout << std::endl;
	} catch (const std::exception & e) {
		std::cout << "Exception : " << e.what() << " at " << this->getName() << std::endl;
	}
}