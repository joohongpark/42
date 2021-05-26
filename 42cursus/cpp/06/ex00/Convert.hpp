/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:15:14 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 00:33:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdlib>
#include <cmath>
#include <limits>

class Convert {
	private:
		double number;
	public:
		Convert(const char* str);
		Convert(const Convert & convert);
		Convert & operator=(const Convert & convert);
		~Convert();
		bool charAvailable(void);
		bool intAvailable(void);
		bool floatAvailable(void);
		bool doubleAvailable(void);
		char getChar(void);
		int getInt(void);
		float getFloat(void);
		double getDouble(void);
};

#endif
