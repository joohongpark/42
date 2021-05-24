/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:49:11 by joopark           #+#    #+#             */
/*   Updated: 2021/05/23 21:33:02 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & shrubberycreationform) :
	Form(shrubberycreationform) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & shrubberycreationform) {
	if (this != &shrubberycreationform)
		this->Form::operator=(shrubberycreationform);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		Form::execute(executor);
		std::ofstream file(this->getName() + "_shrubbery");
		if (file.is_open()) {
			file << "                      ___" << '\n';
			file << "                _,-'''   ''''`--." << '\n';
			file << "             ,-'          __,,-- \\" << '\n';
			file << "           ,'    __,--''''dF      )" << '\n';
			file << "          /   .-'Hb_,--''dF      /" << '\n';
			file << "        ,'       _Hb ___dF'-._,-'" << '\n';
			file << "      ,'      _,-''''   ''--..__" << '\n';
			file << "     (     ,-'                  `." << '\n';
			file << "      `._,'     _   _             ;" << '\n';
			file << "       ,'     ,' `-'Hb-.___..._,-'" << '\n';
			file << "       \\    ,''Hb.-'HH`-.dHF'" << '\n';
			file << "        `--'   'Hb  HH  dF'" << '\n';
			file << "                'Hb HH dF" << '\n';
			file << "                 'HbHHdF" << '\n';
			file << "                  |HHHF" << '\n';
			file << "                  |HHH|" << '\n';
			file << "                  |HHH|" << '\n';
			file << "                  |HHH|" << '\n';
			file << "                  |HHH|" << '\n';
			file << "                  dHHHb" << '\n';
			file << "                .dFd|bHb.               o" << '\n';
			file << "      o       .dHFdH|HbTHb.          o /" << '\n';
			file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << '\n';
			file << "##########################################" << '\n';
			file.close();
		}
	} catch (const std::exception & e) {
		std::cout << "Exception : " << e.what() << " at " << this->getName() << std::endl;
	}
}
