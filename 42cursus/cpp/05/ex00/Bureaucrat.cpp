/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:10:52 by joopark           #+#    #+#             */
/*   Updated: 2021/05/22 13:51:00 by joopark          ###   ########.fr       */
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
