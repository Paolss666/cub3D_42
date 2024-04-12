/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:50:56 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/11 12:04:12 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D2.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
// --------------------------------------------- POUR TESTER LA MAP --------------------------------------------
void	ft_clean_sl(char **result)
{
	int	nw;

	nw = 0;
	while (result[nw])
	{
		free(result[nw]);
		nw++;
	}
	free(result);
}

char	*ft_clean_gnl(char *line, char *result, int fd)
{
	while (line != NULL)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free (result);
	result = NULL;
	return (result);
}

// char	*ft_check_gnl(char *result, char *line, t_data *data, int fd)
// {
// 	char	*temp;
// 	int		i;

// 	temp = NULL;
// 	while (1)
// 	{
// 		if (!result)
// 			result = get_next_line(fd);
// 		if (!line)
// 			line = get_next_line(fd);
// 		if (line == NULL || result == NULL || i < 0))
// 		return ;
// 	if (map[x][y] == '0' && (x == 0 || y == 0 || x == data->col_x - 1 || y == data->lin_y - 1 || (map[x - 1]

char	*ft_ber_on_line(int fd, t_data *data)
{
	char	*line;
	char	*result;

	result = NULL;
	line = NULL;
	result = ft_check_gnl(result, line, data, fd);
	return (result);
}

int	ft_map_on_tab(int fd, t_data *data)
{
	char	*result;

	result = ft_ber_on_line(fd, data);
	if (!result)
		return (1);
	data->map = ft_split(result, '\n');
	data->check_map = ft_split(result, '\n');
	if (!data->map || !data->check_map)
	{
		if (data->map)
			ft_clean_sl(data->map);
		if (data->check_map)
			ft_clean_sl(data->check_map);
		return (1);
	}
	free (result);
	return (0);
}

// --------------------------------------------- POUR CHECKER LA MAP --------------------------------------------

//creer un boleen de comparaison de +ieurs caracteres

//bool multi_char_comp(char a, char b, char c)
//{}
//	if(a == b || a == c)
//		return TRUE;
//	return FALSE;
//}

void	ft_check_frontier(char **map, t_data *data, int x, int y)
{
	int a = 0;
	int b = 0;
	//int y = 0;
	printf("TEST : x = %d et y = %d\n", x, y);
	while (b < data->col_x)
	{
		printf("%s\n", map[b]);
		b++;
	}
	if (x < 0 || y < 0 || x == data->col_x || y == data->lin_y || map[x][y] == 'F' || data->not_valid == 1)
		return ;
	if (map[x][y] == '0' && (x == 0 || y == 0 || x == data->col_x - 1 || y == data->lin_y - 1 || (map[x - 1][y] == ' ' || map[x][y + 1] == ' ' || map[x][y - 1] == ' ' || map[x + 1][y] == ' ')))
	{
		data->not_valid = 1;
		return ;
	}
	else
	{
		//printf("TEST du else\n");
		if (map[x][y] != ' ')
			map[x][y] = 'F';
		//if (map[x][y] == ' ')
		//	map[x][y] = 'X';
		//ft_check_frontier(map, data, x - 1, y);
		ft_check_frontier(map, data, x, y + 1);
		ft_check_frontier(map, data, x + 1, y);
		//ft_check_frontier(map, data, x, y - 1);
	}
}

