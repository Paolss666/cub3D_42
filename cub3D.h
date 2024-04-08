/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/08 10:40:05 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
#define cub3D_H

# include "./libft/libft.h"
# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "X11/X.h"      // verifier
# include "X11/keysym.h"


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

}               t_cube;

char	**ft_split_gbg(char const *s, char c);
int		check_file_open(char **av);
int		get_types(t_cube *game, char **av);
int		cpy_map_from_file(t_cube *game, char **argv, int rows);
void	ft_count_rows(t_cube *game, int fd, int *rows);
int		get_map(t_cube *game, int fd, char **av);
int		is_wspc_excl_nl(char c);
void	swap_ptrs(char **s1, char **s2);
int		check_types(char **new);
int		ptr_to_swap(char *s);
int		search_type(char *type, char **new);
int		reorder_new(char **new);
int		found_redif_type(t_cube *game);
int		get_file_content(t_cube *game, char **argv);
t_img	*xpm_img(t_cube *game, char *img_path, int w, int h);
int     get_color(int *tab_c);
int	*ft_parse_for_color(char *identi);
int	check_chars(char *s, char c);
int	check_err_types(t_cube *game);

#endif