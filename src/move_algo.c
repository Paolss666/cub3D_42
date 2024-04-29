/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:44:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/29 12:17:22 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


double	clc_plyer_direction(t_cube *game)
{
	return (atan2(game->dir_y, game->dir_x));
}

void	move_up(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x + game->dir_x * (game->move_speed
				+ 0.01))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y + game->dir_y
			* (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x += game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y += game->dir_y * game->move_speed;
}

void	move_down(t_cube *game)
{
	char	new_pos_y;
	char	new_pos_x;

	new_pos_x = game->map[(int)(game->pos_x - game->dir_x * (game->move_speed
				+ 0.01))][(int)game->pos_y];
	new_pos_y = game->map[(int)game->pos_x][(int)(game->pos_y - game->dir_y
			* (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x -= game->dir_x * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y -= game->dir_y * game->move_speed;
}

/* 
* Il motivo per cui si utilizza il valore di π (pi greco)
* in questo codice è per calcolare la direzione della testa del giocatore
* e determinare il movimento verso sinistra.
* In questo caso, viene utilizzata la costante M_PI_2,
* che rappresenta π/2,
* per ruotare la direzione del giocatore di 90 gradi in senso antiorario.
* Questo è utile quando si desidera spostarsi a sinistra rispetto alla direzione
* corrente della testa del giocatore.
 */

void	move_left(t_cube *game)
{
	char	new_pos_x;
	char	new_pos_y;
	double	head_direction;

	head_direction = clc_plyer_direction(game);
	new_pos_x = game->map[(int)(game->pos_x + cos(head_direction + M_PI_2)
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			+ sin(head_direction + M_PI_2) * (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x += cos(head_direction + M_PI_2) * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y += sin(head_direction + M_PI_2) * game->move_speed;
}

void	move_right(t_cube *game)
{
	char	new_pos_x;
	char	new_pos_y;
	double	head_direction;

	head_direction = clc_plyer_direction(game);
	new_pos_x = game->map[(int)(game->pos_x + cos(head_direction - M_PI_2)
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			+ sin(head_direction - M_PI_2) * (game->move_speed + 0.01))];
	if (new_pos_x != '1')
		game->pos_x += cos(head_direction - M_PI_2) * game->move_speed;
	if (new_pos_y != '1')
		game->pos_y += sin(head_direction - M_PI_2) * game->move_speed;
}
