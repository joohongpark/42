/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/15 09:25:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim {
	protected:
		std::string _name;
	public:
		Victim(std::string name);
		Victim(const Victim& victim);
		Victim& operator=(const Victim& victim);
		~Victim();
		std::string getName(void) const;
		void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif
