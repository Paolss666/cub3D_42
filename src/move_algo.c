/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:44:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/23 17:15:09 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	play_move_calcul(t_cube *game)
{
	return (atan2(game->pos_y, game->pos_x));
}

void	move_up(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x + game->dir_x * (game->move_speed
				+ 0.5))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y + game->dir_y
			* (game->move_speed + 0.5))];
	if (new_pos_x != '1')
	{
		game->pos_x += game->dir_x * game->move_speed;
		printf("game->pos_x up %f\n", game->pos_x);
	}
	if (new_pos_y != '1')
	{
		game->pos_y += game->dir_y * game->move_speed;
		printf("game->pos_y up %f\n", game->pos_y);
	}
}

void	move_down(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x - game->dir_x * (game->move_speed
				+ 0.5))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y - game->dir_y
			* (game->move_speed + 0.5))];
	if (new_pos_x != '1')
	{
		game->pos_x -= game->dir_x * game->move_speed;
		printf("game->pos_x down %f\n", game->pos_x);
	}
	if (new_pos_y != '1')
	{
		game->pos_y -= game->dir_y * game->move_speed;
		printf("game->pos_y down %f\n", game->pos_y);
	}
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
	{
		game->pos_y -= game->dir_x * game->move_speed;
		printf("game->pos_x right %f\n", game->pos_x);
	}
	if (new_pos_y != '1')
	{
		game->pos_x -= game->dir_y * game->move_speed;
		printf("game->pos_y right %f\n", game->pos_x);
	}
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
	{
		game->pos_y += game->dir_x * game->move_speed;
		printf("game->pos_x left %f\n", game->pos_x);
	}
	if (new_pos_y != '1')
	{
		game->pos_x += game->dir_y * game->move_speed;
		printf("game->pos_x left %f\n", game->pos_x);
	}
}
