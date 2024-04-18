/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:03:38 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/18 14:49:48 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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


int	check_file_open(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror("Wrong extension");
		return (-1);
	}
	if (check_if_exection(av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Open failed\n", 2);
		return (-1);
	}
	return (fd);
}

/* * get_types
 * La fonction récupérera les 6 premiers char* non vides qui 
 *   correspondent aux 6 types attendus.
 * Dans le processus de recherche des 6 char*, nous suivons le 
 *   nombre de lignes lues dans game->rows.
 * En cas de succès (= nous avons obtenu 6 char*), le descripteur 
 *   de fichier (fd) est retourné, de sorte que le début de la 
 *   lecture reste en place.
 * Sinon (= tous les 6 types n'ont pas été trouvés), -1 est retourné. */

int	get_types(t_cube *game, char **av)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed"), -1);
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line || ft_gbg(ADD, line, PARS))
			break ;
		if (!(ft_strlen(line) == 1 && !ft_strncmp(line, "\n", 1)))
			game->type[count++] = line;
		else
			ft_gbg(FREE, line, PARS);
		game->rows++;
	}
	if (count == 6)
		return (fd);
	else
		return (close(fd),
				ft_putstr_fd("Error\nInvalid numbers of types\n", 2), -1);
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

int	get_map(t_cube *game, int fd, char **av)
{
	int	rows;

	rows = game->rows;
	game->rows = 0;
	ft_count_rows(game, fd, &rows);
	if (game->rows <= 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), -1);
	game->map = ft_calloc(game->rows + 2, sizeof(char *));
	if (!game->map || ft_gbg(ADD, game->map, PARS))
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	cpy_map_from_file(game, av, rows);
	return (0);
}

/*
 * count_rows
 * rows = numero di righe dall'inizio del file fino alla prima
 * 	riga della mappa
 * game->rows: numero di righe della mappa
 * La test di lettura è già posizionata dopo il char* 'types'; dobbiamo
 * 	attraversare tutte le righe vuote fino a raggiungere la prima riga
 * 	della mappa e incrementare rows ogni volta
 * Una volta raggiunta una riga non vuota, significa che è la prima riga
 * 	della mappa; quindi contiamo tutte le righe della mappa, incrementando
 * 	game->rows
 */ 

void	ft_count_rows(t_cube *game, int fd, int *rows)
{
	char	*line;
	int		ln;

	ln = 1;
	while (ln)
	{
		line = get_next_line(fd);
		if (!line || ft_gbg(ADD, line, PARS))
			break ;
		is_newline(line, &ln, rows);
	}
	if (line)
	{
		game->rows++;
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			free(line);
			game->rows++;
		}
	}
	(get_next_line(fd), close(fd));
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

int cpy_map_from_file(t_cube *game, char **argv, int rows)
{
	int		fd;
	int		i;
	char	*line;

	i = game->rows + 1;
	fd = open(argv[1], O_RDONLY);
	game->line = 0;
	if (fd < 0)
		return (perror("open failed"), -1);
	while (rows > 0)
	{
		line = get_next_line(fd);
		free(line);
		rows--;
	}
	while (i > 0)
	{
		game->map[game->line] = get_next_line(fd);
		ft_gbg(ADD, game->map[game->line], PARS);
		i--;
		game->line++;
	}
	(get_next_line(fd), close(fd));
	return (0);
}


/*
 * sort_content
 * Calls get_types: we want exactly 6 types so we open the file
 * 	and get the 6 first non-empty char* ; the fd is returned
 * 	so that we can read what's next (the map)
 * Calls get_map: the first is alread_y open and the head for read is
 * 	stopped after the 6 types ; we then get all the rows that come
 * 	after, which correspond supposedly to the map
 */

int	sort_content(t_cube *game, char **av)
{
	int	fd;

	game->type = ft_calloc(7, sizeof(char *));
	if (!game->type || ft_gbg(ADD, game->type, PARS))
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	fd = get_types(game, av);
	delete_types_nl(game);
	if (fd < 0)
		return (-1);
	if (get_map(game, fd, av) == -1)
		return (-1);
	// print_map(game->map);
	return (0);
}

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
		return(1);
	if (ft_check_map(game) == 1)
		return (1);
	return (0);
}
