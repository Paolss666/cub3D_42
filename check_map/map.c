/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:50:56 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:53 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// --------------------------------------------- POUR CHECKER LA MAP --------------------------------------------
/*
void	ft_print_maperror(t_cube *game, char **map, int x, int y) //a supprimer
{
	int b = 0;
	printf("%c = %d, %d\n", map[x][y], x, y);
	printf("gamerow = %d\n", game->crow); 
	while (b < game->l)
	{
		printf("%s\n", map[b]);
		b++;
	}
}
*/

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

	i = 0;
	while (game->map[0][i] && game->map[0][i])
		i++;
	return (++i);
}

int	ft_countline(t_cube *game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i])
		i++;
	return (i);
}

int	ft_adjust_row(t_cube *game)
{
	int	crow;
	int	i;

	crow = 0;
	i = ft_countline(game);
	while (game->map && game->map[i - 1][0] == '\n')
	{
		i--;
		while (game->map[i - 1][crow] != '\0')
			crow++;
		if (crow > game->crow)
			game->crow = crow;
	}
	return (i);
}

void	ft_stock_map(t_cube *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = ft_adjust_row(game);
	i = j;
	while (game->map && game->map[i - 1][0] != '\n')
		i--;
	game->l = j - i;
	game->map_game = NULL;
	game->map_game = (char **)malloc((sizeof(char *)) * (j - i + 1));
	if (!game->map_game || ft_gbg(ADD, game->map_game, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit (99), (void)0);
	game->l = j - i;
	while (k < game->l)
	{
		game->map_game[k] = ft_calloc(sizeof(char), game->crow + 2);
		if (!game->map_game[k] || ft_gbg(ADD, game->map_game[k], PARS))
			return (ft_gbg(FLUSH, NULL, ALL), exit (99), (void)0);
		ft_strlcpy(game->map_game[k], game->map[i], game->crow + 2);
		i++;
		k++;
	}
	ft_add_space(game);
}

bool	is_perso(char **map, int x, int y)
{
	if (map[x][y] == 'N' || map[x][y] == 'E'
		|| map[x][y] == 'S' || map[x][y] == 'W')
		return (TRUE);
	return (FALSE);
}

void	ft_check_frontier(t_cube *game, int x, int y)
{
	char	**map;

	map = game->map_game;
	while (1)
	{
		if ((map[x][y] == '0' || is_perso(map, x, y) == TRUE) && (x == 0
			|| y == 0 || x == game->l - 1 || y == game->crow
			|| (map[x - 1][y] == ' ' || map[x][y + 1] == ' '
			|| map[x][y - 1] == ' ' || map[x + 1][y] == ' ')))
		{
			write(1, "map not valid : walls incorrect\n", 33);
			return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	//	ft_print_maperror(game, map, x, y); //a supprimer
		}	
		if (x == game->l - 1 && y == game->crow)
			break ;
		if (y == game->crow)
		{
			y = 0;
			x++;
		}
		y++;
	}
}

int	ft_check_char(t_cube *game, int x, int y)
{
	int	perso;

	perso = 1;
	while (1)
	{
		if (game->map_game[x][y] == '\0')
		{	
			x++;
			if (x == game->l)
				break ;
			y = 0;
			continue ;
		}
		if (is_perso(game->map_game, x, y) == TRUE)
			perso--;
		else if (game->map_game[x][y] != '1' && game->map_game[x][y] != '0'
			&& game->map_game[x][y] != ' ' && game->map_game[x][y] != '\n')
			return (write(1, "map not valid : char not valid on map\n", 39), 1);
		y++;
	}
	if (perso != 0)
		return (write(1, "map not valid : invalid number of perso\n", 41), 1);
	return (0);
}

void	ft_add_wall(t_cube *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (1)
	{
		if (game->map_game[x][y] == '\0')
		{	
			x++;
			if (x == game->l)
				break ;
			y = 0;
			continue ;
		}
		if (game->map_game[x][y] == ' ')
			game->map_game[x][y] = '1';
		y++;
	}
}

int	ft_check_map(t_cube *game)
{
	game->crow = ft_countrows(game);
	game->l = ft_countline(game);
	ft_stock_map(game);
//	int i = 0;
//	while (i < game->l)
//	{
//		printf("la map stockee finale est celle ci : %s\n", game->map_game[i]);
//		i++;
//	}
	if (ft_check_char(game, 0, 0) == 1)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), 1);
	ft_check_frontier(game, 0, 0);
	ft_add_wall(game);
	return (0);
}

