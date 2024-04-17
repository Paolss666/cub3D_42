/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:58:04 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/17 15:13:31 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* 
* Questa funzione 
* get_color prende in input un array di interi tab_c, 
* dove tab_c[0], tab_c[1] e tab_c[2] rappresentano 
* rispettivamente i valori dei canali Rosso, 
* Verde e Blu (RGB) del colore. 
* La funzione concatena questi valori 
* in un unico valore unsigned int hexa_color, 
* che rappresenta il colore in formato esadecimale. 
* Questo viene fatto spostando i bit del valore di tab_c[0] 
* di 16 posizioni a sinistra, poi aggiungendo 
* il valore di tab_c[1] spostato di 8 posizioni a sinistra 
* e infine aggiungendo il valore di tab_c[2]. Alla fine, 
* la funzione restituisce il valore esadecimale del colore.
*/

int     get_color(int *tab_c)
{
	unsigned int	hexa_color;

	hexa_color = ((unsigned int)tab_c[0] << 16 | \
	(unsigned int)tab_c[1] << 8 | (unsigned int)tab_c[2]);
	// printf("rgb == > %d\n", tab_c[0]);
	// printf("rgb == > %d\n", tab_c[1]);
	// printf("rgb == > %d\n", tab_c[2]);
	return (hexa_color);
}

unsigned int	get_pixel_img(t_img src, int x, int y)
{
	return (*(unsigned int *)((src.addr
			+ (y * src.line_len) + (x * src.bpp / 8))));
}

void	put_pixel_img_anims(t_img dst, int x, int y, int color)
{
	char	*img;

	if (x >= 0 && y >= 0 && x < dst.w && y < dst.h)
	{
		img = dst.addr + (y * dst.line_len + x * (dst.bpp / 8));
		*(unsigned int *) img = color;
	}
}
