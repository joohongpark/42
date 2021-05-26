/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:29:52 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 12:51:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void) {
	void * raw;
	Data * data;

	raw = serialize();
	std::cout << "[RAW DATA SIZE : " << sizeof(Data) << "]" << std::endl;
	data = deserialize(raw);

	std::cout << *(data->stringOne) << std::endl;
	std::cout << data->integer << std::endl;
	std::cout << *(data->stringTwo) << std::endl;

	delete data->stringOne;
	delete data->stringTwo;
	delete data;
	return (0);
}
