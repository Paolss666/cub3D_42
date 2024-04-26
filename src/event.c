/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:36 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/26 16:54:13 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


int	esc_close(int key, t_cube *game)
{
	int	i;

	i = 4;
	if (key ==  XK_Escape)
	{
		if (game->so)
			mlx_destroy_image(game->mlx_ptr, game->so->img_ptr);
		if (game->we)
			mlx_destroy_image(game->mlx_ptr, game->we->img_ptr);
		if (game->ea)
			mlx_destroy_image(game->mlx_ptr, game->ea->img_ptr);
		if (game->no)
			mlx_destroy_image(game->mlx_ptr, game->no->img_ptr);
		if (game->img->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->img->img_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		ft_gbg(FLUSH, NULL, ALL);
		exit(99);
	}
	return (0);
}

int	close_win(t_cube *game)
{
	if (game->so)
		mlx_destroy_image(game->mlx_ptr, game->so->img_ptr);
	if (game->we)
		mlx_destroy_image(game->mlx_ptr, game->we->img_ptr);
	if (game->ea)
		mlx_destroy_image(game->mlx_ptr, game->ea->img_ptr);
	if (game->no)
		mlx_destroy_image(game->mlx_ptr, game->no->img_ptr);
	if (game->img->img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img->img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_gbg(FLUSH, NULL, ALL);
	exit(2);
}

int	handle_no_event(t_cube *game)
{
	if (game->key_w)
		move_up(game);
	if (game->key_s)
		move_down(game);
	if (game->key_d)
		move_right(game);
	if (game->key_a)
		move_left(game);
	// if (game->key_right)
		// rotate_right(game, -0.3);
	// if (game->key_left)
		// rotate_left(game, 0.3);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	display(game, 0);
	return (0);
}

int	handle_keypress(int keysym, t_cube *game)
{
	if (keysym == XK_w)
		game->key_w = 1;
	if (keysym == XK_s)
		game->key_s = 1;
	if (keysym == XK_d)
		game->key_d = 1;
	if (keysym == XK_a)
		game->key_a = 1;
	if (keysym == XK_m && game->p_minimap == 0)
		game->p_minimap = 1;
	else if (keysym == XK_m && game->p_minimap == 1)
		game->p_minimap = 0;
	if (keysym == XK_Right)
	{
		game->key_right = 1;
		printf("%d\n", game->key_right);
	}
	if (keysym == XK_Left)
	{
		game->key_left = 2;
		printf("%d\n", game->key_left);
	}
	if (keysym == XK_Escape)
		close_win(game);
	return (0);
}

int	handle_keyrelease(int keysym, t_cube *game)
{
	if (keysym == XK_w)
		game->key_w = 0;
	if (keysym == XK_s)
		game->key_s = 0;
	if (keysym == XK_d)
		game->key_d = 0;
	if (keysym == XK_a)
		game->key_a = 0;
	if (keysym == XK_Right)
		game->key_right = 0;
	if (keysym == XK_Left)
		game->key_left = 0;
	return (0);
}