//void	ft_check_frontier(char **map, t_data *data, int x, int y)
//{
//	int a = 0;
//	int b = 0;
//	//int y = 0;
//	printf("TEST : x = %d et y = %d\n", x, y);
//	while (b < data->col_x)
//	{
//		printf("%s\n", map[b]);
//		b++;
//	}
//	if (x < 0 || y < 0 || x == data->col_x || y == data->lin_y || map[x][y] == '\0' || map[x][y] == 'F')
//		return ;
//	if ((map[x][y] == '1' && (x == 0 || y == 0 || x == data->col_x - 1 || y == data->lin_y - 1 || (map[x - 1][y] == ' ' || map[x][y + 1] == ' ' || map[x][y - 1] == ' ' || map[x + 1][y] == ' '))))
//	{
//		printf("TESTSEGFAULT\n");
//		map[x][y] = 'F';
//		printf("TESTSEGFAULT\n");		
//		if (x > 0 && map[x - 1][y] == 'F')
//			a++;
//		printf("TESTSEGFAULT\n");
//		if (y + 1 < data->lin_y && map[x][y + 1] == 'F')
//			a++;
//		printf("TESTSEGFAULT\n");
//		if (y > 0 && map[x][y - 1] == 'F')
//			a++;
//		printf("TESTSEGFAULT\n");
//		if (x + 1 < data->col_x && map[x + 1][y] == 'F')
//			a++;
//		printf("TESTSEGFAULT\n");
//		if (a == 2)
//		{
//			data->not_valid = 2;
//			return ;
//		}
//		printf("TESTSEGFAULT\n");
//		ft_check_frontier(map, data, x - 1, y);
//		ft_check_frontier(map, data, x, y + 1);
//		ft_check_frontier(map, data, x + 1, y);
//		ft_check_frontier(map, data, x, y - 1);
//	}
//}

int ft_check_char(t_data *data)
{
	int x = 0;
	int y = 0;

	while(1)
	{
		if (data->map[x][y] == '\0')
		{
			x++;
			if (x == data->col_x)
				break ;
			y = 0;
			continue ;
		}
		if (data->map[x][y] == 'N' || data->map[x][y] == 'E' || data->map[x][y] == 'S' || data->map[x][y] == 'W')
		{
			data->check_map[x][y] = '0'; //permet de voir apres si bien dans la map et pas dehors
			data->perso--;
		}
		else if (data->map[x][y] != '1' && data->map[x][y] != '0' && data->map[x][y] != ' ')
			return(write(1, "map not valid : char not valid on map\n", 39), 1);
		y++;
	}
	return 0;
}

int ft_check_map(t_data *data)
{
	data->perso = 1;
	data->not_valid = 0;
	printf("CECI EST UN TEST 2\n");
	if (ft_check_char(data) == 1 || data->perso < 0)
	{
		data->not_valid = 1;
		if (data->perso < 0)
			write(1, "map not valid : to much perso\n", 31);
		return 1;		
	}
	else
		write(1, "first check : map valid\n", 25);
	ft_check_frontier(data->check_map, data, 0, 0);
	if (data->not_valid == 0)
		write(1, "second check : map valid\n", 26);
	else 
		write(1, "second check : map not valid\n", 30);
	return 0;
}

//structure pour stoquer la place du perso
//1. ouvrir le fichier map et reperer si les infos demandees sont presentes : faire un tableau 
//avec des pointeurs sur fonction,qui vont check chaque element pour voir si c est conforme et stocker 
//dans la structure les infos souhaitees en donnant l adresse de la structure
//2. la map : check s'il y a bien qu un perso et qu il y a des murs tout autour de la map
//3. 


//structure : 
// NO
// SO
// WE
// EA
// F
// C
// ou est le perso + vu : x, y, vision
// la map


//Votre programme doit prendre en premier argument un fichier de description de
//scène avec pour extension .cub
//◦ La map doit être composée d’uniquement ces 6 caractères : 0 pour les espaces
//vides, 1 pour les murs, et N,S,E ou W qui représentent la position de départ
//du joueur et son orientation.
//Cette simple map doit être valide :
//111111222222
//1001011222222
//101000111111
//1100N1222222
//111111222222
//◦ La map doit être fermée/entourée de murs, sinon le programme doit renvoyer
//une erreur.
//◦ Mis à part la description de la map, chaque type d’élément peut être séparée
//par une ou plusieurs lignes vides.
//◦ La description de la carte sera toujours en dernier dans le fichier, le reste des
//éléments peut être dans n’importe quel ordre.
//◦ Sauf pour la map elle-même, les informations de chaque élément peuvent être
//séparées par un ou plusieurs espace(s).
//◦ La carte doit être parsée en accord avec ce qui est présenté dans le fichier. Les
//espaces sont une partie valable de la carte, c’est à vous de les gérer correcte-
//ment. Vous devez pouvoir parser n’importe quelle sorte de carte, tant qu’elle
//respecte les règles de carte.


