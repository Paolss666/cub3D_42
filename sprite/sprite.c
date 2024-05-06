/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:52:48 by elcesped          #+#    #+#             */
/*   Updated: 2024/05/06 17:43:13 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_sprite(t_cube *game)
{
	game->sprite1 = NULL;
	game->sprite = 0;
	game->map_x_sprite = 0;
	game->map_y_sprite = 0;
	game->side_dist_x_sprite = 0;
	game->side_dist_y_sprite = 0;
	game->perp_wall_dist_sprite = 0;
	game->line_height_sprite = 0;
	game->draw_start_sprite = 0;
	game->draw_end_sprite = 0;
	game->wall_x_sprite = 0;
	game->tex_x_sprite = 0;
	game->tex_y_sprite = 0;
	game->step_sprite = 0;
	game->tex_pos_sprite = 0;

}
//void	ft_init_sprite(t_cube *game)
//{
//	game->sprite1 = xpm_img(game, game->type[0], 32, 64);
//	if (!game->sprite1)
//	{
//		write(1, "Error\nsprite not valid\n", 24);
//		return (ft_gbg(FLUSH, NULL, ALL), exit(99), (void)0);
//	}
//}

	//while (y < game->tex_h)
	//{
	//	x = 0;
	//	while (x < game->tex_w)
	//	{
	//		game->tex[i][y * game->tex_w + x] = img->full_buf[y * game->tex_w + x];
	//		x++;
	//	}
	//	y++;
	//}

//void	sprite_size(t_cube *game)
//{
//	double spriteX = (game->map_x_sprite) - game->pos_x;
//	double spriteY = (game->map_y_sprite) - game->pos_y;

//	if (game->sprite == 0)
//	{
//		return ;
//	}
//	double invDet = 1.0 / (game->plane_x * game->dir_y - game->dir_x * game->plane_y);
//	double transformX = invDet * (game->dir_y * spriteX - game->dir_x * spriteY);
//     double transformY = invDet * (-game->plane_y * spriteX + game->plane_x * spriteY); 
//	 int spriteScreenX = (int)((game->screen_w / 2) * (1 + transformX / transformY));
//	//checker avec nico si bonnes variables
//	int spriteHeight = abs((int)(game->screen_h / (transformY)));
//	int drawStartY = -spriteHeight / 2 + game->screen_h / 2 - 1;
//    if(drawStartY < 0) 
//	  	drawStartY = 0;
//    int drawEndY = spriteHeight / 2 + game->screen_h / 2 - 1;
//      if(drawEndY >= game->screen_h)
//	  	drawEndY = game->screen_h - 1;
//	int spriteWivoid sprite_size(t_cube *game) {
//    double spriteX = (game->map_x_sprite) - game->pos_x;
//    double spriteY = (game->map_y_sprite) - game->pos_y;

//    if (game->sprite == 0) {
//        return;
//    }
//    double invDet = 1.0 / (game->plane_x * game->dir_y - game->dir_x * game->plane_y);
//    double transformX = invDet * (game->dir_y * spriteX - game->dir_x * spriteY);
//    double transformY = invDet * (-game->plane_y * spriteX + game->plane_x * spriteY);
//    int spriteScreenX = (int)((game->screen_w / 2) * (1 + transformX / transformY));

//    int spriteHeight = abs((int)(game->screen_h / transformY));
//    int drawStartY = -spriteHeight / 2 + game->screen_h / 2;
//    if (drawStartY < 0) 
//        drawStartY = 0;
//    int drawEndY = spriteHeight / 2 + game->screen_h / 2;
//    if (drawEndY >= game->screen_h)
//        drawEndY = game->screen_h - 1;

//    int spriteWidth = abs((int)(game->screen_w / transformY));
//    int drawStartX = -spriteWidth / 2 + spriteScreenX;
//    if (drawStartX < 0)
//        drawStartX = 0;
//    int drawEndX = spriteWidth / 2 + spriteScreenX;
//    if (drawEndX >= game->screen_w)
//        drawEndX = game->screen_w - 1;

//    unsigned int color;

//    for (int stripe = drawStartX; stripe < drawEndX; stripe++) {
//        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * game->tex_w / spriteWidth) / 256;
//        if (transformY > 0 && stripe > 0 && stripe < game->screen_w && transformY < game->screen_w) {
//            for (int y = drawStartY; y < drawEndY; y++) {
//                int d = (y) * 256 - game->screen_h * 128 + spriteHeight * 128;
//                int texY = ((d * game->tex_h) / spriteHeight) / 256;
//                color = game->tex[4][game->tex_w * texY + texX];
//                game->buf[y][stripe] = color;
//            }
//        }
//    }
//    game->sprite = 0;
//}dth = abs((int)(game->screen_h / (transformY)));
//      int drawStartX = -spriteWidth / 2 + spriteScreenX;
//      if(drawStartX < 0) 
//	  	drawStartX = 0;
//      int drawEndX = spriteWidth / 2 + spriteScreenX;
//      if(drawEndX >= game->screen_w)
//	  	drawEndX = game->screen_w - 1;
		
//	int				y;
//	unsigned int	color;
//	//int x = 0;
//	//static int i = 0;
//	y = drawStartY;

//	//if (game->sprite == 1)
//	//{
//	//	game->sprite = 0;
//	//	i = 1;
//	//}
//	//printf("TEST1\n");
//	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
//	{
//		//printf("TEST1, stripe = %d et drawendx = %d\n", stripe, drawEndX);
//		//printf("TEST2, transformY = %f et game->tex[4][stripe] = %d et gamescreen = %d\n", transformY, game->tex[4][stripe], game->screen_h);
//    	int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * game->tex_w / spriteWidth) / 256;
//		if(transformY > 0 && stripe > 0 && stripe < game->screen_w && transformY < game->screen_w)
//		{
//			//printf("TEST3, stripe = %d et drawendx = %d\n", drawStartX, drawEndX);
//			while (y++ < drawEndY)
//			{
//				int d = (y) * 256 - game->screen_h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
//          		int texY = ((d * game->tex_h) / spriteHeight) / 256;
//				//game->tex_y_sprite = (int)game->tex_pos_sprite & (game->tex_h - 1);
//				//game->tex_pos_sprite += game->step_sprite;
//				//if (game->tex[4][game->tex_w * texY + texX] != 0)
//				//{
//					color = game->tex[4][game->tex_w * texY + texX];
//					//printf("TEST2 color = %d\n", color);
//				//}
//				game->buf[y][stripe] = color;						
//				//y++;
//			}
//		}
//	}
//	game->sprite = 0;
//	//i = 0;

void sprite_size(t_cube *game) 
{
    double spriteX = (game->map_x_sprite + 0.5) - game->pos_x;
    double spriteY = (game->map_y_sprite + 0.5) - game->pos_y;
//ajouter une condition pour eviter d afficher le sprite si raydir de collision d un mur est avant le sprite
//mettre aux normes
//faire un thread pour l affichage du sprite avec un monitoring qui check si sprite ?


    if (game->sprite == 0) {
        return;
    }
	if (game->n_sprite == 0)
		game->n_sprite = 1;
	else
		game->n_sprite = 0;
    double invDet = 1.0 / (game->plane_x * game->dir_y - game->dir_x * game->plane_y);
    double transformX = invDet * (game->dir_y * spriteX - game->dir_x * spriteY);
    double transformY = invDet * (-game->plane_y * spriteX + game->plane_x * spriteY);
    int spriteScreenX = (int)((game->screen_w / 2) * (1 + transformX / transformY));

    int spriteHeight = abs((int)(game->screen_h / transformY));
    int drawStartY = -spriteHeight / 2 + game->screen_h / 2;
    if (drawStartY < 0) 
        drawStartY = 0;
    int drawEndY = spriteHeight / 2 + game->screen_h / 2;
    if (drawEndY >= game->screen_h)
        drawEndY = game->screen_h - 1;

    int spriteWidth = abs((int)(game->screen_w / transformY));
    int drawStartX = -spriteWidth / 2 + spriteScreenX;
    if (drawStartX < 0)
        drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
    if (drawEndX >= game->screen_w)
        drawEndX = game->screen_w - 1;

    unsigned int color;

    for (int stripe = drawStartX; stripe < drawEndX; stripe++) {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * game->tex_w / spriteWidth) / 256;
        if (transformY > 0 && stripe > 0 && stripe < game->screen_w && transformY < game->screen_w) {
            for (int y = drawStartY; y < drawEndY; y++) {
                int d = (y) * 256 - game->screen_h * 128 + spriteHeight * 128;
                int texY = ((d * game->tex_h) / spriteHeight) / 256;
                color = game->tex[game->n_sprite + 4][game->tex_w * texY + texX];
				if (color != 0)
                	game->buf[y][stripe] = color;
            }
        }
    }
    game->sprite = 0;
	usleep(1000);
}

//}

	//pxl_color_sprite(game, 4);
	//game->perp_wall_dist_sprite = (game->side_dist_x_sprite - game->delta_dist_x);
	//game->perp_wall_dist_sprite_y = (game->side_dist_y - game->delta_dist_y);
	//game->line_height_sprite = (int)(game->screen_h / game->perp_wall_dist_sprite);
	//game->draw_start_sprite = -game->line_height_sprite / 2 + game->screen_h / 2;
	//if (game->draw_start_sprite < 0)
	//	game->draw_start_sprite = 0;
	//game->draw_end_sprite = game->line_height_sprite / 2 + game->screen_h / 2;
	//if (game->draw_end_sprite >= game->screen_h)
	//	game->draw_end_sprite = game->screen_h;

void	texture_sprite(t_cube *game)
{
	if (game->sprite == 0)
		return ;
	game->tex_x_sprite = 0;
	game->tex_y_sprite = 0;
}

void	pxl_color_sprite(t_cube *game, int x)
{
	int				y;
	unsigned int	color;
	//int x = 0;
	//static int i = 0;

	if (game->sprite == 0)
		return;
	y = game->draw_start_sprite;

	//if (game->sprite == 1)
	//{
	//	game->sprite = 0;
	//	i = 1;
	//}
	
	while (y < game->draw_end_sprite)
	{
		//printf("TEST1\n");	
		game->tex_y_sprite = (int)game->tex_pos_sprite & (game->tex_h - 1);
		game->tex_pos_sprite += game->step_sprite;
		if (game->tex[4][game->tex_h * game->tex_y_sprite + game->tex_x_sprite] != 0)
		{
			color = game->tex[4][game->tex_h * game->tex_y_sprite + game->tex_x_sprite];
				
		}
		//printf("TEST2 %d\n", game->tex_h * game->tex_y_sprite + game->tex_x_sprite);	
		y++;
	}
	game->buf[y][x] = color;
	game->sprite = 0;
	//i = 0;
}

//int	get_each_img_data_sprite(t_cube *game, t_img *img, int i)
//{
//	int	x;
//	int	y;

//	game->tex[i] = ft_calloc((32 * 64), sizeof(int));
//	if (!game->tex[i] || ft_gbg(ADD, game->tex[i], EX))
//        return (ft_gbg(FLUSH, NULL, ALL), exit(99), -1);
//	y = 0;
//	while (y < 64)
//	{
//		x = 0;
//		while (x < 32)
//		{
//			game->tex[i][y * 32 + x] = img->full_buf[y * 32 + x];
//			x++;
//		}
//		y++;
//	}
//	return (0);
//}