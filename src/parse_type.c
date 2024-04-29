/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:35:21 by npaolett          #+#    #+#             */
/*   Updated: 2024/04/26 12:17:43 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_wspc_excl_nl(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

void	swap_ptrs(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	check_types(char **new)
{
	if (ft_strncmp(new[0], "NO", 2))
		return (-1);
	if (ft_strncmp(new[1], "SO", 2))
		return (-1);
	if (ft_strncmp(new[2], "WE", 2))
		return (-1);
	if (ft_strncmp(new[3], "EA", 2))
		return (-1);
	if (ft_strncmp(new[4], "F", 1))
		return (-1);
	if (ft_strncmp(new[5], "C", 1))
		return (-1);
	return (0);
}

int	ptr_to_swap(char *s)
{
	if (!ft_strncmp(s, "NO", 2) && is_wspc_excl_nl(s[2]))
		return (0);
	if (!ft_strncmp(s, "SO", 2) && is_wspc_excl_nl(s[2]))
		return (1);
	if (!ft_strncmp(s, "WE", 2) && is_wspc_excl_nl(s[2]))
		return (2);
	if (!ft_strncmp(s, "EA", 2) && is_wspc_excl_nl(s[2]))
		return (3);
	if (!ft_strncmp(s, "F", 1) && is_wspc_excl_nl(s[1]))
		return (4);
	if (!ft_strncmp(s, "C", 1) && is_wspc_excl_nl(s[1]))
		return (5);
	return (-1);
}

int	search_type(char *type, char **new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		if (!ft_strncmp(type, new[i], ft_strlen(type)))
			return (0);
		i++;
	}
	return (-1);
}


int	clean_for_types(char **new)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (new[i])
	{
		if (i < 4)
			j = 3;
		else
			j = 2;
		while (new[i][j] && is_wspc_excl_nl(new[i][j]))
			j++;
		tmp = ft_strdup(&new[i][j]);
		if (!tmp || ft_gbg(ADD, tmp, PARS))
			return (ft_gbg(FLUSH, NULL, ALL), exit(99), 0);
		ft_gbg(FREE, new[i], PARS);
		new[i] = tmp;
		i++;
	}
	return (0);
}


char *init_for_trim(void)
{
	char	*for_trim;

	for_trim = ft_calloc(6, sizeof(char));
	if (!for_trim || ft_gbg(ADD, for_trim, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), NULL);
	for_trim[0] = ' ';
	for_trim[1] = '\v';
	for_trim[2] = '\r';
	for_trim[3] = '\t';
	for_trim[4] = '\f';
	return (for_trim);
}


int	found_redif_type(t_cube *game, int fd)
{
	char	*to_trim;
	int		i;
	char	*temp;
	char	**new;

	i = 0;
	new = ft_calloc(7, sizeof(char *));
	if (!new || ft_gbg(ADD, new, PARS))
		return (ft_gbg(FLUSH, NULL, ALL), exit(99), 0);
	to_trim = init_for_trim();
	while (game->type[i])
	{
		temp = ft_strtrim(game->type[i], to_trim);
		if (!temp || ft_gbg(ADD, temp, PARS))
			return (ft_gbg(FLUSH, NULL, ALL), exit(99), 0);
		new[i] = temp;
		i++;
	}
	if (reorder_new(new) == -1)
		return (get_next_line(fd, 1), clear_wrong_text(game), -1);
	if (clean_for_types(new) == -1)
		return (clear_wrong_text(game), -1);
	ft_free_tab(game->type);
	game->type = new;
	return (0);
}
