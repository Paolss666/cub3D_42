/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/15 17:07:55 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* 
	// game->nb_tex = 5;
	// game->move_speed = 0.01;
	// game->key_w = 0;
	// game->key_s = 0;
	// game->key_a = 0;
	// game->key_d = 0;
	// game->key_left = 0;
	// game->key_right = 0;
	// game->key_q = 0;
	// game->key_e = 0;
 */

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

void	init_game(t_cube *game)
{
	game->img = NULL;
	game->map = NULL;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr || ft_gbg(ADD, game->mlx_ptr, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	game->rows = 0;
	game->win_ptr = NULL;
	game->type = NULL;
	game->buf = NULL;
	game->screen_w = 640;
	game->screen_h = 480;
	game->tex_w = 64;
	game->tex_h = 64;
	game->anim_flag = 0;
	game->f = 0;
	game->c = 0;
	game->line = 0;
	game->f_color = 0;
	game->c_color  = 0;
	game->cols = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_s = 0;
	game->key_w = 0;
	game->key_right = 0;
	game->key_left = 0;
	game->key_q = 0;
	game->key_e = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0 ;
	game->plane_y = 0 ;
	game->camera_x = 0;
	game->raydir_x = 0;
	game->raydir_y = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->side_dist_x = 0;
	game->side_dist_y = 0;
	game->delta_dist_x = 0;
	game->delta_dist_y = 0;
	game->perp_wall_dist = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->hit = 0;
	game->side = 0;
	game->line_height = 0;
	game->pitch = 0;
	game->draw_start = 0;
	game->draw_end = 0;
	game->tex_num = 0;
	game->wall_x = 0;
	game->tex_x = 0;
	game->tex_y = 0;
	game->step = 0;
	game->tex_pos = 0;
}




void	init_loop(t_cube *game)
{
	mlx_hook(game->win_ptr, 2,  KeyPressMask, &esc_close, game);
	mlx_hook(game->win_ptr, 17, KeyPressMask, &close_win, game);
	// mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	// mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		// &handle_keyrelease, game);
	// mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	// mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_cube	*game;
	int		fd;

	game = (t_cube *)malloc(sizeof(t_cube));
	if (!game || ft_gbg(ADD, game, PARS))
		return (-1);
	if (ac != 2)
		return (ft_gbg(FLUSH, NULL, ALL),
			ft_putstr_fd("Bad numbers of arguments\n", 2), 1);
	init_game(game);
	fd = check_file_open(av);
	if (fd == -1)
		return (ft_gbg(FLUSH, NULL, ALL), 1);
	get_map(game, fd, av);
		// check_err_types(game);
	get_file_content(game, av);
	init_mlx(game);
	init_buf(game);
	found_redif_type(game);
	get_pos(game);
	display(game, 0);
	init_loop(game);
	// printf("===================================\n");
	// mlx_loop(game->mlx_ptr);
	// ERROR TYPES ----////////
	return (0);
}
