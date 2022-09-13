/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:48:26 by mservais          #+#    #+#             */
/*   Updated: 2021/09/17 16:02:46 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_param	*ft_free(t_param *p)
{
	free(p);
	return (NULL);
}

t_param	*init_structs(void)
{
	t_param	*p;

	p = malloc(sizeof(t_param));
	if (!p)
		return (NULL);
	p->move_count = 0;
	p->map = malloc(sizeof(t_map));
	if (!p->map)
		return (ft_free(p));
	p->player = malloc(sizeof(t_player));
	if (!p->player)
	{
		free(p->map);
		return (ft_free(p));
	}
	p->sprite = malloc(sizeof(t_sprite));
	if (!p->sprite)
	{
		free(p->player);
		free(p->map);
		return (ft_free(p));
	}
	return (p);
}

int	init_board(t_param *p)
{
	int	row;

	p->map->board = malloc(sizeof(char *) * p->map->height);
	if (!p->map->board)
		return (-1);
	row = 0;
	while (row < p->map->height)
	{
		p->map->board[row] = malloc(sizeof(char) * p->map->width);
		if (!p->map->board[row])
			return (free_board(p, row));
		row++;
	}
	return (0);
}

int	init_sprites(t_param *p)
{
	p->sprite->floor = mlx_xpm_file_to_image(p->mlx_ptr,
			FLOOR, &p->sprite->width, &p->sprite->height);
	if (!p->sprite->floor)
		return (free_sprites(p));
	p->sprite->wall = mlx_xpm_file_to_image(p->mlx_ptr,
			WALL, &p->sprite->width, &p->sprite->height);
	if (!p->sprite->wall)
		return (free_sprites(p));
	p->sprite->door = mlx_xpm_file_to_image(p->mlx_ptr,
			DOOR, &p->sprite->width, &p->sprite->height);
	if (!p->sprite->door)
		return (free_sprites(p));
	p->sprite->loot = mlx_xpm_file_to_image(p->mlx_ptr,
			LOOT, &p->sprite->width, &p->sprite->height);
	if (!p->sprite->loot)
		return (free_sprites(p));
	p->player->player = mlx_xpm_file_to_image(p->mlx_ptr,
			PLAYER, &p->player->img_width, &p->player->img_height);
	if (!p->player->player)
		return (free_sprites(p));
	return (0);
}
