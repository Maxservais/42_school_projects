/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:37:32 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 15:56:10 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	sort_stack(t_data *data, t_list **lst_a, t_list **lst_b)
{
	if (data->nbr_elemts == 2)
		swap_top(lst_a, SA);
	else if (data->nbr_elemts <= 3)
		sort_three(lst_a);
	else if (data->nbr_elemts <= 4)
		sort_four(lst_a, lst_b);
	else if (data->nbr_elemts <= 5)
		sort_five(lst_a, lst_b);
	else if (data->nbr_elemts <= 19)
		insertion_sort(data, lst_a, lst_b);
	else
		sort_large(data, lst_a, lst_b);
	free_all(data, lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_data	*data;

	lst_b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (find_errors(argv, argc))
		return (error_message());
	lst_a = initialize_stack(argc, argv);
	if (!lst_a)
		return (error_message());
	if (!stack_is_sorted(lst_a))
	{
		free_stack(&lst_a);
		return (EXIT_SUCCESS);
	}
	data = initialize_data(lst_a, argc - 1);
	if (!data)
	{
		free_stack(&lst_a);
		return (error_message());
	}
	sort_stack(data, &lst_a, &lst_b);
	return (EXIT_SUCCESS);
}
