/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:02:17 by joopark           #+#    #+#             */
/*   Updated: 2021/05/30 01:41:49 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <functional>

class Span {
	private:
		std::vector<int> data;
		struct isMulti : public std::binary_function<int, int, bool> {
			bool operator() (int target, int i) const;
		};
	public:
		Span();
		Span(unsigned int N);
		Span(const Span & span);
		Span & operator=(const Span & span);
		~Span();
		void addNumber(int i);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
		class SpanFullException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughElementsException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif
