/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/16 15:28:05 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D2_H
#define cub3D2_H

#include "cub3D.h"
# include "./libft/libft.h"
//# include "../mlx_linux/mlx.h"
# include "X11/X.h"      // verifier
# include "X11/keysym.h"
# include <math.h>
#include <stdbool.h>


// pour checker la map
void	ft_add_space(t_cube *game);
int		ft_countrows(t_cube *game);
int		ft_countline(t_cube *game);
int		ft_adjust_row(t_cube *game);
void	ft_stock_map(t_cube *game);
bool	is_perso(char **map, int x, int y);
void	ft_check_frontier(t_cube *game, int x, int y);
int ft_check_char(t_cube *game, int x, int y);
void ft_add_wall(t_cube *game);
int ft_check_map(t_cube *game);

# define MLX_ERROR 1

#endif