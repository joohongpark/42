/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:35:53 by joopark           #+#    #+#             */
/*   Updated: 2021/04/24 15:35:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main (int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout << static_cast<char>(argv[i][j] - ('a' - 'A'));
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}