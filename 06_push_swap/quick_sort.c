/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:18:18 by mservais          #+#    #+#             */
/*   Updated: 2021/11/04 19:45:57 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low - 1;
	j = low;
	pivot = arr[high];
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort(arr, low, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high);
	}
}
