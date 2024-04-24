/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:49 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/24 15:54:36 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    m_rotate_right(t_cube *game, float move_speed)
{
    float   old_dir_x;
    float   old_plane_x;

    old_dir_x = game->dir_x;
    game->dir_x = game->dir_x * cos(-move_speed) - game->dir_y * sin(-move_speed);
    game->dir_y = old_dir_x * sin(-move_speed) + game->dir_y * cos(-move_speed);
    old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(-move_speed) - game->plane_y * sin(-move_speed);
    game->plane_y = old_plane_x * sin(-move_speed) + game->plane_y * cos(-move_speed);
}


void    m_rotate_left(t_cube *game, float move_speed)
{
    float old_dir_x;
    float old_plane_x;

	old_dir_x = game->dir_x;
    game->dir_x = game->dir_x * cos(move_speed) - game->dir_y * sin(move_speed);
    game->dir_y = old_dir_x * sin(move_speed) + game->dir_y * cos(move_speed);
    old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(move_speed) - game->plane_y * sin(move_speed);
    game->plane_y = old_plane_x * sin(move_speed) + game->plane_y * cos(move_speed);
 
    
}
