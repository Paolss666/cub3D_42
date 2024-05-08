/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:50:56 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/08 15:55:54 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// # include <stddef.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <stdio.h>
// void	ft_print_maperror(t_cube *game, char **map, int x, int y) //a supprimer
// {
// 	int b = 0;
// 	printf("%c = %d, %d\n", map[x][y], x, y);
// 	printf("gamecrow = %d\n", game->crow);
// 	printf("gamel = %d\n", game->l);
// 	printf("gamerownico = %d\n", game->rows);
// 	printf("gamelinenico = %d\n", game->line);
// 	while (b < game->l)
// 	{
// 		printf("%s\n", map[b]);
// 		b++;
// 	}
// }

void	ft_add_space(t_cube *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != game->l)
	{
		if (game->map_game[i][j] == '\n' || (game->map_game[i][j] == '\0'
			&& j <= game->crow))
			game->map_game[i][j] = ' ';
		if (j == game->crow)
		{
			i++;
			j = 0;
		}
		j++;
	}
}

int	ft_countrows(t_cube *game)
{
	int	i;
	int	y;
	int	x;

	y = 0;
	x = 0;
	i = 0;
	while (1)
	{
		if (!(game->map[x][y]))
		{
			if (!game->map[x + 1])
				break ;
			x++;
			if (i < y)
				i = y;
			y = 0;
		}
		else
			y++;
	}
	return (i);
}

int	ft_countline(t_cube *game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i])
		i++;
	return (i);
}

void	ft_stock_map(t_cube *game)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	game->map_game = NULL;
	game->map_game = ft_calloc((sizeof(char *)), (game->line));
	if (!game->map_game || ft_gbg(ADD, game->map_game, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit (99), (void)0);
	while (k < game->l)
	{
		game->map_game[k] = ft_calloc(sizeof(char), game->crow + 2);
		if (!game->map_game[k] || ft_gbg(ADD, game->map_game[k], PARS))
			return (ft_gbg(FLUSH, NULL, ALL), exit (99), (void)0);
		ft_strlcpy(game->map_game[k], game->map[i], game->crow + 1);
		i++;
		k++;
	}
	ft_add_space(game);
}
