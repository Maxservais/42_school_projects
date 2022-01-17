/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:50 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 15:30:01 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_data *data, t_list **lst1, t_list **lst2)
{
	int		i;
	int		min;

	i = 0;
	min = find_min(lst1);
	while (i < data->nbr_elemts)
	{
		while ((*lst1)->content != min)
			rev_rotate(lst1, RRA);
		push_top(lst1, lst2, PB);
		min = find_min(lst1);
		i++;
	}
	i = 0;
	while (i < data->nbr_elemts)
	{
		push_top(lst2, lst1, PA);
		i++;
	}
}

void	sort_b(t_data *data, t_list **lst_b, t_list **lst_a)
{
	int	max_nbr;
	int	nbr;

	nbr = data->nbr_elemts;
	while (nbr > 0)
	{
		max_nbr = find_max(lst_b);
		send_top(lst_b, max_nbr, nbr, RB);
		push_top(lst_b, lst_a, PA);
		nbr--;
	}
}

void	organize_stack_b(t_list **lst_b)
{
	int	max;

	if (!*lst_b)
		return ;
	max = find_max(lst_b);
	send_top(lst_b, max, nbr_elemts(lst_b), RB);
}

void	search_chunk(t_data *data, t_list **lst_a, t_list **lst_b, int j)
{
	int		i;
	int		final_index;
	t_list	*trav;

	i = 0;
	while (i < (data->chunk_size))
	{
		if (!*lst_a)
			break ;
		final_index = find_index(data, lst_a, j);
		trav = *lst_a;
		while (final_index > 0 && trav != NULL)
		{
			trav = trav->next;
			final_index--;
		}
		send_top(lst_a, trav->content, nbr_elemts(lst_a), RA);
		organize_stack_b(lst_b);
		push_top(lst_a, lst_b, PB);
		i++;
	}
}

void	sort_large(t_data *data, t_list **lst_a, t_list **lst_b)
{
	int		j;

	j = 0;
	while (j < data->chunks)
	{
		search_chunk(data, lst_a, lst_b, j);
		j++;
	}
	sort_b(data, lst_b, lst_a);
}
