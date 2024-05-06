/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_err_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:14:53 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/06 17:38:31 by elcesped         ###   ########.fr       */
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
			game->tex[i][y * game->tex_w + x] = img->full_buf[y * game->tex_w + x];
			x++;
		}
		y++;
	}
	return (0);
}

	// if (get_each_img_data(game, game->door, 4)!= 0)
    //     return (-1);

int get_imgs_data_err(t_cube *game)
{
	game->tex = ft_calloc(6, sizeof(int *));
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
	if (get_each_img_data(game, game->sprite1, 4) != 0)
		return (-1);
	if (get_each_img_data(game, game->sprite2, 5) != 0)
		return (-1);
	//if (get_each_img_data_sprite(game, game->sprite1, 4) != 0)
	//	return (-1);
		
	return (0);
}

int	check_err_types_bis_color(t_cube *game)
{
	game->f = ft_parse_for_color(game->type[4], game);
	if (!game->f)
		return (-1);	
	game->c = ft_parse_for_color(game->type[5], game);
	if (!game->c)
		return (-1);
	return (0);
}


// game->door = xpm_img(game, "./img/door.xpm", 64, 64);
// if (!game->door)
// 	return (-1);

int	check_err_types(t_cube *game)
{
	game->no = xpm_img(game, game->type[0], 64, 64);
	if (!game->no)
		return (-1);
	game->so = xpm_img(game, game->type[1], 64, 64);
	if (!game->so)
		return (-1);
	game->we = xpm_img(game, game->type[2], 64, 64);
	if (!game->we)
		return (-1);
	game->ea = xpm_img(game, game->type[3], 64, 64);
	if (!game->ea)
		return (-1);
	game->sprite1 = xpm_img(game, "./img/lescopinessprite/lee.xpm", 64, 64);
	if (!game->sprite1)
		return (-1);
	game->sprite2 = xpm_img(game, "./img/lescopinessprite/neige_1.xpm", 64, 64);
	if (!game->sprite2)
		return (-1);
	if (get_imgs_data_err(game) != 0)
		return (ft_gbg(FLUSH, NULL, ALL),exit(99),-1);
	if (check_chars((game->type[4] + 2), ',') != 2
		|| check_chars((game->type[5] + 2), ',') != 2)
		return (ft_putstr_fd("Error\nInvalid type of format\n", 2),
			clear_wrong_text(game), -1);
	return (check_err_types_bis_color(game));
}
