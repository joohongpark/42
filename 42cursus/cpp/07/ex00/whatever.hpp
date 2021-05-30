/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:19:29 by joopark           #+#    #+#             */
/*   Updated: 2021/05/31 00:26:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T & a, T & b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T & min(T & a, T & b) {
	return (a >= b ? b : a);
}

template <typename T>
T & max(T & a, T & b) {
	return (a <= b ? b : a);
}

#endif
