/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:49:08 by joopark           #+#    #+#             */
/*   Updated: 2021/05/24 11:17:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <ctime>

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm & robotomyrequestform);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & robotomyrequestform);
		virtual ~RobotomyRequestForm();
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
