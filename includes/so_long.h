/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapple <tapple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:48:28 by tapple            #+#    #+#             */
/*   Updated: 2022/01/25 00:25:13 by tapple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define IMG_SIZE 128
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*hero;
	void	*wall;
	void	*key;
	void	*floor;
	void	*fin;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		count_coll;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		collected;
	int		moves;
}			t_game;

typedef struct s_content
{
	int	player;
	int	exit;
	int	i;
	int	j;
}		t_content;

void	ft_free(t_map *map);
void	ft_free1(t_game *game);
void	exit_content(t_game *game);
int		exit1(t_game *game);
int		check_end(char *file, char *end);
int		check_argv(char **argv, int argc);
void	check_border(t_game *game);
void	check_content(t_game *game, t_content content);
int		start(t_map *map, t_game *game, char **argv, int argc);
void	malloc_for_lines(t_map *map, int lines, int len);
int		count_line(int fd);
void	copy_map(char *argv, t_map *map, int lines, int len);
int		len_line(char *argv);
void	give_content(t_game *game);
int		read_map(char *argv, t_game *game, t_map *map);
void	put_background(t_game *game);
void	put_player(t_game *game);
void	put_exit(t_game *game);
void	put_wall(t_game *game);
void	put_image(t_game *game);
void	path_image(t_game *game);
void	player_move(t_game *game);
void	collected(t_game *game);
void	move(t_game *game, char os, int cor);
int		input(int key, t_game *game);
#endif