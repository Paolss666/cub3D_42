/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:11:38 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/30 13:58:05 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int lows(double nb)
{
	double	i;

	i = 0.0;
	while (i < nb)
		i += 1;
	i -= 1;
	return ((int)i);
}

void	door_open(t_cube *game)
{
	if (game->map[game->m_x][game->m_y] == 'D'
	&& ((game->d_x <= 2 && game->d_x >= 0)
	|| (game->d_y <= 2 && game->d_y >= 0)))
		game->map[game->m_x][game->m_y] = 'd';
}

void	close_door(t_cube *game)
{
	int	m_x;
	int	m_y;

	m_x = 0;
	while (game->map[m_x])
	{
		m_y = 0;
		while (game->map[m_x][m_y])
		{
			if (game->map[m_x][m_y] == 'd'
			&& game->map[lows(game->pos_x)][lows(game->pos_y)] != 'd')
				game->map[m_x][m_y] = 'D';
			m_y++;
		}	
		m_x++;
	}
}

void	variable_door_bonus(t_cube *game)
{
	game->m_y = game->map_y;
	game->m_x = game->map_x;
	game->d_y = (int)game->side_dist_y;
	game->d_x = (int)game->side_dist_x;
}
