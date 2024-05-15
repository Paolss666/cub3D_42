/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:03:10 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/15 16:03:49 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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
