/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 02:00:05 by joopark           #+#    #+#             */
/*   Updated: 2021/05/29 20:21:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <template <typename, typename> class T>
typename T<int, std::allocator<int> >::iterator easyfind(T<int, std::allocator<int> > & t, int i) {
	typename T<int, std::allocator<int> >::iterator iter;
	iter = std::find(t.begin(), t.end(), i);
	if (iter == t.end())
		throw ("not found");
	return (iter);
}

#endif
