/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:08:28 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:05:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap(void) {
	Pony *pony = new Pony("joopark", 12, "black", "sleeping");
	pony->greeting();
	pony->status();
	pony->changeStatus("running");
	pony->status();
	delete pony;
}

void ponyOnTheStack(void) {
	Pony pony("parkjoo", 21, "white", "running");
	pony.greeting();
	pony.status();
	pony.changeStatus("sleeping");
	pony.status();
}

int main (void) {
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
