/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:22:17 by tapple            #+#    #+#             */
/*   Updated: 2022/01/29 21:06:14 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start(t_map *map, t_game *game, char **argv, int argc)
{
	if (!check_argv(argv, argc))
		return (0);
	if (!read_map(argv[1], game, map))
	{
		printf("Error\nincorrect map\n");
		return (0);
	}
	return (1);
}
