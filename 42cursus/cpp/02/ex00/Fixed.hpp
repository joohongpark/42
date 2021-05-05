/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:58:39 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:11:03 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		int RawBits;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator= (const Fixed& fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
