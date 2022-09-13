/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:16:45 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 14:06:15 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize_stack(int nbr_elemts, char **argv)
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = ft_lstnew(ft_atoi(argv[1]));
	if (!head)
		return (NULL);
	node = head;
	i = 2;
	while (i < nbr_elemts)
	{
		node->next = ft_lstnew(ft_atoi(argv[i]));
		if (!node->next)
		{
			free_stack(&head);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	node->next = NULL;
	return (head);
}

int	*copy_lst(t_list *lst, int nbr_elemts)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * nbr_elemts);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nbr_elemts)
	{
		arr[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (arr);
}

int	*find_pivots(t_data *data)
{
	int	i;
	int	j;
	int	*pivots;

	i = data->chunk_size;
	j = 0;
	pivots = malloc(sizeof(int) * data->chunks);
	if (!pivots)
		return (NULL);
	while (j < data->chunks - 1)
	{
		pivots[j] = data->arr[i];
		j++;
		i = i + data->chunk_size;
	}
	pivots[j] = data->arr[data->nbr_elemts - 1];
	return (pivots);
}

int	set_nbr_chunks(t_data *data)
{
	if (data->nbr_elemts <= 100)
		return (5);
	else if (data->nbr_elemts <= 500)
		return (11);
	return (15);
}

t_data	*initialize_data(t_list *lst_a, int nbr)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nbr_elemts = nbr;
	data->chunks = set_nbr_chunks(data);
	data->chunk_size = data->nbr_elemts / data->chunks;
	if (data->nbr_elemts % data->chunks)
		data->chunk_size++;
	data->arr = copy_lst(lst_a, data->nbr_elemts);
	if (!data->arr)
		return (NULL);
	quick_sort(data->arr, 0, data->nbr_elemts - 1);
	if (data->nbr_elemts >= 20)
	{
		data->pivots = find_pivots(data);
		if (!data->pivots)
		{
			free((void *)data->arr);
			return (NULL);
		}
	}
	free((void *)data->arr);
	return (data);
}
