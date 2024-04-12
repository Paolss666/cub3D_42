/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:54:17 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/12 15:11:52 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw(t_cube *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->screen_h)
    {
        x = 0;
        while (x < game->screen_w)
        {
            game->img->full_buf[y * game->screen_w + x] = game->buf[y][x];
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, 0 , 0);
}
