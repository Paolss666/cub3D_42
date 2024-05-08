/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:09:10 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/08 15:56:27 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
			write(1, "Error\nmap not valid : walls incorrect\n", 39);
			return (clear_wrong_text(game), (void)0);
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
	if (BONUS != 2 && ft_check_char(game, 0, 0) == 1)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), 1);
	}
	else if (BONUS == 2)
	{
		if (ft_check_char_bonus(game, 0, 0) == 1)
		{
			mlx_destroy_display(game->mlx_ptr);
			return (ft_gbg(FLUSH, NULL, ALL), exit(99), 1);
		}
	}
	ft_check_frontier(game, 0, 0);
	ft_add_wall(game);
	game->map = game->map_game;
	return (0);
}
