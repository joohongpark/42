/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:40:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/30 16:11:34 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T, std::deque<T> > {
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack() : std::stack<T, std::deque<T> >() {};
		MutantStack(const MutantStack & mutantstack) : std::stack<T, std::deque<T> >(mutantstack) {};
		MutantStack& operator=(const MutantStack & mutantstack) {
			return (std::stack<T, std::deque<T> >::operator=(mutantstack));
		}
		~MutantStack() {}
		iterator begin(void) {
			return (this->c.begin());
		}
		iterator end(void) {
			return (this->c.end());
		}
};

#endif
