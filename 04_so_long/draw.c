/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:44:20 by mservais          #+#    #+#             */
/*   Updated: 2021/09/20 14:46:11 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_frame(t_param *p)
{
	write(1, "Total steps: ", ft_strlen("Total steps: "));
	ft_putnbr(p->move_count);
	write(1, "\n", 1);
	if (draw_sprites(p, 0, 0))
		return (-1);
	if (draw_player(p))
		return (-1);
	return (0);
}

int	draw_floor_wall(t_param *p, int row, int col)
{
	void	*ptr;

	ptr = NULL;
	while (row < p->map->height)
	{
		col = 0;
		while (col < p->map->width)
		{
			ptr = p->sprite->floor;
			if (!ptr)
				return (-1);
			if (p->map->board[row][col] == '1')
				ptr = p->sprite->wall;
			if (!ptr)
				return (-1);
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, ptr,
				col * p->sprite->width, row * p->sprite->height);
			col++;
		}
		row++;
	}
	return (0);
}

int	draw_sprites(t_param *p, int row, int col)
{
	void	*ptr;

	ptr = NULL;
	while (row < p->map->height)
	{
		col = 0;
		while (col < p->map->width)
		{
			if (p->map->board[row][col] == 'E' ||
				p->map->board[row][col] == 'C')
			{
				if (p->map->board[row][col] == 'E')
					ptr = p->sprite->door;
				else if (p->map->board[row][col] == 'C')
					ptr = p->sprite->loot;
				if (!ptr)
					return (-1);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, ptr,
					col * p->sprite->width, row * p->sprite->height);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	draw_player(t_param *p)
{
	int		pos_x;
	int		pos_y;
	void	*player_ptr;

	pos_x = p->player->x * p->player->img_width;
	pos_y = p->player->y * p->player->img_height;
	player_ptr = p->player->player;
	if (!player_ptr)
		return (-1);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, player_ptr, pos_x, pos_y);
	return (0);
}

int	try_move(t_param *p, int y, int x, int row)
{
	int	col;
	int	collectibles;

	collectibles = 0;
	if (p->map->board[x][y] == '1')
		return (-1);
	else if (p->map->board[x][y] == 'C')
		p->map->board[x][y] = '0';
	else if (p->map->board[x][y] == 'E')
	{
		while (row < p->map->height)
		{
			col = 0;
			while (col < p->map->width)
			{
				if (p->map->board[row][col] == 'C')
					collectibles++;
				col++;
			}
			row++;
		}
		if (collectibles == 0)
			return (close_win(p));
	}
	return (0);
}
