/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:02:14 by joopark           #+#    #+#             */
/*   Updated: 2021/05/30 01:49:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() {
	data.reserve(0);
}

Span::Span(unsigned int N) {
	data.reserve(N);
}

Span::Span(const Span & span) {
	if (this != &span)
		*this = span;
}

Span & Span::operator=(const Span & span) {
	if (this != &span)
		this->data = span.data;
	return (*this);
}

Span::~Span() {}

bool Span::isMulti::operator() (int target, int i) const {
	return (target > i);
}

void Span::addNumber(int i) {
	std::vector<int>::iterator iter;

	if (data.capacity() == data.size())
		throw Span::SpanFullException();
	iter = std::find_if(data.begin(), data.end(), std::bind2nd(isMulti(), i));
	data.insert(iter, i);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (data.capacity() < static_cast<size_t>(end - begin))
		throw Span::NotEnoughElementsException();
	std::copy(begin, end, std::back_inserter(data));
	std::sort(data.begin(), data.end());
}

int Span::shortestSpan(void) {
	std::vector<int>::iterator iter_prev;
	std::vector<int>::iterator iter_next;
	int min = INT_MAX;
	if (data.size() < 2)
		throw Span::NotEnoughElementsException();
	iter_prev = data.begin();
	iter_next = iter_prev + 1;
	while (iter_next != data.end()) {
		if (static_cast<int>(*iter_next - *iter_prev) < min)
			min = static_cast<int>(*iter_next - *iter_prev);
		if (min == 0)
			break ;
		iter_prev++;
		iter_next++;
	}
	return (min);
}

int Span::longestSpan(void) {
	std::vector<int>::iterator end;
	if (data.size() < 2)
		throw Span::NotEnoughElementsException();
	return (static_cast<int>(data.back() - data.front()));
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is Full";
}

const char* Span::NotEnoughElementsException::what() const throw() {
	return "Not Enough Elements in Span";
}
