/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:08:33 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 00:33:01 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
#define PONY_H

#include <iostream>

class Pony {
	private:
		std::string Name;
		std::string Status;
		std::string Color;
		int Age;
	public:
		Pony(std::string name, int age, std::string color, std::string status);
		void greeting(void);
		void status(void);
		void changeStatus(std::string status);
};

#endif