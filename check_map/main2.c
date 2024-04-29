/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:32:38 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/29 10:02:24 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D2.h"

//int	main(int argc, char **argv)
//{
//	int		i;
//	int		fd;
//	t_game	*game;

//	if (argc == 2)
//	{
//		fd = 0;
//		fd = open(argv[1], fd);
//	}
//	else
//	{
//		ft_putstr_fd("Error\nNo Card Or Too Much Card\n", 2);
//		return (1);
//	}
//	i = 0;
//	printf("CECI EST UN TEST\n");
//	ft_check_map(game);
//	//printf("%s\n",game->map[1]);
//	return (0);
//}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

void	init_game(t_cube *game)
{
	game->img = NULL;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->rows = 0;
	game->type = NULL;
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
	//get_file_content(game, av);

	//found_redif_type(game);
	// printf("===================================\n");
	//print_map(game->type);
	//check_err_types(game);
	printf("TESTCHECKMAP\n");
	printf("rowz = %d\n",game->rows);
	printf("line = %d\n",game->line);
	printf("map ligne 1 = %s\n", game->map[1]);
	ft_check_map(game);
	return (ft_gbg(FLUSH, NULL, ALL), 0);
}