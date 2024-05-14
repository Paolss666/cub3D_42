/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:19:32 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/14 21:30:59 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void    get_dir(t_cube *game, char c)
{
    if (c == 'E')
    {
        game->dir_x = 0;
        game->dir_y = 1;
        game->plane_x = 0.66;
        game->plane_y =  0;
        return ;
    }
    if (c == 'W')
    {
        game->dir_x = 0;
        game->dir_y = -1;
        game->plane_x = - 0.66;
        game->plane_y =  0;
        return ;
    }
    if (c == 'S')
    {
        game->dir_x = 1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y = - 0.66;
        return ;
    }
    if (c == 'N')
    {
        game->dir_x = -1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y =  0.66;
        return ;
    }
}

void    get_pos(t_cube *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
                || game->map[y][x] == 'W' || game->map[y][x] == 'S')
            {
                game->pos_y = (double)x + 0.5;
                game->pos_x = (double)y + 0.5;
                get_dir(game, game->map[y][x]);
                game->map[y][x] = '0';
            }
			if (game->map[y][x] == 'H')
				get_pos_sprite(game, y, x);
            x++;
        }
        y++;
    }
}
