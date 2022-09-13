/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:17:01 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 15:40:36 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(char *instruction)
{
	write(STDOUT_FILENO, instruction, ft_strlen(instruction));
	write(STDOUT_FILENO, "\n", 1);
}

int	find_min(t_list **lst)
{
	int		min;
	t_list	*tmp;

	min = INT_MAX;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_list **lst)
{
	int		max;
	t_list	*tmp;

	max = INT_MIN;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

void	rotate_efficiently(t_list **lst, int nbr_elemts, int index, char *instr)
{
	if (index < (nbr_elemts / 2) - 1)
	{
		while (index > 0)
		{
			rotate(lst, instr);
			index--;
		}
	}
	else
	{
		if (!ft_strncmp(instr, RA, sizeof(RA)))
			instr = RRA;
		else
			instr = RRB;
		while (index < nbr_elemts)
		{
			rev_rotate(lst, instr);
			index++;
		}
	}	
}

void	send_top(t_list **lst, int nbr, int nbr_elemts, char *instr)
{
	int		i;
	t_list	*trav;

	i = 0;
	trav = *lst;
	while (trav->content != nbr && trav != NULL)
	{
		trav = trav->next;
		i++;
	}
	rotate_efficiently(lst, nbr_elemts, i, instr);
}
