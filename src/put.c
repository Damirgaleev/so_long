/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:07 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 00:22:08 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->floor, x, y);
			x += IMG_SIZE;
		}
		y += IMG_SIZE;
	}
}

void	put_player(t_game *game)
{
	game->p_x = game->map->x;
	game->p_y = game->map->y;
	mlx_put_image_to_window(game->mlx, game->win, game->img->hero,
		game->p_x * IMG_SIZE, game->p_y * IMG_SIZE);
}

void	put_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img->fin, game->map->x * IMG_SIZE,
		game->map->y * IMG_SIZE);
}

void	put_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img->wall, game->map->x * IMG_SIZE,
		game->map->y * IMG_SIZE);
}

void	put_image(t_game *game)
{
	game->map->y = 0;
	game->map->x = 0;
	put_background(game);
	while (game->map->y < (game->size_y / IMG_SIZE))
	{
		game->map->x = 0;
		while (game->map->x < (game->size_x / IMG_SIZE))
		{
			if (game->map->map[game->map->y][game->map->x] == 'P')
				put_player(game);
			if (game->map->map[game->map->y][game->map->x] == '1')
				put_wall(game);
			if (game->map->map[game->map->y][game->map->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->key, game->map->x * IMG_SIZE,
					game->map->y * IMG_SIZE);
			if (game->map->map[game->map->y][game->map->x] == 'E')
				put_exit(game);
			game->map->x++;
		}
		game->map->y++;
	}
}
