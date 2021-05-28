/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:30:10 by joopark           #+#    #+#             */
/*   Updated: 2021/05/28 18:27:07 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <ctime>

#pragma pack(1)
struct Data {
	std::string * stringOne;
	int integer;
	std::string * stringTwo;
};
#pragma pack(0)

void * serialize(void);
Data * deserialize(void * raw);

#endif
