/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/29 12:23:32 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
#define cub3D_H

# include "./libft/libft.h"
# include "mlx_linux/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "X11/X.h"
# include "X11/keysym.h"

# define SCREEN_W  480
# define MLX_ERROR 1
# define SPEED 0.05

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
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*no;
	t_img			*so;
	t_img			*ea;
	t_img			*we;
	t_img			*door;
	t_img			*spr;
	// t_anim			*anim;
	int				anim_flag;
	int				*f;
	int				*c;
	int				line;
	int				l;
	unsigned int	f_color;
	unsigned int	c_color;
	char			**map;
	char			**map_game;
	char			**type;
	int				rows;
	int				crow;
	int				cols;
	unsigned int	**buf;
	t_img			*img;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_q;
	int				key_e;

	int				screen_w;
	int				screen_h;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;

	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;

	int				line_height;
	int				pitch;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;

	double			move_speed;

	double			olddir_x;
	double			oldplane_x;

	int				tex_w;
	int				tex_h;
	int				nb_tex;
	unsigned int	**tex;

	// t_sprite		*sprite;
	int				num_sprites;
	double			z_buffer[SCREEN_W];
	int				*sprite_order;
	double			*sprite_distance;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				stripe;
	int				draw_start_y;
	int				draw_start_x;
	int				draw_end_y;
	int				draw_end_x;
	int				vmove_screen;

	double			p_x;
	double			p_y;
	int				col_perso;
	int				col_wall;
	int				col_door;
	int				col_floor;
	int				col_anim;
	int				x_mmap;
	int				y_mmap;
	int				box_size;

	int				m_y;
	int				m_x;
	int				d_y;
	int				d_x;

	int				click;
}               t_cube;

int				tab_size(char **tab);
void			print_map(char **map);

char			**ft_split_gbg(char const *s, char c);
int				check_file_open(char **av);
int				get_types(t_cube *game, char **av);
int				cpy_map_from_file(t_cube *game, char **argv, int rows);
void			ft_count_rows(t_cube *game, int fd, int *rows);
int				get_map(t_cube *game, int fd, char **av);
int				is_wspc_excl_nl(char c);
void			swap_ptrs(char **s1, char **s2);
int				check_types(char **new);
int				ptr_to_swap(char *s);
int				search_type(char *type, char **new);
int				reorder_new(char **new);
int				found_redif_type(t_cube *game, int fd);
int				get_file_content(t_cube *game, char **av);
t_img			*xpm_img(t_cube *game, char *img_path, int w, int h);
int     		get_color(int *tab_c);
int				*ft_parse_for_color(char *identi, t_cube *game);
int				check_chars(char *s, char c);
int				check_err_types(t_cube *game);
void			init_mlx(t_cube *game);
int				init_buf(t_cube *game);
int				get_imgs_data_err(t_cube *game);
void			get_pos(t_cube *game);
int				esc_close(int key, t_cube *game);
int				close_win(t_cube *game);
void			draw(t_cube *game);
int     		get_color(int *tab_c);
unsigned int	get_pixel_img(t_img src, int x, int y);
void			put_pixel_img_anims(t_img dst, int x, int y, int color);
int				display(t_cube *game, int x);
void			texture(t_cube *game, int x);
int				handle_no_event(t_cube *game);
int				handle_keyrelease(int keysym, t_cube *game);
// int				handle_keypress(int keysym, t_cube *game);
int				handle_keypress(int keysym, t_cube *game);

// --------------- CLEAR -------------------------- // 
void	clear_wrong_text(t_cube *game);

// ---------------- MOVE ------------------------- // 
void	move_up(t_cube *game);
void	move_down(t_cube *game);
void	move_left(t_cube *game);
void	move_right(t_cube *game);
void    m_rotate_right(t_cube *game, float move_speed);
void    m_rotate_left(t_cube *game, float move_speed);

// ----------------- check map --------------------- // 

void	ft_add_space(t_cube *game);
int		ft_countrows(t_cube *game);
int		ft_countline(t_cube *game);
void	ft_stock_map(t_cube *game);
bool	is_perso(char **map, int x, int y);
void	ft_check_frontier(t_cube *game, int x, int y);
int		ft_check_char(t_cube *game, int x, int y);
void	ft_add_wall(t_cube *game);
int		ft_check_map(t_cube *game);
void	ft_print_maperror(t_cube *game, char **map, int x, int y); //a supprimer

// ------------------------minimap ---------------------- //
int ft_put_minimap(t_cube *game);
#endif