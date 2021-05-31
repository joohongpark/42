/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:40:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/31 01:04:49 by joopark          ###   ########.fr       */
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
		const_iterator begin(void) const {
			return (this->c.begin());
		}
		iterator end(void) {
			return (this->c.end());
		}
		const_iterator end(void) const {
			return (this->c.end());
		}
		reverse_iterator rbegin(void) {
			return (this->c.begin());
		}
		const_reverse_iterator rbegin(void) const {
			return (this->c.begin());
		}
		reverse_iterator rend(void) {
			return (this->c.end());
		}
		const_reverse_iterator rend(void) const {
			return (this->c.end());
		}
};

#endif
