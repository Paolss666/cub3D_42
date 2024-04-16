/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/16 16:04:21 by npaolett         ###   ########.fr       */
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
	game->screen_w = 640;
	game->screen_h = 480;
	game->rows = 0;
	game->tex_w = 64;
	game->tex_h = 64;
	game->nb_tex = 5;
	game->move_speed = 0.05;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->key_q = 0;
	game->key_e = 0;
}




void	init_loop(t_cube *game)
{
	mlx_hook(game->win_ptr, 2,  KeyPressMask, &esc_close, game);
	mlx_hook(game->win_ptr, 17, KeyPressMask, &close_win, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
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
		// check_err_types(game);
// VAZY MA GEUELE
	// get_map(game,fd,  av);
	// ft_check_map(game);
	// print_map(game->map_game);	
	// print_map(game->map);
	if (get_file_content(game, av) == 1)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), 1);
	init_mlx(game);
	get_pos(game);
	printf("%f\n", game->pos_x);
	printf("%f\n", game->pos_y);
	printf("%f\n", game->dir_x);
	printf("%f\n", game->dir_y);
	printf("%f\n", game->plane_x);
	printf("%f\n", game->plane_y);
	// display(game, 0);
	init_loop(game);
	// printf("===================================\n");
	// mlx_loop(game->mlx_ptr);
	// ERROR TYPES ----////////
	return (0);
}
