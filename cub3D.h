/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/02 15:04:57 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
#define cub3D_H

# include "./libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "X11/X.h"      // verifier
# include "X11/keysym.h"
# include <math.h>

# define MLX_ERROR 1

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_len;
	int		endian;

	int		*full_buf;
	int		size;
}		t_img;

typedef struct s_cube
{
    char    **map;
    void	*mlx_ptr;
	void	*win_ptr;
	char	**type;
	int		rows;
	t_img	*img;
}               t_cube;


int	check_file_open(char **av);
int	get_types(t_cube *game, char **av);
int	cpy_map_from_file(t_cube *game, char **argv, int rows);
void	ft_count_rows(t_cube *game, int fd, int *rows);
int	get_map(t_cube *game, int fd, char **av);
#endif