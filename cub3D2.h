/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/16 14:48:37 by elcesped         ###   ########.fr       */
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

typedef struct s_cube
{
    char    **map;
	char	**map_game;
    void	*mlx_ptr;
	void	*win_ptr;
	char	**type;
	int		rows;
	int		line;
	t_img	*img;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	t_img	*door;
	unsigned int	f_color;
	unsigned int	c_color;
	int				*f;
	int				*c;
	unsigned int	**tex;
	int				tex_h;
	int				tex_w;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			pos_x;
	double			pos_y;

}               t_cube;

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