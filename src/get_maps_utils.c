/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:13:54 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/17 00:10:13 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_if_in_nl_map(t_cube *game)
{
	int		y;

	y = 0;
	if (!game->map)
		return (-1);
	while (game->map[y])
	{
		if (!ft_strcmp(game->map[y], "\n"))
			return (-1);
		y++;
	}
	return (0);
}

/*
 * delete_types_nl
 * Removes the useless '\n' at the end of the types char*
*/

void	delete_types_nl(t_cube *game)
{
	int	i;

	i = 0;
	while (game->type[i])
	{
		if (game->type[i][ft_strlen(game->type[i]) - 1] == '\n')
			game->type[i][ft_strlen(game->type[i]) - 1] = '\0';
		i++;
	}
}

/* check if the exection file is .cub */

int	check_if_exection(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i--] != 'b')
		return (1);
	if (av[1][i--] != 'u')
		return (1);
	if (av[1][i--] != 'c')
		return (1);
	if (av[1][i--] != '.')
		return (1);
	return (0);
}

/*
* is_newline
* Utils for count_rows, it compares the line content to "\n" to see
* 	if the line is just an empty newline or not ; it updates the
* 	int ln and int rows accordingly
*/

void	is_newline(char *line, int *ln, int *rows)
{
	if (ft_strlen(line) == 0)
	{
		*ln = 0;
		ft_gbg(FREE, line, PARS);
	}
	else if ((ft_strlen(line) == 1) && !ft_strncmp(line, "\n", 1))
	{
		*ln = 1;
		*rows += 1;
		ft_gbg(FREE, line, PARS);
	}
	else
		*ln = 0;
}

int	check_file_open(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror("Open failed");
		return (-1);
	}
	if (check_if_exection(av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong extension\n", 2);
		return (-1);
	}
	return (fd);
}
