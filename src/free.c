/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:29 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 11:57:53 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit(1);
}

void	ft_free1(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		i++;
	}
	free(game->map->map);
	if (game->img)
		free(game->img);
	exit(1);
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
