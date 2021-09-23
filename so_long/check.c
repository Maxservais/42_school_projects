/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:45:56 by mservais          #+#    #+#             */
/*   Updated: 2021/09/17 17:17:00 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid(t_param *param, char *str)
{
	int	res;
	int	i;
	int	row;
	int	col;

	res = -1;
	row = 0;
	while (row < param->map->height)
	{
		col = 0;
		while (col < param->map->width)
		{
			i = 0;
			while (str[i] != '\0')
			{
				if (param->map->board[row][col] == str[i])
					res = 0;
				i++;
			}
			col++;
		}
		row++;
	}
	return (res);
}

int	check_walls(t_param *param, int row, int col)
{
	while (row < param->map->height)
	{
		col = 0;
		while (col < param->map->width)
		{
			if (param->map->board[row][col] != '1')
				return (-1);
			col++;
		}
		row += param->map->height - 1;
	}
	col = 0;
	while (col < param->map->width)
	{
		row = 0;
		while (row < param->map->height)
		{
			if (param->map->board[row][col] != '1')
				return (-1);
			row++;
		}
		col += param->map->width - 1;
	}
	return (0);
}

int	check_obj_requirements(t_param *param, int row, int col)
{
	int	exit;
	int	player;
	int	collectible;

	exit = 0;
	player = 0;
	collectible = 0;
	while (row < param->map->height)
	{
		col = 0;
		while (col < param->map->width)
		{
			if (param->map->board[row][col] == 'E')
				exit++;
			else if (param->map->board[row][col] == 'P')
				player++;
			else if (param->map->board[row][col] == 'C')
				collectible++;
			col++;
		}
		row++;
	}
	if (exit < 1 || collectible < 1 || player != 1)
		return (-1);
	return (0);
}

int	check_map(t_param *param, char *filename)
{
	param->map->height = map_height(filename);
	param->map->width = map_width(filename, 0);
	if (param->map->width <= 0 || param->map->height <= 0)
		return (-1);
	if (parse_map(param, filename, 0, 0) == -1)
		return (-1);
	if (check_valid(param, "01CEP") == -1)
	{
		free_board(param, param->map->height);
		return (-1);
	}
	if (check_walls(param, 0, 0) == -1)
	{
		free_board(param, param->map->height);
		return (-1);
	}
	if (check_obj_requirements(param, 0, 0) == -1)
	{
		free_board(param, param->map->height);
		return (-1);
	}
	return (0);
}
