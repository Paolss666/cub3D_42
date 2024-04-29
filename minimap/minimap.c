/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:38:49 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/29 15:58:07 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

#define WIDTH  80
#define HEIGHT 100

void	ft_color_perso(t_cube *game)
{
	int	x;
	int	y;

	x = 37;
	y = 47;
	while (x < 44)
	{
		game->buf[x][50] = 16711680;
		if (x < 43 && x > 37)
			game->buf[x][x + 10] = 16711680;
		while (x == 40 && y < 54)
			game->buf[x][y++] = 16711680;
		x++;
	}
	x = 40;
	y = 50;
	game->buf[x - 1][y + 1] = 16711680;
	game->buf[x - 2][y + 2] = 16711680;
	game->buf[x + 1][y - 1] = 16711680;
	game->buf[x + 2][y - 2] = 16711680;
}

//bool	ft_virg(int x, int y, int a_virg, int b_virg)
//{
//	b_virg = b_virg % 10;
//	a_virg = a_virg % 10;
//	if ((x + b_virg) % 10 == 0 || (y + a_virg) % 10 == 0)
//		return (TRUE);
//	return (FALSE);
//}

bool	ft_bmap(t_cube *game, int c, int d, char wall)
{
	if (game->map[c][d] && game->map[c][d] == wall)
		return (TRUE);
	return (FALSE);
}

bool	limit(t_cube *game)
{
	if (game->p_c < 0 || game->p_d < 0 || game->p_d >= game->crow
		|| game->p_c >= game->l)
		return (TRUE);
	if (ft_bmap(game, game->p_c, game->p_d, '1') == TRUE)
		return (TRUE);
	return (FALSE);
}

void	ft_init_minimap(t_cube *game, int *x, int *y)
{
	game->p_c = (int)game->pos_x - 3;
	game->p_d = (int)game->pos_y - 4;
	game->pv_c = (game->pos_x * 10);
	game->pv_d = (game->pos_y * 10);
	if (game->pv_d % 10 != 0)
		game->p_d--;
	*y = 10;
	*x = 10;
}

void	ft_cal_minimap(t_cube *game, int *x, int *y)
{
	*x = 9;
	*y = (*y + 1);
	game->p_d = (int)game->pos_y - 4;
	if (game->pv_d % 10 == 0)
		game->p_d--;
	if ((*y + (game->pv_c % 10)) % 10 == 0)
		game->p_c++;
}

int	ft_put_minimap(t_cube *game)
{
	int	y;
	int	x;

	if (game->p_minimap == 0)
		return (0);
	ft_init_minimap(game, &x, &y);
	while (1)
	{
		if (x == HEIGHT || y == WIDTH || x == 10
			|| y == 10 || limit(game) == TRUE)
		{
			game->buf[y][x] = 0;
			if (x == HEIGHT && y == WIDTH)
				break ;
		}
		else
			game->buf[y][x] = 16763956;
		if ((x + (game->pv_d % 10)) % 10 == 0)
			game->p_d++;
		if (x == HEIGHT)
			ft_cal_minimap(game, &x, &y);
		x++;
	}
	ft_color_perso(game);
	return (0);
}
