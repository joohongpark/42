/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:48:59 by joopark           #+#    #+#             */
/*   Updated: 2021/05/24 11:17:04 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm & presidentialpardonform);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & presidentialpardonform);
		virtual ~PresidentialPardonForm();
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
