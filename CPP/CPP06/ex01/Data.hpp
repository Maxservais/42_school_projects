/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:39:50 by mservais          #+#    #+#             */
/*   Updated: 2022/03/07 17:43:40 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

typedef struct {
	int			age;
	std::string	name;
}			Data;

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);

#endif
