/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:52:48 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/29 17:26:19 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_init_sprite(t_cube *game)
{
	game->sprite1 = xpm_img(game, game->type[0], 32, 64);
	if (!game->sprite1)
		return (-1);
}

void	ft_print_sprite(t_cube *game)
{
	int x = 0;
	int y = 0;

	if (game->map[x][y] == "D")
		game->text
}