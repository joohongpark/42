/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:31:29 by joopark           #+#    #+#             */
/*   Updated: 2021/05/31 00:31:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *a, size_t len, void(*func)(T)) {
	for (size_t i = 0; i < len; i++)
		func(a[i]);
}

template <typename T>
void iter(T *a, size_t len, void(*func)(T &)) {
	for (size_t i = 0; i < len; i++)
		func(a[i]);
}

template <typename T>
void iter(T *a, size_t len, void(*func)(const T &)) {
	for (size_t i = 0; i < len; i++)
		func(a[i]);
}

#endif
