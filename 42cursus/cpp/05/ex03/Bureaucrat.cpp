/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:52 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 21:33:51 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat & bureaucrat) : _name(bureaucrat._name) {
	if (this != &bureaucrat)
		*this = bureaucrat;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & bureaucrat) {
	if (this != &bureaucrat) {
		this->_grade = bureaucrat._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const {
	return (_name);
}

int Bureaucrat::getGrade(void) const {
	return (_grade);
}

void Bureaucrat::gradeInc(void) {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::gradeDec(void) {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form & form) {
	if (form.getSigned()) {
		std::cout << "<";
		std::cout << _name;
		std::cout << "> has already received an autograph from <";
		std::cout << form.getName();
		std::cout << ">";
		std::cout << std::endl;
	} else {
		try {
			form.beSigned(*this);
			std::cout << "<";
			std::cout << _name;
			std::cout << "> signs <";
			std::cout << form.getName();
			std::cout << ">";
			std::cout << std::endl;
		} catch (const std::exception& e) {
			std::cout << "<";
			std::cout << _name;
			std::cout << "> cannot sign <";
			std::cout << form.getName();
			std::cout << "> because <";
			std::cout << e.what();
			std::cout << ">";
			std::cout << std::endl;
		}
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
	} catch(const std::exception& e) {
		std::cout << "Exception : " << e.what() << " at " << this->getName() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat & bureaucrat) {
	out << "<";
	out << bureaucrat.getName();
	out << ">, bureaucrat grade <";
	out << bureaucrat.getGrade();
	out << ">";
	out << std::endl;
	return (out);
}
