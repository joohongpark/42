/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:41:37 by joopark           #+#    #+#             */
/*   Updated: 2021/05/24 01:13:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern & intern);
		Intern & operator=(const Intern & intern);
		~Intern();
		Form* makeForm(std::string name, std::string target);
};

Form* genPresidentialPardonForm(std::string const & target);
Form* genRobotomyRequestForm(std::string const & target);
Form* genShrubberyCreationForm(std::string const & target);

#endif
