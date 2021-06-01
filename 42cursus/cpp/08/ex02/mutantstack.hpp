/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:40:25 by joopark           #+#    #+#             */
/*   Updated: 2021/06/01 16:45:38 by joopark          ###   ########.fr       */
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
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		MutantStack() : std::stack<T, std::deque<T> >() {};
		MutantStack(const MutantStack & mutantstack) : std::stack<T, std::deque<T> >(mutantstack) {};
		MutantStack& operator=(const MutantStack & mutantstack) {
			return (std::stack<T, std::deque<T> >::operator=(mutantstack));
		}
		~MutantStack() {}
		iterator begin(void) {
			return (this->c.begin());
		}
		const_iterator cbegin(void) const {
			return (this->c.cbegin());
		}
		iterator end(void) {
			return (this->c.end());
		}
		const_iterator cend(void) const {
			return (this->c.cend());
		}
		reverse_iterator rbegin(void) {
			return (this->c.rbegin());
		}
		reverse_iterator rend(void) {
			return (this->c.rend());
		}
		const_reverse_iterator crbegin(void) const {
			return (this->c.crbegin());
		}
		const_reverse_iterator crend(void) const {
			return (this->c.crend());
		}
};

#endif
