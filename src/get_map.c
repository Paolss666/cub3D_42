/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:03:38 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/06 16:52:46 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
* get_types
* La fonction récupérera les 6 premiers char* non vides qui 
*   correspondent aux 6 types attendus.
* Dans le processus de recherche des 6 char*, nous suivons le 
*   nombre de lignes lues dans game->rows.
* En cas de succès (= nous avons obtenu 6 char*), le descripteur 
*   de fichier (fd) est retourné, de sorte que le début de la 
*   lecture reste en place.
* Sinon (= tous les 6 types n'ont pas été trouvés), -1 est retourné.
*/

int	get_types(t_cube *game, int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd, 0);
		if (!line || ft_gbg(ADD, line, PARS))
		{
			get_next_line(fd, 1);
			break ;
		}
		if (!(ft_strlen(line) == 1 && !ft_strncmp(line, "\n", 1)))
			game->type[count++] = line;
		else
			ft_gbg(FREE, line, PARS);
		game->rows++;
	}
	if (count == 6)
		return (fd);
	else
		return (ft_putstr_fd("Error\nInvalid numbers of types\n", 2),
			close(fd), clear_wrong_text(game), -1);
}

int	get_map(t_cube *game, int fd, char **av)
{
	int	rows;

	rows = game->rows;
	game->rows = 0;
	ft_count_rows(game, fd, &rows);
	if (game->rows <= 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2),
			ft_gbg(FLUSH, NULL, ALL), -1);
	game->map = ft_calloc(game->rows + 2, sizeof(char *));
	if (!game->map || ft_gbg(ADD, game->map, PARS))
		return (ft_putstr_fd("Bad malloc\n", 2), ft_gbg(FLUSH, NULL, ALL),
			clear_wrong_text(game), -1);
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
		line = get_next_line(fd, 0);
		if (!line || ft_gbg(ADD, line, PARS))
			break ;
		is_newline(line, &ln, rows);
	}
	if (line)
	{
		game->rows++;
		while (1)
		{
			line = get_next_line(fd, 0);
			if (!line)
				break ;
			free(line);
			game->rows++;
		}
	}
	(get_next_line(fd, 0), close(fd));
}

int	cpy_map_from_file(t_cube *game, char **argv, int rows)
{
	int		fd;
	int		i;
	char	*line;

	i = game->rows + 1;
	game->line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed"), -1);
	while (rows > 0)
	{
		line = get_next_line(fd, 0);
		free(line);
		rows--;
	}
	while (i > 0)
	{
		game->map[game->line] = get_next_line(fd, 0);
		ft_gbg(ADD, game->map[game->line], PARS);
		i--;
		game->line++;
	}
	(get_next_line(fd, 0), close(fd));
	return (0);
}

/*
 * 	sort_content
 * 	Calls get_types: we want exactly 6 types so we open the file
 * 	and get the 6 first non-empty char* ; the fd is returned
 * 	so that we can read what's next (the map)
 * 	Calls get_map: the first is alread_y open and the head for read is
 * 	stopped after the 6 types ; we then get all the rows that come
 * 	after, which correspond supposedly to the map
*/

int	sort_content(t_cube *game, char **av)
{
	int	fd;

	game->type = ft_calloc(7, sizeof(char **));
	if (!game->type || ft_gbg(ADD, game->type, PARS))
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed"), -1);
	fd = get_types(game, fd);
	if (found_redif_type(game, fd) != 0)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
	delete_types_nl(game);
	if (get_map(game, fd, av) == -1)
		return (-1);
	if (check_if_in_nl_map(game) == -1)
		return (ft_putstr_fd("Error\nNew_line in map\n", 2),
			clear_wrong_text(game), -1);
	return (0);
}
