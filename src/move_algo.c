/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:44:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/24 18:14:22 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void	move_up(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x + game->dir_x * (game->move_speed
				+ 0.01))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y + game->dir_y
			* (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x += game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y += game->dir_y * game->move_speed;
}

void	move_down(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x - game->dir_x * (game->move_speed
				+ 0.01))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y - game->dir_y
			* (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x -= game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y -= game->dir_y * game->move_speed;
}

void	move_left(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x)][(int)(game->pos_y - game->dir_x
			* (game->move_speed + 0.01))];
	new_pos_y = game->map[(int)(game->pos_x - game->dir_y * (game->move_speed
				+ 0.01))][(int)(game->pos_y)];
	if (new_pos_x != '1')
		game->pos_y -= game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_x -= game->dir_y * game->move_speed;
}

void	move_right(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x)][(int)(game->pos_y + game->dir_x
			* (game->move_speed + 0.01))];
	new_pos_y = game->map[(int)(game->pos_x + game->dir_y * (game->move_speed
				+ 0.01))][(int)(game->pos_y)];
	if (new_pos_x != '1')
		game->pos_y += game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_x += game->dir_y * game->move_speed;
}
