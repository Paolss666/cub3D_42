/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:54:17 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/29 16:09:37 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw(t_cube *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->screen_h)
	{
		x = 0;
		while (x < game->screen_w)
		{
			game->img->full_buf[y * game->screen_w + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, 0, 0);
}

/*
* pixel color ceiling floor : Cette fonction est chargée de colorer les pixels
* du sol et du plafond. Elle prend en entrée un pointeur vers une 
* structure de jeu t_game et la coordonnée x actuelle.
* Elle commence par obtenir les couleurs du plafond et du sol game->f_color et game->c_color
* en utilisant get_color.
* Ensuite, avec la boucle, elle colore les pixels du bord supérieur de l'écran jusqu'au point 
* où les murs sont dessinés. 
* Dans cet intervalle, elle assigne la couleur des pixels dans le tampon de jeu (game->buf[x][y])
* à la couleur du plafond (game->c_color);
* Ensuite, elle utilise une autre boucle while pour colorer
* les pixels du point où se terminent les murs jusqu'au bas de l'écran.
*/

void    pixel_color_ceiling_floor(t_cube *game, int x)
{
	int	y;

	y = 0;
	game->f_color = get_color(game->f);
	game->c_color = get_color(game->c);
	while (y < game->draw_start)
	{
		game->buf[y][x] = game->c_color;
		y++;
	}
	y = game->draw_end;
	while (y < game->screen_h && y >= 0)
	{
		if (x < game->screen_w)
			game->buf[y][x] = game->f_color;
		y++;
	}
}

/*
* pixel_color_walls ==> colorie les pixels des murs
* Utilise une boucle et parcourt les lignes verticales de la fenêtre de visualisation,
* de la coordonnée y game->draw_start jusqu'à game->draw_end
* et calcule la coordonnée de la texture (game->tex_y)
* et la couleur correspondante du tampon de texture (game->tex[game->tex_num]
* [game->tex_h * game->tex_y + game->tex_x]), 
* Enfin, définit la couleur du pixel dans le tampon de jeu(game->buf[y][x])
* avec la couleur de la texture)
*/


void	pxl_color_wll(t_cube *game, int x)
{
	int				y;
	unsigned int	color;

	y = game->draw_start;
	while (y < game->draw_end)
	{
		game->tex_y = (int)game->tex_pos & (game->tex_h - 1);
		game->tex_pos += game->step;
		color = game->tex[game->tex_num][game->tex_h * game->tex_y + game->tex_x];
		game->buf[y][x] = color;
		y++;
	}
}


/*
* Questa funzione determina quale texture utilizzare per 
* disegnare una parte in base alla posizione sulla mappa
* e dell'orientamento del reycasting.
* Se tipo il muro e' una porta (D), imposta il numeo di texture a 4 
* Altrimenti controlla l'orientamento della parete
* (game->side) Se la parete e' orientata orizzontalmente, 
* controlla la direzione dell'incremento x (game->step_x)
* e assegna il numero di texture corrispondente (0 ou 1).
* Se la parete e' orentata verticalmente, controlla la direzione dell'incremento
* y (game->step_y) e assegna il numero di texture corripondetne (2 o 3);
*/


void	texture_wall_orientation(t_cube *game)
{
	if (game->map[game->map_x][game->map_y] == 'D')
		game->tex_num = 4;
	else if (game->side == 0)
	{
		if (game->step_x == 1)
			game->tex_num = 1;
		else if (game->step_x == -1)
			game->tex_num = 0;
	}
	else if (game->side == 1)
	{
		if (game->step_y == 1)
			game->tex_num = 2;
		else if (game->step_y == -1)
			game->tex_num = 3;
	}
}

/*
* si le cote de la collision avec le mur est horizontal(game->side == 0)
	calcule la position du mur sur l 'axe des x (game->wll_x) en utilisant la position actuelle
	du jueur (game->pos_y) plus la distance perpendiculaire qu mur multipliee par la direction du rayon(game->raydir_y)
	Sinon, calcule la position du mur sur l'aze des y (game->wall_x);
	Normalise la position du mur pour s'assurer qu'elle est compirse entr 0 et 1;
* game->wall_x -= floor(game->wall_X) normalise la postion du mur po 0 ou 1;
* game->tex_x = (int)(game->wall_x * (double)game->game->tex_w); Calcule le cordonee de texture correspondant a la posi0tion du mur, 
* en multipliant la position normalisee du mur par la largeur de la texture;
* game->step = 1.0 * game->tex_h / game->line_height Calcule le pas de texture par ligne de pizel pour eviter la distorsion
* game->tex_pos = (game->draw_start - game->screen_h / 2 + game->line_height / 2) * game->step
   initialise la posit de texture in fonction de la hauteur de la ligne actuel;
*
*/


/*
* The floor() is a library function in C defined in the <math. h> header file.
* This function returns the nearest integer value, which is less than or equal
* to the floating point number (float or double) passed to it as an argument
*/



void	texture(t_cube *game, int x)
{
	game->tex_x = 0;
	game->tex_y = 0;
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->raydir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->raydir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = (int)(game->wall_x * (double)(game->tex_w));
	if (game->side == 0 && game->raydir_x > 0)
		game->tex_x = game->tex_w - game->tex_x - 1;
	if (game->side == 1 && game->raydir_y < 0)
		game->tex_x = game->tex_w - game->tex_x - 1;
	game->step = 1.0 * game->tex_h / game->line_height;
	game->tex_pos = (game->draw_start
			- game->screen_h / 2 + game->line_height / 2) * game->step;
	texture_wall_orientation(game);
	pxl_color_wll(game, x);
	pixel_color_ceiling_floor(game, x);
}
