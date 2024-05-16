/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/16 16:00:40 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line_maker(int fd, char *buf, char *storage)
{
	int		r_size;
	char	*tmp;

	r_size = read(fd, buf, BUFFER_SIZE);
	while (r_size > 0)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = ft_strdup(buf);
		else
		{
			tmp = storage;
			storage = ft_strjoin(storage, buf);
			free(tmp);
		}
		if (!(storage))
			return (NULL);
		if (ft_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

int	ft_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_extract_line(char *line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = ft_strdup(line + i + 1);
	if (!(tmp))
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd, int frex)
{
	static char	*storage;
	char		*buf;
	char		*line;
	char		*temp2;

	if (frex == 1)
		return (free(storage), NULL);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		return (NULL);
	line = ft_line_maker(fd, buf, storage);
	free(buf);
	if (!line)
		return (NULL);
	storage = ft_extract_line(line);
	temp2 = ft_strdup(line);
	free(line);
	line = NULL;
	return (temp2);
}
