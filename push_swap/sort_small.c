/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:22:56 by mservais          #+#    #+#             */
/*   Updated: 2021/11/04 19:41:54 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_entry(t_list **lst1, t_list **lst2)
{
	int		max;

	if ((*lst1)->content > (*lst2)->content)
		return ;
	max = find_max(lst1);
	if ((*lst2)->content > max)
		return ;
	while ((*lst1)->content < (*lst2)->content)
		rotate(lst1, RA);
}

static void	bring_min_top(t_list **lst)
{
	int		i;
	int		min;
	t_list	*trav;

	i = 0;
	min = find_min(lst);
	trav = *lst;
	while (trav->content != min && trav != NULL)
	{
		trav = trav->next;
		i++;
	}
	while (i > 3 && i < 5)
	{
		rev_rotate(lst, RRA);
		i++;
	}
	while (i <= 3 && i > 0)
	{
		rotate(lst, RA);
		i--;
	}
}

void	sort_three(t_list **lst)
{
	while (stack_is_sorted(*lst))
	{
		if ((*lst)->content < (*lst)->next->content
			&& (*lst)->content > (*lst)->next->next->content)
			rev_rotate(lst, RRA);
		else if ((*lst)->content > (*lst)->next->content
			&& (*lst)->content < (*lst)->next->next->content)
			swap_top(lst, SA);
		else if ((*lst)->content > (*lst)->next->content
			&& (*lst)->next->content > (*lst)->next->next->content)
			swap_top(lst, SA);
		else if ((*lst)->content > (*lst)->next->content
			&& (*lst)->next->content < (*lst)->next->next->content)
			rev_rotate(lst, RRA);
		else if ((*lst)->content < (*lst)->next->content
			&& (*lst)->next->content > (*lst)->next->next->content)
			rev_rotate(lst, RRA);
	}
}

void	sort_four(t_list **lst1, t_list **lst2)
{
	push_top(lst1, lst2, PB);
	sort_three(lst1);
	find_entry(lst1, lst2);
	push_top(lst2, lst1, PA);
	while (stack_is_sorted(*lst1))
		rotate(lst1, RA);
}

void	sort_five(t_list **lst1, t_list **lst2)
{	
	bring_min_top(lst1);
	push_top(lst1, lst2, PB);
	bring_min_top(lst1);
	push_top(lst1, lst2, PB);
	sort_three(lst1);
	push_top(lst2, lst1, PA);
	push_top(lst2, lst1, PA);
}
