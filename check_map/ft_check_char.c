/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:05:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/08 15:56:59 by npaolett         ###   ########.fr       */
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
			return (write(1,
					"Error\nmap not valid : char not valid on map\n", 45),
				clear_wrong_text(game), 1);
		y++;
	}
	if (perso != 0)
		return (write(1, "Error\nmap not valid : invalid number of perso\n", 47),
			clear_wrong_text(game), 1);
	return (0);
}

bool	is_wall_espace_zero_endl_bonu(t_cube *game, int x, int y)
{
	if (game->map_game[x][y] != '1' && game->map_game[x][y] != '0'
		&& game->map_game[x][y] != ' ' && game->map_game[x][y] != '\n'
		&& game->map_game[x][y] != 'D')
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
			return (write(1,
					"Error\nmap not valid : char not valid on map\n", 45),
				clear_wrong_text(game), 1);
		y++;
	}
	if (perso != 0)
		return (write(1, "Error\nmap not valid : invalid number of perso\n", 47),
			clear_wrong_text(game), 1);
	return (0);
}
