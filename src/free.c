/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:29 by tapple            #+#    #+#             */
/*   Updated: 2022/01/29 18:06:05 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	exit(0);
}

void	ft_free1(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map)
	{
		while (game->map->map[i])
		{
			free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
	}
	exit(0);
}

void	exit_content(t_game *game)
{
	printf("Error\nincorrect content\n");
	ft_free1(game);
}

int	exit1(t_game *game)
{
	ft_free1(game);
	return (0);
}
