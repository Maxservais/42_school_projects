/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:28:42 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 15:15:16 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	addContact(Phonebook *phonebook)
{
	Contact contact;
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contact.setNickName(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contact.setSecret(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	phonebook->setContact(contact);
}

std::string	truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	else
		return str;
}

void	printTable(Phonebook *phonebook)
{
	int		i;
	Contact	contact;

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index";
	std::cout << "|" << std::right << std::setw(10) << "First name";
	std::cout << "|" << std::right << std::setw(10) << "Last name";
	std::cout << "|" << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	i = 0;
	while (i < phonebook->getNbInstance())
	{
		contact = phonebook->getContact(i);
		std::cout << "|" << std::right << std::setw(10) << i + 1;
		std::cout << "|" << std::right << std::setw(10) << truncate(contact.getFirstName(), 10);
		std::cout << "|" << std::right << std::setw(10) << truncate(contact.getLastName(), 10);
		std::cout << "|" << std::right << std::setw(10) << truncate(contact.getNickName(), 10) << "|" << std::endl;
		i++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl << std::endl;
}

void	searchContact(Phonebook *phonebook)
{
	printTable(phonebook);
	if (phonebook->getNbInstance())
	{
		Contact	tmp_contact;
		int		input;

		std::cout << "Which contact's information would you like to see? Enter index: ";
		while (!(std::cin >> input) || input <= 0 || input > phonebook->getNbInstance())
		{
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cout << "Please enter a valid index: ";
		}
		tmp_contact = phonebook->getContact(input - 1);
		std::cout << "First name: " << tmp_contact.getFirstName() << std::endl;
		std::cout << "Last name: " << tmp_contact.getLastName() << std::endl;
		std::cout << "Nickname: " << tmp_contact.getNickName() << std::endl;
		std::cout << "Darkest secret: " << tmp_contact.getSecret() << std::endl;
		std::cout << "Phone number: " << tmp_contact.getPhoneNumber() << std::endl;
	}
	else
		std::cout << "EMPTY TABLE, SORRY. PRESS ENTER TO CONTINUE" << std::endl << std::endl;
	std::cin.ignore(10000, '\n');
}

int	main(void)
{
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Program's use: " << std::endl;
	std::cout << " -ADD: add a contact's details to the phonebook" << std::endl;
	std::cout << " -SEARCH: search for a specific contact in the phonebook" << std::endl;
	std::cout << " -EXIT: terminate the program" << std::endl;
	while (true)
	{
		std::cout << "Input a command (or enter 'EXIT' or press enter to quit): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			addContact(&phonebook);
		else if (input == "SEARCH")
			searchContact(&phonebook);
		else if (input == "EXIT" || input == "")
			break ;
	}
	return (0);
}
