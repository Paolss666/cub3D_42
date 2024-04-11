/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:50:56 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/10 17:49:00 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D2.h"
//#include "../cub3D.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// --------------------------------------------- POUR CHECKER LA MAP --------------------------------------------

//creer un boleen de comparaison de +ieurs caracteres

//bool multi_char_comp(char a, char b, char c)
//{}
//	if(a == b || a == c)
//		return TRUE;
//	return FALSE;
//}

int		ft_countrows(t_cube *game)
{
	int i;

	i = 0;
	while (game->map && game->map[0][i])
		i++;
	return (i);
}

int		ft_countline(t_cube *game)
{
	int i;

	i = 0;
	while(game->map && game->map[i])
		i++;
	return(j);
}

void	ft_check_frontier(t_cube *game, t_checkmap *checkmap, int x, int y)
{
	//int a = 0;
	int b = 0;
	//int y = 0;
	char **map;
	map = game->map;
	printf("TEST : x = %d et y = %d\n", x, y);
	while (b < game->line)
	{
		printf("%s\n", map[b]);
		b++;
	}
	if (x < 0 || y < 0 || x == game->line || y == game->line || map[x][y] == 'F' || checkmap->not_valid == 1)
		return ;
	if (map[x][y] == '0' && (x == 0 || y == 0 || x == game->line - 1 || y == game->rows - 1 || (map[x - 1][y] == ' ' || map[x][y + 1] == ' ' || map[x][y - 1] == ' ' || map[x + 1][y] == ' ')))
	{
		checkmap->not_valid = 1;
		return ;
	}
	else
	{
		if (map[x][y] != ' ')
			map[x][y] = 'F';
		//if (map[x][y] == ' ')
		//	map[x][y] = 'X';
		//ft_check_frontier(map, game, x - 1, y);
		ft_check_frontier(game, checkmap, x, y + 1);
		ft_check_frontier(game, checkmap, x + 1, y);
		//ft_check_frontier(map, game, x, y - 1);
	}
}

int ft_check_char(t_cube *game, t_checkmap *checkmap)
{
	int x = 0;
	int y = 0;

	while(1)
	{
		if (game->map[x][y] == '\0')
		{
		printf("CECI EST UN TEST 2.1\n");			
			x++;
			if (x == game->rows)
				break ;
			y = 0;
			continue ;
		}
		if (game->map[x][y] == 'N' || game->map[x][y] == 'E' || game->map[x][y] == 'S' || game->map[x][y] == 'W')
		{
			checkmap->check_map[x][y] = '0'; //permet de voir apres si bien dans la map et pas dehors
			checkmap->perso--;
		}
		else if (game->map[x][y] != '1' && game->map[x][y] != '0' && game->map[x][y] != ' ')
			return(write(1, "map not valid : char not valid on map\n", 39), 1);
		y++;
	}
	return 0;
}

int ft_check_map(t_cube *game)
{
	t_checkmap *checkmap;

	printf("rowz = %d\n",game->rows);
	printf("line = %d\n",game->line);

	game->rows = ft_countrows(game);
	
	game->line = ft_countline(game);
	printf("rowz = %d\n",game->rows);
	printf("line = %d\n",game->line);
	checkmap = (t_checkmap *)malloc(sizeof(t_checkmap));
	//checkmap->check_map = malloc
	//a proteger
	printf("CECI EST UN TEST 0\n");
	checkmap->perso = 1;
	printf("CECI EST UN TEST 0.1\n");
	checkmap->not_valid = 0;
	printf("CECI EST UN TEST 1\n");
	checkmap->check_map = game->map;
	printf("CECI EST UN TEST 2\n");
	if (ft_check_char(game, checkmap) == 1 || checkmap->perso < 0)
	{
		printf("CECI EST UN TEST 3\n");
		checkmap->not_valid = 1;
		if (checkmap->perso < 0)
			write(1, "map not valid : to much perso\n", 31);
		//free checkmap
		return 1;		
	}
	else
		write(1, "first check : map valid\n", 25);
	ft_check_frontier(game, checkmap, 0, 0);
	if (checkmap->not_valid == 0)
		write(1, "second check : map valid\n", 26);
	else 
		write(1, "second check : map not valid\n", 30);
	//free checkmap
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



//void	ft_check_where_is_p(t_game *game)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (game->map[i][j] != 'N' || game->map[i][j] != 'S' || game->map[i][j] != 'E' || game->map[i][j] != 'W')
//	{
//		j++;
//		if (game->map[i][j] == '\0')
//		{
//			i++;
//			j = 0;
//		}
//	}
//	game->play_x = i;
//	game->play_y = j;
//}

//void	*ft_check_map(t_game *game)
//{
//	int	i;

//	i = ft_check_frontier(game);
//	if (i < 0)
//	{
//		ft_putstr_fd("Error\nWE'RE FREE THE WALL HAS FALLEN\n", 2);
//		ft_clean_sl(game->map);
//		ft_clean_sl(game->check_map);
//		return (NULL);
//	}
//	ft_ok_to_go_out(game);
//	if (game->count_exit != 0 || game->check_collect != 0)
//	{
//		ft_putstr_fd("Error\nOH NAAAAN I CAN T PLAY WITH MY TEAM :(\n", 2);
//		ft_clean_sl(game->map);
//		ft_clean_sl(game->check_map);
//		return (NULL);
//	}
//	ft_clean_sl(game->check_map);
//	return (game->map);
//}

////check les frontieres / mur + element + cree la map.
//char	**ft_map_on_tab(int fd, t_game *game)
//{
//	char	*result;

//	result = ft_ber_on_line(fd, game);
//	if (!result)
//		return (NULL);
//	if (ft_check_el_online(result, game) <= 0)
//	{
//		ft_putstr_fd("Error\nWTF WE NEED MORE/LESS STUFFS ON THIS CARD\n", 2);
//		return (free(result), NULL);
//	}
//	game->map = ft_split(result, '\n');
//	game->check_map = ft_split(result, '\n');
//	if (!game->map || !game->check_map)
//	{
//		if (game->map)
//			ft_clean_sl(game->map);
//		if (game->check_map)
//			ft_clean_sl(game->check_map);
//		return (NULL);
//	}
//	free (result);
//	game->map = ft_check_map(game);
//	if (game->map == NULL)
//		return (NULL);
//	return (game->map);
//}

//void	ft_ok_to_go_out(t_game *game)
//{
//	int		x;
//	int		y;
//	char	**map;

//	ft_check_where_is_p(game);
//	x = game->plgame
//	game->to_collect = 0;
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
//			game->to_collect++;
//		else if (result[i] != '1' && result[i] != '0'
//			&& result[i] != '\n' && result[i] != 'Y')
//			return (-1);
//		i++;
//	}
//	if (perso == 1 && exit == 1 && game->to_collect >= 1)
//		return (game->to_collect);
//	return (-1);
//}
