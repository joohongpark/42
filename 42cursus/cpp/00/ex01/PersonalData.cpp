/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PersonalData.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:37:42 by joopark           #+#    #+#             */
/*   Updated: 2021/04/25 23:48:13 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PersonalData.hpp"

void PersonalData::setFirstName(std::string str) {
	FirstName = str;
}

std::string PersonalData::getFirstName() {
	return (FirstName);
}

void PersonalData::setLastName(std::string str) {
	LastName = str;
}

std::string PersonalData::getLastName() {
	return (LastName);
}

void PersonalData::setNickName(std::string str) {
	NickName = str;
}

std::string PersonalData::getNickName() {
	return (NickName);
}

void PersonalData::setLogin(std::string str) {
	Login = str;
}

std::string PersonalData::getLogin() {
	return (Login);
}

void PersonalData::setPostalAddress(std::string str) {
	PostalAddress = str;
}

std::string PersonalData::getPostalAddress() {
	return (PostalAddress);
}

void PersonalData::setEmailAddress(std::string str) {
	EmailAddress = str;
}

std::string PersonalData::getEmailAddress() {
	return (EmailAddress);
}

void PersonalData::setPhoneNumber(std::string str) {
	PhoneNumber = str;
}

std::string PersonalData::getPhoneNumber() {
	return (PhoneNumber);
}

void PersonalData::setBirthdayDate(std::string str) {
	BirthdayDate = str;
}

std::string PersonalData::getBirthdayDate() {
	return (BirthdayDate);
}

void PersonalData::setFavoriteMeal(std::string str) {
	FavoriteMeal = str;
}

std::string PersonalData::getFavoriteMeal() {
	return (FavoriteMeal);
}

void PersonalData::setUnderwearColor(std::string str) {
	UnderwearColor = str;
}

std::string PersonalData::getUnderwearColor() {
	return (UnderwearColor);
}

void PersonalData::setDarkestSecret(std::string str) {
	DarkestSecret = str;
}

std::string PersonalData::getDarkestSecret() {
	return (DarkestSecret);
}
