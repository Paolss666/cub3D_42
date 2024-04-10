/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/10 14:17:25 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D2_H
#define cub3D2_H

# include "./libft/libft.h"
//# include "../mlx_linux/mlx.h"
# include "X11/X.h"      // verifier
# include "X11/keysym.h"
# include <math.h>
#include <stdbool.h>

typedef struct s_data
{
	char	**map;
	char	**check_map;
	int		not_valid;
	int		perso;

	int		play_x;
	int		play_y;

	int		col_x;
	int		lin_y;

	int		o;
}				t_data;

//Pour tester une map adaptation so_long
int		ft_map_on_tab(int fd, t_data *data);
char	*ft_ber_on_line(int fd, t_data *data);
char	*ft_check_gnl(char *result, char *line, t_data *data, int fd);
char	*ft_clean_gnl(char *line, char *result, int fd);

// pour checker la map
int		ft_check_map(t_data *data);

# define MLX_ERROR 1

#endif