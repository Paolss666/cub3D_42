/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/11 15:00:32 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D2_H
#define cub3D2_H

#include "cub3D.h"
# include "./libft/libft.h"
//# include "../mlx_linux/mlx.h"
# include "X11/X.h"      // verifier
# include "X11/keysym.h"
# include <math.h>
#include <stdbool.h>


typedef struct s_checkmap
{
	int	not_valid;
	int	perso;
	char	**check_map;
}		t_checkmap;


// pour checker la map
int ft_check_map(t_cube *game);

# define MLX_ERROR 1

#endif