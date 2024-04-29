/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:56:26 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/29 17:00:11 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	wall_size(t_cube *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
	game->line_height = (int)(game->screen_h / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + game->screen_h / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->screen_h / 2;
	if (game->draw_end >= game->screen_h)
		game->draw_end = game->screen_h;
}

void	dry_da_algo(t_cube *game)
{
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_x][game->map_y] == '1'
			|| game->map[game->map_x][game->map_y] == 'D' )
			game->hit = 1;
	}
}

void	hit_init_side(t_cube *game)
{
	game->hit = 0;
	if (game->raydir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x
				- game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x
				+ 1.0 - game->pos_x) * game->delta_dist_x;
	}
	if (game->raydir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y
				+ 1.0 - game->pos_y) * game->delta_dist_y;
	}
}

void	ft_free_bffr(t_cube *game)
{
	int	i;

	i = 0;
	while (i < game->screen_h && game->buf && game->buf[i])
	{
		ft_gbg(FREE, game->buf[i], PARS);
		i++;
	}
	ft_gbg(FREE, game->buf, PARS);
	game->buf = NULL;
}

int	display(t_cube *game, int x)
{
	init_buf(game);
	while (x < game->screen_w)
	{
		game->camera_x = 2 * x / (double)game->screen_w - 1;
		game->raydir_x = game->dir_x + game->plane_x * game->camera_x;
		game->raydir_y = game->dir_y + game->plane_y * game->camera_x;
		game->map_x = (int)game->pos_x;
		game->map_y = (int)game->pos_y;
		if (game->raydir_x == 0)
			game->delta_dist_x = pow(10, 30);
		else
			game->delta_dist_x = fabs(1 / game->raydir_x);
		if (game->raydir_y == 0)
			game->delta_dist_y = pow(10, 30);
		else
			game->delta_dist_y = fabs(1 / game->raydir_y);
		(hit_init_side(game), dry_da_algo(game),
			wall_size(game), texture(game, x));
		x++;
	}
	ft_put_minimap(game);
	draw(game);
	ft_free_bffr(game);
	return (0);
}

