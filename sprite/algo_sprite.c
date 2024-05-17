/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:07:27 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/15 16:55:21 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	dry_da_algo_sprite(t_cube *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_n)
	{
		if (game->sprite[i]->map_x_s == game->map_x
			&& game->sprite[i]->map_y_s == game->map_y)
			game->sprite[i]->dist_sprite
				= (game->side_dist_x - game->delta_dist_x);
		i++;
	}
}

double	invert_neg(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void	get_pos_sprite(t_cube *game, int y, int x)
{
	game->sprite[game->sprite_n]->map_x_s = y;
	game->sprite[game->sprite_n]->map_y_s = x;
	game->sprite_n++;
}

double	sprite_more_far(t_cube *game, int *n)
{
	int		i;
	double	temp;
	int		j;

	i = 0;
	j = 0;
	temp = invert_neg(game->sprite[i]->dist_sprite);
	while (i < game->sprite_n)
	{
		if (temp < invert_neg(game->sprite[i]->dist_sprite))
		{
			temp = game->sprite[i]->dist_sprite;
			j = i;
		}
		i++;
	}
	*n = j;
	game->sprite[j]->order = 1;
	return (temp);
}

int	sprite_less_far(t_cube *game, double far)
{
	int		i;
	double	temp;
	int		j;

	i = 0;
	j = 0;
	while (i < game->sprite_n && game->sprite[i]->order != -1)
		i++;
	temp = invert_neg(game->sprite[i]->dist_sprite);
	j = i;
	while (i < game->sprite_n)
	{
		if (invert_neg(game->sprite[i]->dist_sprite) < invert_neg(far)
			&& invert_neg(game->sprite[i]->dist_sprite) >= invert_neg(temp))
		{
			temp = invert_neg(game->sprite[i]->dist_sprite);
			j = i;
		}
		i++;
	}
	game->sprite[j]->order = 1;
	return (j);
}
