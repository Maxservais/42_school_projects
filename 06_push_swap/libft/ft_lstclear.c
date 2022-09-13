/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:56:15 by mservais          #+#    #+#             */
/*   Updated: 2021/10/08 17:53:50 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*trav;

	if (!lst || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		trav = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(trav, del);
	}
	*lst = NULL;
}
