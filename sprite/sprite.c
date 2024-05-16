/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:52:48 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/16 16:06:04 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	define_sprite(t_cube *game, int j)
{
	double	far;
	int		far2;
	int		d;

	far = 0.0;
	far2 = 0;
	d = 0;
	if (j == 0)
	{
		if (game->sprite_n > 1)
		{
			far = sprite_more_far(game, &d);
			far2 = sprite_less_far(game, far);
		}
		game->sp_x = (game->sprite[d]->map_x_s + 0.5) - game->pos_x;
		game->sp_y = (game->sprite[d]->map_y_s + 0.5) - game->pos_y;
	}
	return (far2);
}

//tr_x = transform_x et sprite_x = sp_x>>>
void	calcul_vis_sprite(t_cube *game)
{
	double	inv_det;

	inv_det = 1.0 / (game->plane_x * game->dir_y - game->dir_x * game->plane_y);
	game->tr_x
		= inv_det * (game->dir_y * game->sp_x - game->dir_x * game->sp_y);
	game->tr_y
		= inv_det * (-game->plane_y * game->sp_x + game->plane_x * game->sp_y);
	game->s_screen_x
		= (int)((game->screen_w / 2) * (1 + game->tr_x / game->tr_y));
	game->s_height = abs((int)(game->screen_h / game->tr_y));
	game->draw_start_y = -game->s_height / 2 + game->screen_h / 2;
	if (game->draw_start_y < 0)
		game->draw_start_y = 0;
	game->draw_end_y = game->s_height / 2 + game->screen_h / 2;
	if (game->draw_end_y >= game->screen_h)
		game->draw_end_y = game->screen_h - 1;
	game->s_width = abs((int)(game->screen_w / game->tr_y));
	game->draw_start_x = -game->s_width / 2 + game->s_screen_x;
	if (game->draw_start_x < 0)
		game->draw_start_x = 0;
	game->draw_end_x = game->s_width / 2 + game->s_screen_x;
	if (game->draw_end_x >= game->screen_w)
		game->draw_end_x = game->screen_w - 1;
}

void	color_sprite(t_cube *game, unsigned int color)
{
	int	stripe;
	int	y;
	int	d;
	int	calcul;

	stripe = game->draw_start_x - 1;
	while (++stripe < game->draw_end_x)
	{
		calcul = (stripe - (-game->s_width / 2 + game->s_screen_x));
		game->tex_x = (int)(256 * calcul * game->tex_w / game->s_width) / 256;
		if (game->tr_y > 0 && stripe > 0 && stripe < game->screen_w
			&& game->tr_y < game->z_buffer[stripe])
		{
			y = game->draw_start_y - 1;
			while (++y < game->draw_end_y)
			{
				d = (y) * 256 - game->screen_h * 128 + game->s_height * 128;
				game->tex_y = ((d * game->tex_h) / game->s_height) / 256;
				color = game->tex[game->n_sprite + 5]
				[game->tex_w * game->tex_y + game->tex_x];
				if (color != 1711396 && color != 1842466)
					game->buf[y][stripe] = color;
			}
		}
	}
}

int	define_sprite_2(t_cube *game, int j, int far2)
{
	double	far;

	if (j != 1)
	{
		far = game->sprite[far2]->dist_sprite;
		far2 = sprite_less_far(game, far);
	}
	game->sp_x = (game->sprite[far2]->map_x_s + 0.5) - game->pos_x;
	game->sp_y = (game->sprite[far2]->map_y_s + 0.5) - game->pos_y;
	return (far2);
}

void	sprite_draw(t_cube *game)
{
	int	far2;
	int	j;

	far2 = 0;
	j = 0;
	if (game->sprite_n == 0)
		return ;
	else
	{
		while (j < game->sprite_n)
		{
			if (j == 0)
				far2 = define_sprite(game, j);
			else
				far2 = define_sprite_2(game, j, far2);
			(increm_sprite(game), calcul_vis_sprite(game));
			color_sprite(game, 0);
			j++;
		}
	}
	init_sprite_order(game);
}
