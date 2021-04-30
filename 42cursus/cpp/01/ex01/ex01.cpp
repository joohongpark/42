/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:41:26 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 01:02:28 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void		memoryLeak()
{
	std::string*	panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete panther;
	panther = NULL;
}
