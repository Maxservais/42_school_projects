/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:21:32 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 13:57:28 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

	public:

		Phonebook(void);
		~Phonebook(void);

		Contact		getContact(int i) const;
		void		setContact(Contact contact);
		static int	getNbInstance(void);

	private:

		int			_index;
		Contact		_contactList[8];
		static int	_nbInst;
};

#endif
