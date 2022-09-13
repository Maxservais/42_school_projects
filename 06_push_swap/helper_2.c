/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:19:38 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 14:33:48 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_elemts(t_list **lst)
{
	int		i;
	t_list	*trav;

	i = 0;
	trav = *lst;
	while (trav != NULL)
	{
		i++;
		trav = trav->next;
	}
	return (i);
}

int	find_index_first(t_data *data, t_list **lst_a, int j)
{
	int		index;
	t_list	*trav;

	index = 0;
	trav = *lst_a;
	while (trav != NULL)
	{
		if (trav->content <= data->pivots[j])
			break ;
		index++;
		trav = trav->next;
	}
	return (index);
}

int	find_index_last(t_data *data, t_list **lst_a, int j)
{
	int		nbr;
	int		index;
	t_list	*trav;

	trav = *lst_a;
	while (trav != NULL)
	{
		if (trav->content <= data->pivots[j])
			nbr = trav->content;
		trav = trav->next;
	}
	index = 0;
	trav = *lst_a;
	while (trav != NULL)
	{
		if (trav->content == nbr)
			break ;
		index++;
		trav = trav->next;
	}
	return (index);
}

int	find_index(t_data *data, t_list **lst_a, int j)
{
	int		nbr_1_index;
	int		nbr_2_index;
	int		final_index;

	nbr_1_index = find_index_first(data, lst_a, j);
	nbr_2_index = find_index_last(data, lst_a, j);
	if (nbr_1_index <= data->nbr_elemts - nbr_2_index)
		final_index = nbr_1_index;
	else
		final_index = nbr_2_index;
	return (final_index);
}
