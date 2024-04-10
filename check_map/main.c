/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:32:38 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/10 14:17:29 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D2.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_data	*data;

	if (argc == 2)
	{
		fd = 0;
		fd = open(argv[1], fd);
	}
	else
	{
		ft_putstr_fd("Error\nNo Card Or Too Much Card\n", 2);
		return (1);
	}
	i = 0;
	data->col_x = 5;
	data->lin_y = 10;
	printf("CECI EST UN TEST\n");
	ft_map_on_tab(fd, data);
	if (data->map == NULL)
		return (1);
	ft_check_map(data);
	printf("%s\n",data->map[1]);
	return (0);
}