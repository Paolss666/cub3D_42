/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/04 13:57:13 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void	print_map(char **map)
{
	int i = 0;
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
	t_cube	*game = NULL;
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
	// if ( fd == -1)
	// 	return (ft_putstr_fd("Not valide\n", 2), 1);
	// while(1)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s\n", line);
	// 	if (!line)
	// 		break ;
	// }
	// if (get_types(game, av) == - 1)
		// return (printf("FAIL\n"));
	// fd = 0;
	get_map(game, fd, av);
	print_map(game->map);
	return (ft_gbg(FLUSH, NULL, ALL), 0);
}
