/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:19 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 15:22:36 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) : _index(0){
	return ;
}

Phonebook::~Phonebook(void){
	return ;
}

Contact	Phonebook::getContact(int i) const {
	return this->_contactList[i];
}

void Phonebook::setContact(Contact contact) {
	this->_contactList[this->_index] = contact;
	if (Phonebook::_nbInst < 8)
		Phonebook::_nbInst += 1;
	else
		std::cout << "Cannot add more than 8 contacts, sorry!" << std::endl;
	this->_index = (this->_index + 1) % 8;
	return ;
}

int	Phonebook::getNbInstance(void) {
	return Phonebook::_nbInst;
}

int	Phonebook::_nbInst = 0;
