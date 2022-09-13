/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:21:32 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 14:01:50 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class Contact {

	public:

		Contact(void);
		~Contact(void);

		std::string	getFirstName(void) const;
		void		setFirstName(std::string str);
		std::string	getLastName(void) const;
		void		setLastName(std::string str);
		std::string	getNickName(void) const;
		void		setNickName(std::string str);
		std::string	getSecret(void) const;
		void		setSecret(std::string str);
		std::string	getPhoneNumber(void) const;
		void		setPhoneNumber(std::string str);

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string _secret;
		std::string	_phone_number;
};

#endif
