/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:54:40 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/24 18:34:10 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_alltypes(char **new)
{
	if (search_type("NO", new) == -1)
		return (-1);
	if (search_type("SO", new) == -1)
		return (-1);
	if (search_type("WE", new) == -1)
		return (-1);
	if (search_type("EA", new) == -1)
		return (-1);
	if (search_type("F", new) == -1)
		return (-1);
	if (search_type("C", new) == -1)
		return (-1);
	return (0);
}

int	reorder_new(char **new)
{
	int		i;
	int		swap_val;

	i = 0;
	if (check_alltypes(new) == -1)
		return (ft_putstr_fd("Error\nInvalid type\n", 2), -1);
	while (new[i])
	{
		swap_val = ptr_to_swap(new[i]);
		if (swap_val == -1)
			return (ft_putstr_fd("Error\nInvalid type\n", 2), -1);
		if (swap_val != -1)
			swap_ptrs(&new[i], &new[swap_val]);
		i++;
	}
	if (check_types(new) == -1)
		return (ft_putstr_fd("Error\nInvalid type\n", 2), -1);
	return (0);
}