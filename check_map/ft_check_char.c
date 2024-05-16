/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:05:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/16 18:10:27 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	is_wall_espace_zero_endl(t_cube *game, int x, int y)
{
	if (game->map_game[x][y] != '1' && game->map_game[x][y] != '0'
			&& game->map_game[x][y] != ' ' && game->map_game[x][y] != '\n')
		return (TRUE);
	return (FALSE);
}

void	ft_write_er(int i)
{
	write(2, "Error\n", 7);
	if (i == 1)
		write(2, "map not valid : char not valid on map\n", 39);
	if (i == 2)
		write(2, "map not valid : invalid number of perso\n", 41);
	if (i == 3)
		write(2, "map not valid : walls incorrect\n", 33);
	if (i == 4)
		write(2, "Empty file\n", 12);
	if (i == 5)
		write(2, "Invalid numbers of types\n", 26);
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
