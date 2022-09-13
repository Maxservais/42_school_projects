/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:23:52 by mservais          #+#    #+#             */
/*   Updated: 2021/11/02 10:25:44 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	swap_top(t_list **lst, char *instruction)
{
	if (*lst && (*lst)->next)
	{
		swap(&((*lst)->content), &((*lst)->next->content));
		print_instruction(instruction);
	}
}

void	push_top(t_list **lst_1, t_list **lst_2, char *instruction)
{
	t_list	*tmp;

	if (*lst_1 == NULL)
		return ;
	tmp = *lst_1;
	*lst_1 = (*lst_1)->next;
	if (*lst_2 == NULL)
	{
		*lst_2 = tmp;
		(*lst_2)->next = NULL;
	}
	else
	{
		tmp->next = *lst_2;
		*lst_2 = tmp;
	}
	print_instruction(instruction);
}

void	rotate(t_list **lst, char *instruction)
{
	t_list	*tmp;
	t_list	*trav;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	trav = *lst;
	while (trav->next != NULL)
		trav = trav->next;
	trav->next = tmp;
	tmp->next = NULL;
	print_instruction(instruction);
}

void	rev_rotate(t_list **lst, char *instruction)
{
	t_list	*tmp;
	t_list	*trav;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	trav = *lst;
	while (trav->next->next != NULL)
		trav = trav->next;
	tmp = trav->next;
	trav->next = NULL;
	tmp->next = (*lst);
	*lst = tmp;
	print_instruction(instruction);
}
