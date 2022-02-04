/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:25 by tapple            #+#    #+#             */
/*   Updated: 2022/02/04 22:58:19 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_end(char *file, char *end)
{
	int	i;
	int	j;
	int	z;

	j = 0;
	z = 0;
	i = 0;
	j = ft_strlen(file);
	z = ft_strlen(end);
	j -= z;
	while (file[j])
	{
		if (file[j] != end[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_argv(char **argv, int argc)
{
	if (argc < 2)
	{
		printf("Error\nmissing argument\n");
		return (0);
	}
	if (argc > 2)
		printf("worning: only first arg processed\n");
	if (ft_strlen(argv[1]) < 5 || (!check_end(argv[1], ".ber")))
	{
		printf("Error\nthe argument must have an extension .ber\n");
		return (0);
	}
	return (1);
}

void	isrectangular(int j, t_game *game)
{
	if (j != game->size_x / IMG_SIZE)
		exit_content(game);
}

void	check_border(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] != '1' && game->map->map[i][j] != '0'
				&& game->map->map[i][j] != 'C' && game->map->map[i][j] != 'E'
				&& game->map->map[i][j] != 'P')
				exit_content(game);
			else if ((i == 0 || j == 0) && game->map->map[i][j] != '1')
				exit_content(game);
			else if (((i == game->size_y / IMG_SIZE - 1)
					&& game->map->map[i][j] != '1')
					|| (((j == game->size_x / IMG_SIZE - 1)
					&& game->map->map[i][j] != '1')))
				exit_content(game);
			j++;
		}
		isrectangular(j, game);
		i++;
	}
}

void	check_content(t_game *game, t_content content)
{
	if (game->map->count_coll == 0)
	{
		printf("Error\nitems must be greater than 0\n");
		ft_free1(game);
	}
	if (content.player != 1)
	{
		printf("Error\nthe player must be alone\n");
		ft_free1(game);
	}
	if (content.exit == 0)
	{
		printf("Error\nthere should be an exit on the map\n");
		ft_free1(game);
	}
	check_border(game);
}
