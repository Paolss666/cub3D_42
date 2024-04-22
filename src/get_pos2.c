/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:16:40 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/22 12:00:02 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_mlx(t_cube *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w,
			game->screen_h, "cub3d");
	if (!game->win_ptr)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	game->img = ft_calloc(sizeof(t_img), 1);
	if (!game->img || ft_gbg(ADD, game->img, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	game->img->img_ptr = mlx_new_image(game->mlx_ptr, game->screen_w,
			game->screen_h);
	if (!game->img->img_ptr)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	game->img->full_buf = (int *)mlx_get_data_addr(game->img->img_ptr,
			&game->img->bpp, &game->img->size, &game->img->endian);
	if (!game->img->full_buf)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
}


int	init_buf(t_cube *game)
{
	int	y;

	y = 0;
	game->buf = ft_calloc(sizeof(unsigned int *), game->screen_h);
	if (!game->buf || ft_gbg(ADD, game->buf, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
	while (y < game->screen_h)
	{
		game->buf[y] = ft_calloc(sizeof(unsigned int), game->screen_w);
		if (!game->buf[y] || ft_gbg(ADD, game->buf[y], PARS))
			return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
		y++;
	}
	return (0);
}
