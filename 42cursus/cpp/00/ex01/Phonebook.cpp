/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:55:15 by joopark           #+#    #+#             */
/*   Updated: 2021/04/27 22:26:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
	index = 0;
	overwrite = 0;
}

void Phonebook::add(void) {
	std::string tmp;

	std::cout << "type 'first name'" << std::endl;
	std::cin >> tmp;
	people[index].setFirstName(tmp);
	std::cout << "type 'last name'" << std::endl;
	std::cin >> tmp;
	people[index].setLastName(tmp);
	std::cout << "type 'nickname'" << std::endl;
	std::cin >> tmp;
	people[index].setNickName(tmp);
	std::cout << "type 'login'" << std::endl;
	std::cin >> tmp;
	people[index].setLogin(tmp);
	std::cout << "type 'postal address'" << std::endl;
	std::cin >> tmp;
	people[index].setPostalAddress(tmp);
	std::cout << "type 'email address'" << std::endl;
	std::cin >> tmp;
	people[index].setEmailAddress(tmp);
	std::cout << "type 'phone number'" << std::endl;
	std::cin >> tmp;
	people[index].setPhoneNumber(tmp);
	std::cout << "type 'birthday date'" << std::endl;
	std::cin >> tmp;
	people[index].setBirthdayDate(tmp);
	std::cout << "type 'favorite meal'" << std::endl;
	std::cin >> tmp;
	people[index].setFavoriteMeal(tmp);
	std::cout << "type 'underwear color'" << std::endl;
	std::cin >> tmp;
	people[index].setUnderwearColor(tmp);
	std::cout << "type 'darkest secret'" << std::endl;
	std::cin >> tmp;
	people[index].setDarkestSecret(tmp);
	index++;
	if (index == 8) {
		index = 0;
		overwrite = 1;
	}
}

void Phonebook::printcol(int i) {
	std::string tmp;

	std::cout << '|';
	std::cout << std::setw(10) << std::setfill(' ') << (i + 1) << '|';
	tmp = people[i].getFirstName();
	tmp = tmp.length() > 9 ? tmp.substr(0, 9) + "." : tmp;
	std::cout << std::setw(10) << std::setfill(' ') << tmp << '|';
	tmp = people[i].getLastName();
	tmp = tmp.length() > 9 ? tmp.substr(0, 9) + "." : tmp;
	std::cout << std::setw(10) << std::setfill(' ') << tmp << '|';
	tmp = people[i].getNickName();
	tmp = tmp.length() > 9 ? tmp.substr(0, 9) + "." : tmp;
	std::cout << std::setw(10) << std::setfill(' ') << tmp << '|';
	std::cout << std::endl;
}

void Phonebook::printall(void) {
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------+----------+----------+----------|" << std::endl;
	for (int i = 0; i < (overwrite ? 8 : index); i++)
		printcol(i);
	std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::printpersonaldata(int i) {
	std::cout << "FirstName : " << people[i].getFirstName() << std::endl;
	std::cout << "LastName : " << people[i].getLastName() << std::endl;
	std::cout << "NickName : " << people[i].getNickName() << std::endl;
	std::cout << "Login : " << people[i].getLogin() << std::endl;
	std::cout << "PostalAddress : " << people[i].getPostalAddress() << std::endl;
	std::cout << "EmailAddress : " << people[i].getEmailAddress() << std::endl;
	std::cout << "PhoneNumber : " << people[i].getPhoneNumber() << std::endl;
	std::cout << "BirthdayDate : " << people[i].getBirthdayDate() << std::endl;
	std::cout << "FavoriteMeal : " << people[i].getFavoriteMeal() << std::endl;
	std::cout << "UnderwearColor : " << people[i].getUnderwearColor() << std::endl;
	std::cout << "DarkestSecret : " << people[i].getDarkestSecret() << std::endl;
}

void Phonebook::search(void) {
	int	input;

	printall();
	while (1) {
		std::cout << "type index of the desired entry" << std::endl;
		std::cout << "> ";
		std::cin >> input;
		if (std::cin.fail() || input < 1 || input > (overwrite ? 8 : index)) {
			std::cout << "wrong index" << std::endl;
			if (std::cin.fail())
				std::cin.clear();
			break ;
		} else {
			printpersonaldata(input - 1);
		}
	}
}

void Phonebook::run(void) {
	std::string tmp;

	std::cout << "joopark's Awesome PhoneBook!!!!!" << std::endl;
	while (1) {
		std::cout << "phonebook> ";
		std::cin >> tmp;
		if (tmp.compare("ADD") == 0) {
			if (overwrite == 1)
				std::cout << "[warning] Overwrite previously created information." << std::endl;
			add();
		} else if (tmp.compare("SEARCH") == 0) {
			if (overwrite == 0 && index == 0)
				std::cout << "[alert] phonebook is empty!" << std::endl;
			else
				search();
		} else if (std::cin.eof() || tmp.compare("EXIT") == 0) {
			std::cout << "bye" << std::endl;
			break ;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
}
