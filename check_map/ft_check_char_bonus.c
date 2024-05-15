/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:28 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/15 16:14:47 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

bool	is_wall_espace_zero_endl(t_cube *game, int x, int y)
{
	if (game->map_game[x][y] != '1' && game->map_game[x][y] != '0'
			&& game->map_game[x][y] != ' ' && game->map_game[x][y] != '\n')
		return (TRUE);
	return (FALSE);
}

void	ft_write_er(int i)
{
	write(1, "Error\n", 7);
	if (i == 1)
		write(1, "map not valid : char not valid on map\n", 39);
	if (i == 2)
		write(1, "map not valid : invalid number of perso\n", 41);
	if (i == 3)
		write(1, "map not valid : walls incorrect\n", 33);
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
		else if (is_wall_espace_zero_endl(game, x, y) == TRUE)
			return (ft_write_er(1), clear_wrong_text(game), 1);
		y++;
	}
	if (perso != 0)
		return (ft_write_er(2), clear_wrong_text(game), 1);
	return (0);
}

bool	is_wall_espace_zero_endl_bonu(t_cube *game, int x, int y)
{
	if (game->map_game[x][y] != '1' && game->map_game[x][y] != '0'
		&& game->map_game[x][y] != ' ' && game->map_game[x][y] != '\n'
		&& game->map_game[x][y] != 'D' && game->map_game[x][y] != 'H')
		return (TRUE);
	return (FALSE);
}

int	ft_check_char_bonus(t_cube *game, int x, int y)
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
		else if (is_wall_espace_zero_endl_bonu(game, x, y) == TRUE)
			return (ft_write_er(1), clear_wrong_text(game), 1);
		if (game->map_game[x][y] == 'H')
			game->nm_sprite++;
		y++;
	}
	if (perso != 0)
		return (ft_write_er(2), clear_wrong_text(game), 1);
	
	return (0);
}
