/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:45:26 by mservais          #+#    #+#             */
/*   Updated: 2021/09/20 14:31:17 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_param *p)
{
	free_sprites(p);
	free_board(p, p->map->height);
	free(p->sprite);
	free(p->player);
	free(p->map);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free(p);
	exit(0);
	return (0);
}

int	deal_key(int key, t_param *p)
{
	void	*sprite_ptr;

	if (key == ESCAPE)
		close_win(p);
	sprite_ptr = p->sprite->floor;
	if (!sprite_ptr)
		close_win(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr,
		sprite_ptr, p->player->x * BLOC_SIZE, p->player->y * BLOC_SIZE);
	if (key == UP && !try_move(p, p->player->x, p->player->y - 1, 0))
		p->player->y -= 1;
	else if (key == DOWN && !try_move(p, p->player->x, p->player->y + 1, 0))
		p->player->y += 1;
	else if (key == LEFT && !try_move(p, p->player->x - 1, p->player->y, 0))
		p->player->x -= 1;
	else if (key == RIGHT && !try_move(p, p->player->x + 1, p->player->y, 0))
		p->player->x += 1;
	p->move_count++;
	if (draw_frame(p))
		close_win(p);
	return (0);
}
