/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:10 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 00:22:11 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(int fd)
{
	int		line;
	char	c;
	int		bytes;

	bytes = 1;
	line = 1;
	while (bytes)
	{
		bytes = read(fd, &c, 1);
		if (bytes != 1)
			break ;
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

void	copy_map(char *argv, t_map *map, int lines, int len)
{
	int		fd;
	char	buf[2];
	int		i;
	int		bytes;

	i = 0;
	bytes = 1;
	buf[1] = '\0';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nincorrect fd\n");
		ft_free(map);
	}
	malloc_for_lines(map, lines, len);
	while (bytes)
	{
		bytes = read(fd, buf, 1);
		if (buf[0] != '\n' && buf[0] != '\0')
			map->map[i] = ft_strjoin(map->map[i], buf);
		else
			i++;
	}
	close(fd);
}

int	len_line(char *argv)
{
	int		i;
	char	c;
	int		fd;
	int		bytes;

	bytes = 1;
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nincorrect fd\n");
		return (0);
	}
	while (bytes == 1)
	{
		bytes = read(fd, &c, 1);
		if (c == '\n')
			break ;
		i++;
	}
	close(fd);
	return (i);
}

void	give_content(t_game *game)
{
	t_content	content;

	content.exit = 0;
	content.i = 0;
	content.player = 0;
	game->map->count_coll = 0;
	while (game->map->map[content.i])
	{
		content.j = 0;
		while (game->map->map[content.i][content.j])
		{
			if (game->map->map[content.i][content.j] == 'P')
				content.player++;
			if (game->map->map[content.i][content.j] == 'C')
				game->map->count_coll++;
			if (game->map->map[content.i][content.j] == 'E')
				content.exit++;
			content.j++;
		}
		content.i++;
	}
	check_content(game, content);
}

int	read_map(char *argv, t_game *game, t_map *map)
{
	int		fd;
	int		line;
	int		len_first_line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nincorrect fd\n");
		return (0);
	}
	line = count_line(fd);
	game->size_y = line * IMG_SIZE;
	len_first_line = len_line(argv);
	game->size_x = len_first_line * IMG_SIZE;
	map->map = malloc(sizeof(char *) * (line));
	if (!map->map)
	{
		perror("Error\nmalloc for line\n");
		return (0);
	}
	copy_map(argv, map, line, len_first_line);
	game->map = map;
	give_content(game);
	return (1);
}
