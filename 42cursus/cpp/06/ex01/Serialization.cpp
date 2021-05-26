/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:29:58 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 12:45:16 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

void * serialize(void) {
	char tmp[30];
	Data * target = new Data;

	srand(time(NULL));
	for (int i = 0; i < 30; i++) {
		tmp[i] = char(rand() % ('Z' - 'A' + 1) + 'A');
	}
	target->stringOne = new std::string(tmp, 10);
	target->integer = rand();
	target->stringTwo = new std::string(tmp + 10, 20);
	return (reinterpret_cast<void *>(target));
}

Data * deserialize(void * raw) {
	return (reinterpret_cast<Data *>(raw));
}