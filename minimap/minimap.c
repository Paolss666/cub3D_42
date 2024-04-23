/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:38:49 by elcesped          #+#    #+#             */
/*   Updated: 2024/04/23 18:56:50 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

#include "mlx.h"

#define WIDTH  80
#define HEIGHT 100

//ca fait 9 par 7 case 


//int ft_wall_on_minimap(t_cube *game)
//{
	
//}

int ft_put_minimap(t_cube *game)
{
	int colorA[3] = {0, 0, 0};
	int colorB[3] = {255, 204, 204};
	int colorC[3] = {204, 102, 51};
	
	int a = (int)game->pos_x;
	int b = (int)game->pos_y;
	int c = a - 3;
	int d = b - 4;

	int y;
	y = 10;

	int x;
	x = 10;
	//printf("le perso est ici : %d et %d\n", a, b);
	
	//if (a < )

	while(1)
	{
		//ft_print_maperror(game, game->map_game, 0, 0);
		//printf("c = %d d = %d et y = %d et x = %d\n", c, d, y, x);
		//if((x < HEIGHT && y == 10) || (y < WIDTH && x == 10) || (y == WIDTH && x < HEIGHT) || (x == HEIGHT && y < WIDTH) || (x == 10 && y == 10))
		//	game->buf[y][x] = (unsigned int)get_color(colorA);
		if (x == HEIGHT && y == WIDTH)
		{
			game->buf[y][x] = (unsigned int)get_color(colorA);
			break ;
		}
		else if (c < 0 || d < 0 || d >= game->crow || c >= game->l)
			game->buf[y][x] = (unsigned int)get_color(colorA);
		//else if (!game->map[c][d])
		//	game->buf[y][x] = (unsigned int)get_color(colorA);			
		else if ((x % 10 == 0 || y % 10 == 0) && c >= 0 && d >= 0 && game->map[c][d] && game->map[c][d] == '0')
			game->buf[y][x] = (unsigned int)get_color(colorA);
		else if(c >= 0 && d >= 0 && game->map[c][d] && game->map[c][d] == '1' && x <= HEIGHT && y <= WIDTH)
			game->buf[y][x] = (unsigned int)get_color(colorA);
		else
		{
			if (c == a && d == b)
				game->buf[y][x] = (unsigned int)get_color(colorC);
			else
				game->buf[y][x] = (unsigned int)get_color(colorB);
		}
		if(x % 10 == 0 && x != 10)
			d++;
		if (x == HEIGHT)
		{
			x = 9;
			y++;
			d = b - 4;					
			if (y % 10 == 0)
				c++;
		}
		x++;
	}
    return 0;
}

//int ft_put_minimap(t_cube *game)
//{


//    void *img_ptr;
//    int *buffer;
//    int x, y;
	
//    // Création d'un tableau pour le buffer
//    buffer = (int *)malloc(sizeof(int) * WIDTH * HEIGHT);

//    // Dessiner quelque chose dans le buffer
//    for (y = 0; y < HEIGHT; y++) {
//        for (x = 0; x < WIDTH; x++) {
//            if (x % 2 == 0 || y % 2 == 0) {
//                buffer[y * WIDTH + x] = 0xFF0000; // Rouge
//            } else {
//                buffer[y * WIDTH + x] = 0xFFFFFF; // Blanc
//            }
//        }
//    }

//    // Création de l'image à partir du buffer
//    img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
//    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, 0, 0);

//    // Afficher le contenu de la fenêtre
//    //mlx_loop(game->mlx_ptr);

//    // Nettoyage
//    //mlx_destroy_window(game->mlx_ptr, game->win_ptr);
//    free(buffer);

//    return 0;
//}

//void    pixel_color_ceiling_floor(t_cube *game, int x)
//{
//	int	y;

//	y = 0;
//	game->f_color = get_color(game->f);
//	game->c_color = get_color(game->c);
//	while (y < game->draw_start)
//	{
//		game->buf[y][x] = game->c_color;
//		y++;
//	}
//	y = game->draw_end;
//	while (y < game->screen_h && y >= 0)
//	{
//		if (x < game->screen_w)
//			game->buf[y][x] = game->f_color;
//		y++;
//	}
//}