//floodfill qui cheque les murs
//flood fill qui cheque le contenu



//void	ft_check_where_is_p(t_data *data)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (data->map[i][j] != 'N' || data->map[i][j] != 'S' || data->map[i][j] != 'E' || data->map[i][j] != 'W')
//	{
//		j++;
//		if (data->map[i][j] == '\0')
//		{
//			i++;
//			j = 0;
//		}
//	}
//	data->play_x = i;
//	data->play_y = j;
//}

//void	*ft_check_map(t_data *data)
//{
//	int	i;

//	i = ft_check_frontier(data);
//	if (i < 0)
//	{
//		ft_putstr_fd("Error\nWE'RE FREE THE WALL HAS FALLEN\n", 2);
//		ft_clean_sl(data->map);
//		ft_clean_sl(data->check_map);
//		return (NULL);
//	}
//	ft_ok_to_go_out(data);
//	if (data->count_exit != 0 || data->check_collect != 0)
//	{
//		ft_putstr_fd("Error\nOH NAAAAN I CAN T PLAY WITH MY TEAM :(\n", 2);
//		ft_clean_sl(data->map);
//		ft_clean_sl(data->check_map);
//		return (NULL);
//	}
//	ft_clean_sl(data->check_map);
//	return (data->map);
//}

////check les frontieres / mur + element + cree la map.
//char	**ft_map_on_tab(int fd, t_data *data)
//{
//	char	*result;

//	result = ft_ber_on_line(fd, data);
//	if (!result)
//		return (NULL);
//	if (ft_check_el_online(result, data) <= 0)
//	{
//		ft_putstr_fd("Error\nWTF WE NEED MORE/LESS STUFFS ON THIS CARD\n", 2);
//		return (free(result), NULL);
//	}
//	data->map = ft_split(result, '\n');
//	data->check_map = ft_split(result, '\n');
//	if (!data->map || !data->check_map)
//	{
//		if (data->map)
//			ft_clean_sl(data->map);
//		if (data->check_map)
//			ft_clean_sl(data->check_map);
//		return (NULL);
//	}
//	free (result);
//	data->map = ft_check_map(data);
//	if (data->map == NULL)
//		return (NULL);
//	return (data->map);
//}

//void	ft_ok_to_go_out(t_data *data)
//{
//	int		x;
//	int		y;
//	char	**map;

//	ft_check_where_is_p(data);
//	x = data->play_x;
//	y = data->play_y;
//	data->check_collect = data->to_collect;
//	data->count_exit = 1;
//	map = data->map;
//	ft_fill_map(data->check_map, data, x, y);
//}

////check les elements a collecter la sortie et la position perso
//int	ft_check_el_online(char *result, t_data *data)
//{
//	int	perso;
//	int	exit;
//	int	i;

//	data->to_collect = 0;
//	perso = 0;
//	exit = 0;
//	i = 0;
//	while (result[i] != '\0')
//	{
//		if (result[i] == 'P')
//			perso++;
//		else if (result[i] == 'E')
//			exit++;
//		else if (result[i] == 'C')
//			data->to_collect++;
//		else if (result[i] != '1' && result[i] != '0'
//			&& result[i] != '\n' && result[i] != 'Y')
//			return (-1);
//		i++;
//	}
//	if (perso == 1 && exit == 1 && data->to_collect >= 1)
//		return (data->to_collect);
//	return (-1);
//}
