/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 15:17:26 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeForSign, int gradeForExecute)
	: _signed(false),
	_name(name),
	_gradeForSign(gradeForSign),
	_gradeForExecute(gradeForExecute)
	{
	if (_gradeForSign < 1 || _gradeForExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeForSign > 150 || _gradeForExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & form)
	: _name(form._name),
	_gradeForSign(form._gradeForSign),
	_gradeForExecute(form._gradeForExecute) {
		if (this != &form)
			*this = form;
}

Form & Form::operator=(const Form & form) {
	if (this != &form) {
		this->_signed = form._signed;
	}
	return (*this);
}

Form::~Form() {}

bool Form::getSigned(void) const {
	return (_signed);
}

std::string Form::getName(void) const {
	return (_name);
}

int Form::getGradeForSign(void) const {
	return (_gradeForSign);
}

int Form::getGradeForExecute(void) const {
	return (_gradeForExecute);
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <=_gradeForSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const {
	if (_signed == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > _gradeForSign)
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char* Form::NotSignedException::what() const throw() {
	return "Not Signed";
}

std::ostream &operator<<(std::ostream &out, const Form & form) {
	out << "<";
	out << form.getName();
	out << "> is signed : ";
	out << form.getSigned();
	out << ", Grade For Sign : ";
	out << form.getGradeForSign();
	out << ", Grade For Execute : ";
	out << form.getGradeForExecute();
	out << std::endl;
	return (out);
}
