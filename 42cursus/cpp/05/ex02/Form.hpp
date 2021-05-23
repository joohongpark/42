/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:38 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 15:16:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		bool _signed;
		const std::string _name;
		const int _gradeForSign;
		const int _gradeForExecute;
	public:
		Form(std::string name, int gradeForSign, int gradeForExecute);
		Form(const Form & form);
		Form & operator=(const Form & form);
		~Form();
		bool getSigned(void) const;
		std::string getName(void) const;
		int getGradeForSign(void) const;
		int getGradeForExecute(void) const;
		void beSigned(Bureaucrat & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const;
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form & form);

#endif
