/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_err_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:14:53 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/18 13:57:05 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


int	get_each_img_data(t_cube *game, t_img *img, int i)
{
	int	x;
	int	y;

	game->tex[i] = ft_calloc((game->tex_w * game->tex_h), sizeof(int));
	if (!game->tex[i] || ft_gbg(ADD, game->tex[i], EX))
        return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
	y = 0;
	while (y < game->tex_h)
	{
		x = 0;
		while (x < game->tex_w)
		{
			// printf("x = %d et i = %d t y = %d === \n", x, i, y);
			game->tex[i][y * game->tex_w + x] = img->full_buf[y * game->tex_w + x];
			// printf("x = %d\n", game->tex[i][y * game->tex_w + x]);
			x++;
		}
		y++;
	}
	return (0);
}

    // if (get_each_img_data(game, game->door, 4) != 0)
    //     return (-1);


int get_imgs_data_err(t_cube *game)
{
    game->tex = ft_calloc(5, sizeof(int *));
    if (!game->tex || ft_gbg(ADD, game->tex, EX))
        return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
    if (get_each_img_data(game, game->no, 0) != 0)
        return (-1);
    if (get_each_img_data(game, game->so, 1) != 0)
        return (-1);
    if (get_each_img_data(game, game->ea, 2) != 0)
        return (-1);
    if (get_each_img_data(game, game->we, 3) != 0)
        return (-1);
    return (0);
}

int	check_err_types_bis_color(t_cube *game)
{
	game->f = ft_parse_for_color(game->type[4]);
	if (!game->f)
		return (-1);
	printf("game->f %d\n", *game->f);
	game->c = ft_parse_for_color(game->type[5]);
	printf("game->c %d\n", *game->c);
	if (!game->c)
		return (-1);
	return (0);
}


// game->door = xpm_img(game, "./img/door.xpm", 64, 64);
// if (!game->door)
// 	return (-1);

/* supprimer NO SE merde */

int	check_err_types(t_cube *game)
{
	// printf("game->type[0] %s\n", game->type[0]);
	// printf("game->type[1] %s\n", game->type[1]);
	// printf("game->type[2] %s\n", game->type[2]);
	// printf("game->type[3] %s\n", game->type[3]);
	printf("game->type[3] %s\n", game->type[4]);
	printf("game->type[3] %s\n", game->type[5]);
	game->no = xpm_img(game, (game->type[0] + 3), 64, 64);
	// game->no = xpm_img(game, ft_substr(game->type[0], 3, ft_strlen(game->type[0])), 64, 64);
	if (!game->no)
		return (-1);
	game->so = xpm_img(game, (game->type[1] + 3), 64, 64);
	// game->so = xpm_img(game, ft_substr(game->type[1], 3, ft_strlen(game->type[1])), 64, 64);
	if (!game->so)
		return (-1);
	game->we = xpm_img(game, (game->type[2] + 3), 64, 64);
	// game->we = xpm_img(game, ft_substr(game->type[2], 3, ft_strlen(game->type[2])), 64, 64);
	if (!game->we)
		return (-1);
	game->ea = xpm_img(game, (game->type[3] + 3), 64, 64);
	// game->no = xpm_img(game, ft_substr(game->type[0], 3, ft_strlen(game->type[0])), 64, 64);
	if (!game->ea)
		return (-1);
	if (get_imgs_data_err(game) != 0)
		return (-1);
	// printf("floor >%s<\n", (game->type[4] + 2));
	// printf("c >%s<\n", (game->type[5] + 2));
	// printf("check_ %d\n", check_chars((game->type[4] + 2), ','));
	if (check_chars((game->type[4] + 2), ',') != 2
		||  check_chars((game->type[5] + 2), ',') != 2)
		return (ft_putstr_fd("ERROR\nInvalid type of format\n", 2), -1);
	return (check_err_types_bis_color(game));
}
