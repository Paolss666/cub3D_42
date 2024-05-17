/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:40:35 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/16 16:05:43 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	init_pre_sprite_map(t_cube *game)
{
	game->p_minimap = 0;
	game->n_sprite = 0;
	game->sprite1 = NULL;
	game->sprite2 = NULL;
	game->sprite3 = NULL;
	game->nm_sprite = 0;
	game->sprite_n = 0;
	game->sp_x = 0.0;
	game->sp_y = 0.0;
	game->tr_x = 0.0;
	game->tr_x = 0.0;
	game->s_screen_x = 0;
	game->s_height = 0;
	game->s_width = 0;
	game->draw_end_x = 0;
	game->draw_end_y = 0;
	game->draw_start_x = 0;
	game->draw_start_y = 0;
}

void	init_sprite(t_cube *game)
{
	int	i;

	i = 0;
	game->sprite = malloc(game->nm_sprite * sizeof(t_sprite *));
	if (!game->sprite || ft_gbg(ADD, game->sprite, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), (void)0);
	while (i < game->nm_sprite)
	{
		game->sprite[i] = (t_sprite *)malloc(sizeof(t_sprite));
		if (!game->sprite[i] || ft_gbg(ADD, game->sprite[i], PARS))
			return (ft_gbg(FLUSH, NULL, ALL), (void)0);
		i++;
	}
	i = 0;
	while (i < game->nm_sprite)
	{
		game->sprite[i]->map_x_s = 0;
		game->sprite[i]->map_y_s = 0;
		game->sprite[i]->side_dist_x_sprite = 0;
		game->sprite[i]->side_dist_y_sprite = 0;
		game->sprite[i]->dist_sprite = 0;
		game->sprite[i]->order = -1;
		i++;
	}
}

void	init_sprite_order(t_cube *game)
{
	int	g;

	g = 0;
	while (g < game->nm_sprite)
	{
		game->sprite[g]->order = -1;
		g++;
	}
}

void	increm_sprite(t_cube *game)
{
	static int	i = 0;

	if (i > 300 && i <= 600)
	{
		game->n_sprite = 1;
		i++;
	}
	else if (i > 600 && i <= 900)
	{
		game->n_sprite = 2;
		i++;
	}
	else
	{
		game->n_sprite = 0;
		i++;
		if (i > 900)
			i = 0;
	}
}

void	display_bonus(t_cube *game)
{
	sprite_draw(game);
	ft_put_minimap(game);
}
