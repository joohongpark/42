/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:20:50 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 00:33:16 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <cctype>

class Print {
	public:
		Print();
		Print(const Print & print);
		Print & operator=(const Print & print);
		~Print();
		void printNumber(bool possible, char c);
		void printNumber(bool possible, int i);
		void printNumber(bool possible, float f);
		void printNumber(bool possible, double d);
};

#endif
