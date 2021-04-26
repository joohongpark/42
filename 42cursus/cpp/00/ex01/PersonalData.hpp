/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonalData.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:56:51 by joopark           #+#    #+#             */
/*   Updated: 2021/04/25 23:59:18 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONALDATA_H
# define PERSONALDATA_H

# include <iostream>

class PersonalData {
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string Login;
		std::string PostalAddress;
		std::string EmailAddress;
		std::string PhoneNumber;
		std::string BirthdayDate;
		std::string FavoriteMeal;
		std::string UnderwearColor;
		std::string DarkestSecret;
	public:
		void setFirstName(std::string str);
		std::string getFirstName();
		void setLastName(std::string str);
		std::string getLastName();
		void setNickName(std::string str);
		std::string getNickName();
		void setLogin(std::string str);
		std::string getLogin();
		void setPostalAddress(std::string str);
		std::string getPostalAddress();
		void setEmailAddress(std::string str);
		std::string getEmailAddress();
		void setPhoneNumber(std::string str);
		std::string getPhoneNumber();
		void setBirthdayDate(std::string str);
		std::string getBirthdayDate();
		void setFavoriteMeal(std::string str);
		std::string getFavoriteMeal();
		void setUnderwearColor(std::string str);
		std::string getUnderwearColor();
		void setDarkestSecret(std::string str);
		std::string getDarkestSecret();
};
#endif
