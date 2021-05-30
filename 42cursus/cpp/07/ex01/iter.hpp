/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:31:29 by joopark           #+#    #+#             */
/*   Updated: 2021/05/30 19:11:32 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

//TODO: const 타입에 대해서도 처리가 가능하게 해야 하며 함수 형식에 대한 고민 필요
template <typename T>
void iter(T *a, int len, void(*func)(T)) {
	for (int i = 0; i < len; i++)
		func(a[i]);
}

template <typename T>
void iter(T *a, int len, void(*func)(const T)) {
	for (int i = 0; i < len; i++)
		func(a[i]);
}

#endif
