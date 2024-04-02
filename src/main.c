/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/02 16:40:51 by npaolett         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_cube	*game = NULL;
	int		fd;
	// char	*line = NULL;

	// (void)av;
	game = (t_cube *)malloc(sizeof(t_cube));
	if (!game || ft_gbg(ADD, game, PARS))
		return (-1);
	if (ac != 2)
		return (ft_gbg(FLUSH, NULL, ALL),ft_putstr_fd("Bad numbers of arguments\n", 2), 1);
	// game = init_play();
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
	// game->rows = ft_count_rows(game, fd, );
	// cpy_map_from_file(game, av, game->rows);
	return (ft_gbg(FLUSH, NULL, ALL), 0);
}
