/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:14 by joopark           #+#    #+#             */
/*   Updated: 2021/05/14 23:06:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
	private:
	public:
		Peon(std::string name);
		Peon(const Peon& peon);
		Peon& operator=(const Peon& peon);
		~Peon();
		void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &out, const Peon &peon);

#endif
