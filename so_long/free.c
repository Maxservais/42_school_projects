/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:48:08 by mservais          #+#    #+#             */
/*   Updated: 2021/09/17 18:02:48 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_structs(t_param *p)
{
	free(p->sprite);
	free(p->player);
	free(p->map);
	free(p);
	error_message();
	return (1);
}

int	free_board(t_param *p, int n)
{
	while (n > 0)
	{
		free(p->map->board[n - 1]);
		n--;
	}
	free(p->map->board);
	return (1);
}

int	free_sprites(t_param *p)
{
	mlx_destroy_image(p->mlx_ptr, p->sprite->floor);
	mlx_destroy_image(p->mlx_ptr, p->sprite->wall);
	mlx_destroy_image(p->mlx_ptr, p->sprite->door);
	mlx_destroy_image(p->mlx_ptr, p->sprite->loot);
	mlx_destroy_image(p->mlx_ptr, p->player->player);
	return (1);
}

int	free_board_and_structs(t_param *p)
{
	free_board(p, p->map->height);
	free_structs(p);
	return (1);
}

int	free_all(t_param *p)
{
	free_board(p, p->map->height);
	free_sprites(p);
	free_structs(p);
	return (1);
}
