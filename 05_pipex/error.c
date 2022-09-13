/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:58:04 by mservais          #+#    #+#             */
/*   Updated: 2021/10/04 16:59:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_err_return(char *error)
{
	write(1, error, ft_strlen(error));
	return (EXIT_FAILURE);
}

int	ft_perror(void)
{
	perror("Error");
	return (EXIT_FAILURE);
}
