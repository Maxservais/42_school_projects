/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:19 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 14:55:53 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

std::string	Contact::getFirstName(void) const {
	return this->_first_name;
}

void Contact::setFirstName(std::string str) {
	this->_first_name = str;
	return ;
}

std::string	Contact::getLastName(void) const {
	return this->_last_name;
}

void Contact::setLastName(std::string str) {
		this->_last_name = str;
	return ;
}

std::string	Contact::getNickName(void) const {
	return this->_nickname;
}

void Contact::setNickName(std::string str) {
		this->_nickname = str;
	return ;
}

std::string	Contact::getSecret(void) const {
	return this->_secret;
}

void Contact::setSecret(std::string str) {
		this->_secret = str;
	return ;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->_phone_number;
}

void Contact::setPhoneNumber(std::string str) {
		this->_phone_number = str;
	return ;
}
