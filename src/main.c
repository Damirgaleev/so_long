/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:21:26 by tapple            #+#    #+#             */
/*   Updated: 2022/01/29 17:36:47 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->hero,
		game->p_x * IMG_SIZE, game->p_y * IMG_SIZE);
	printf("%d\n", ++game->moves);
}

void	collected(t_game *game)
{
	game->collected++;
	game->map->map[game->p_y][game->p_x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
		game->p_x * IMG_SIZE, game->p_y * IMG_SIZE);
	player_move(game);
}

void	move(t_game *game, char os, int cor)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
		game->p_x * IMG_SIZE, game->p_y * IMG_SIZE);
	if (os == 'y' && game->map->map[game->p_y + 1 * cor][game->p_x] != '1'
		&& (game->map->map[game->p_y + 1 * cor][game->p_x] != 'E'
		|| game->collected == game->map->count_coll))
		game->p_y = game->p_y + 1 * cor;
	else if ((os == 'x' && game->map->map[game->p_y][game->p_x + 1 * cor] != '1'
		&& (game->map->map[game->p_y][game->p_x + 1 * cor] != 'E'
		|| game->collected == game->map->count_coll)))
		game->p_x = game->p_x + 1 * cor;
	else if ((os == 'x' && game->map->map[game->p_y][game->p_x + 1 * cor] != '1'
		&& (game->map->map[game->p_y][game->p_x + 1 * cor] == 'E'
		&& game->collected != game->map->count_coll)))
		printf("collect all coins\n");
	else if (os == 'y' && game->map->map[game->p_y + 1 * cor][game->p_x] != '1'
		&& (game->map->map[game->p_y + 1 * cor][game->p_x] == 'E'
		|| game->collected != game->map->count_coll))
		printf("collect all coins\n");
	player_move(game);
	if (game->map->map[game->p_y][game->p_x] == 'C')
		collected(game);
}

int	input(int key, t_game *game)
{
	if (key == ESC)
		ft_free1(game);
	if (key == W)
		move(game, 'y', UP);
	if (key == S)
		move(game, 'y', DOWN);
	if (key == A)
		move(game, 'x', LEFT);
	if (key == D)
		move(game, 'x', RIGHT);
	if (game->map->map[game->p_y][game->p_x] == 'E')
	{
		printf("You won\n");
		printf("You completed the game in %d steps\n", game->moves);
		ft_free1(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (!start(&map, &game, argv, argc))
		return (0);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		printf("Error\nmlx init\n");
		ft_free1(&game);
	}
	path_image(&game);
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y, "./so_long");
	if (game.win == NULL)
	{
		printf("Error\nmlx_new_window\n");
		ft_free1(&game);
	}
	put_image(&game);
	mlx_hook(game.win, 17, 1L << 2, exit1, (void *)&game);
	mlx_key_hook(game.win, input, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
