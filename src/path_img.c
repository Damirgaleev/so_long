/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:21:54 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 00:21:55 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path_image(t_game *game)
{
	t_img	*img;
	int		w;
	int		h;

	img = malloc(sizeof(*img));
	if (img == NULL)
	{
		perror("Error\nmalloc for img\n");
		ft_free1(game);
	}
	img->floor = mlx_xpm_file_to_image(game->mlx, "./sprites/floo.xpm", &w, &h);
	img->hero = mlx_xpm_file_to_image(game->mlx, "./sprites/hero.xpm", &w, &h);
	img->key = mlx_xpm_file_to_image(game->mlx, "./sprites/key.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &w, &h);
	img->fin = mlx_xpm_file_to_image(game->mlx, "./sprites/finish.xpm", &w, &h);
	game->img = img;
	if (game->img == NULL)
	{
		printf("Error\npath to image\n");
		ft_free1(game);
	}
	game->moves = 0;
	game->collected = 0;
}
