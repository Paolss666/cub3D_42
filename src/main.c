/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/11 16:38:46 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


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
	get_file_content(game, av);
	init_buf(game);
	init_mlx(game);
	// get_imgs_data_err(game);
	// print_map(game->map);
	found_redif_type(game);
	// printf("===================================\n");
	print_map(game->type);
	check_err_types(game);
	return (/* ft_gbg(FLUSH, NULL, ALL),  */0);
}
