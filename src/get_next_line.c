/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:11:30 by tapple            #+#    #+#             */
/*   Updated: 2022/02/04 22:55:10 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*reader(char *line, int fd)
{
	char	*buff;
	int		was_read;

	was_read = 1;
	buff = (char *)malloc(sizeof(char) * 1 + 1);
	if (!buff)
		return (0);
	while (!ft_strchr(line, '\n') && was_read != 0)
	{
		was_read = read(fd, buff, 1);
		if (was_read == -1)
		{
			free(buff);
			return (0);
		}
		buff[was_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_line(char *st_line)
{
	char	*line;
	int		i;

	i = 0;
	if (st_line[i] == '\0')
		return (0);
	while (st_line[i] && st_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (st_line[i] && st_line[i] != '\n')
	{
		line[i] = st_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*trim(char	*st_line)
{
	char	*line;
	int		before_n;
	int		after_n;

	before_n = 0;
	after_n = 0;
	while (st_line[before_n] && st_line[before_n] != '\n')
		before_n++;
	if (!st_line[before_n])
	{
		free(st_line);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(st_line) - before_n + 1));
	if (!line)
		return (NULL);
	before_n++;
	while (st_line[before_n])
		line[after_n++] = st_line[before_n++];
	line[after_n] = '\0';
	free(st_line);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*st_line;

	if (fd < 0)
		return (0);
	st_line = reader(st_line, fd);
	if (!st_line)
		return (NULL);
	line = get_line(st_line);
	st_line = trim(st_line);
	return (line);
}
