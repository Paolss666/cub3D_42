/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/06 15:26:02 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * get_map:
 * First, checks errors related to the source file of the map
 * Second, sorts the file content: split the types from the map
 * 
*/

int	get_file_content(t_cube *game, char **av)
{
	if (!av || !av[1])
		return (1);
	if (check_file_open(av) == -1)
		return (1);
	if (sort_content(game, av) == -1)
		return (1);
	if (check_err_types(game) == -1)
		return (1);
	if (ft_check_map(game) == 1)
		return (1);
	return (0);
}

void	init_game_b(t_cube *game)
{
	game->door = NULL;
	game->p_minimap = 0;
	game->click = -1;
}

void	init_game(t_cube *game)
{
	game->img = NULL;
	game->map = NULL;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr || ft_gbg(ADD, game->mlx_ptr, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
	game->screen_w = 640;
	game->screen_h = 480;
	game->rows = 0;
	game->tex_w = 64;
	game->tex_h = 64;
	game->nb_tex = 5;
	game->move_speed = 0.01;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->key_q = 0;
	game->key_e = 0;
	game->ea = NULL;
	game->so = NULL;
	game->no = NULL;
	game->we = NULL;
	init_game_b(game);
}


void	init_loop(t_cube *game)
{
	mlx_mouse_move(game->mlx_ptr, game->win_ptr,
		game->screen_w / 2, game->screen_h / 2);
	mlx_mouse_hook(game->win_ptr, mouse_but, game);
	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, mouse_mov, game);
	// mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	mlx_hook(game->win_ptr, 2, KeyPressMask, &esc_close, game);
	mlx_hook(game->win_ptr, 17, NoEventMask, &close_win, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
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
	fd = check_file_open(av);
	if (fd == -1)
		return (ft_gbg(FLUSH, NULL, ALL), 1);
	init_game(game);
	if (get_file_content(game, av) == 1)
		return (get_next_line(fd, 1), ft_gbg(FLUSH, NULL, ALL), exit(99), 1);
	init_mlx(game);
	get_pos(game);
	display(game, 0);
	init_loop(game);
	return (0);
}
