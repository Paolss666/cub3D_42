/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:36 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/12 17:29:09 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	esc_close(int key, t_cube *game)
{
	if (key ==  XK_Escape)
	{
		mlx_destroy_image(game->mlx_ptr, game->img->img_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		ft_gbg(FLUSH, NULL, ALL);
		exit(0);
	}
	return (0);
}

int	close_win(t_cube *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img->img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_gbg(FLUSH, NULL, ALL);
	exit(0);
}
