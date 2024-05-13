/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:21 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/13 13:58:03 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	mouse_position(t_cube *game, int x, int y)
{
	if (x > game->screen_w - DEST_MOUSE)
	{
		x = DEST_MOUSE;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
	}
	if (x < DEST_MOUSE)
	{
		x = game->screen_w - DEST_MOUSE;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
	}
}

int	mouse_mov(int x, int y, t_cube *game)
{
	static int	last_x = SCREEN_W / 2;

	if (game->click == 1)
	{
		mouse_position(game, x, y);
		if (x == last_x)
			return (0);
		else if (x < last_x)
			m_rotate_left(game, 0.01);
		else if (x > last_x)
			m_rotate_right(game, 0.01);
	}
	last_x = x;
	(void)y;
	return (0);
}

int	mouse_but(int button, int x, int y, t_cube *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->click *= -1;
	return (0);
}
