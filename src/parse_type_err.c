/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:59:57 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/18 14:44:03 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_chars(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == ',') && !(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	get_nb(char *color)
{
	int	n;
	int	i;

	i = 0;
	while (color[i] && color[i] != '\n')
	{
		if (!(color[i] >= '0' && color[i] <= '9'))
			return (ft_putstr_fd("Error\nBad RGB color\n", 2), -1);
		i++;
	}
	color[i] = '\0';
	n = ft_atoi(color);
	if (n < 0 || n > 255)
		return (ft_putstr_fd("Error\nBad RGB color\n", 2), -1);
	return (n);
}

t_img	*xpm_img(t_cube *game, char *img_path, int w, int h)
{
	t_img	*new_img;

	new_img = (t_img *)malloc(sizeof(t_img));
	if (!new_img || ft_gbg(ADD, new_img, EX))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), NULL);
	new_img->h = h;
	new_img->w = w;
	new_img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			img_path, &(new_img->w), &(new_img->h));
	if (!new_img->img_ptr)
		return (ft_putstr_fd("Error\nwrong texture path\n", 2),
			ft_gbg(FREE, new_img, EX), exit(99), NULL);
	new_img->full_buf = (int *)mlx_get_data_addr(game->mlx_ptr,
			&new_img->bpp, &new_img->line_len,
			&new_img->endian);
	if (!new_img->full_buf)
	{
		mlx_destroy_image(game->mlx_ptr, new_img->img_ptr);
		new_img->img_ptr = NULL;
		return (ft_putstr_fd("Error\nBad xpm adress\n", 2), NULL);
	}
	return (new_img);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}


char	*crt_color_parse(char *color)
{
	char	*parse_color;

	parse_color = ft_substr(color, 2, ft_strlen(color));
	if (!parse_color || ft_gbg(ADD, parse_color, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), NULL);
	return (parse_color);
}

int	*ft_parse_for_color(char *identi)
{
	int		*rgb;
	char	**colours;

	colours = NULL;
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb || ft_gbg(ADD, rgb, EX))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), NULL);
	colours = ft_split_gbg(identi, ',');
	if (!colours)
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), NULL);
	if (tab_size(colours) != 3)
		return (ft_putstr_fd("Error\nWrong colours\n", 2), ft_gbg(FLUSH, NULL,
				ALL), exit(0), NULL);
	rgb[0] = get_nb(crt_color_parse(colours[0]));
	if (rgb[0] == -1)
		return (ft_free_tab(colours), ft_gbg(FREE, rgb, EX), NULL);
	rgb[1] = get_nb(colours[1]);
	if (rgb[1] == -1)
		return (ft_free_tab(colours), ft_gbg(FREE, rgb, EX), NULL);
	rgb[2] = get_nb(colours[2]);
	if (rgb[2] == -1)
		return (ft_free_tab(colours), ft_gbg(FREE, rgb, EX), NULL);
	return (ft_free_tab(colours), rgb);
}
