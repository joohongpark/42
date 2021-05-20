/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:19 by joopark           #+#    #+#             */
/*   Updated: 2021/05/14 22:39:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	private:
		std::string _name;
		std::string _title;
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(const Sorcerer& sorcerer);
		Sorcerer& operator=(const Sorcerer& sorcerer);
		~Sorcerer();
		std::string getName(void) const;
		std::string getTitle(void) const;
		void polymorph(Victim const& victim) const;
		void polymorph(Peon const& peon) const;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);

#endif
