/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:17 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 00:22:18 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start(t_map *map, t_game *game, char **argv, int argc)
{
	if (!check_argv(argv, argc))
	{
		printf("Error\nincorrect argv\n");
		return (0);
	}
	if (!read_map(argv[1], game, map))
	{
		printf("Error\nincorrect map\n");
		return (0);
	}
	return (1);
}

void	malloc_for_lines(t_map *map, int lines, int len)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		map->map[i] = malloc(sizeof(char) * len);
		if (!map->map[i])
		{
			perror("Error\nmalloc error\n");
			ft_free(map);
		}
		i++;
	}
}
