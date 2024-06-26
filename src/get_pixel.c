/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:58:04 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/06 16:53:03 by npaolett         ###   ########.fr       */
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

int	get_color(int *tab_c)
{
	unsigned int	hexa_color;

	hexa_color = ((unsigned int)tab_c[0] << 16 | \
	(unsigned int)tab_c[1] << 8 | (unsigned int)tab_c[2]);
	return (hexa_color);
}
