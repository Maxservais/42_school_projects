/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:21:13 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 12:54:38 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **lst)
{
	t_list	*trav;

	if (!(*lst))
		return ;
	trav = (*lst)->next;
	while (trav != NULL)
	{
		free(*lst);
		*lst = trav;
		trav = trav->next;
	}
	free(*lst);
	*lst = NULL;
}

void	free_all(t_data *data, t_list **lst_a, t_list **lst_b)
{
	free_stack(lst_a);
	free_stack(lst_b);
	if (data->nbr_elemts > 20)
		free(data->pivots);
}
