/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:59:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define ROAD '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define HAPPY 0

# define OPEN_MAX 4896
# define BUFFER_SIZE 100

typedef struct s_node
{
	char			*buf_map;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	t_node	*front;
	t_node	*rear;
	char	**map;
	int		x;
	int		y;
	int		player;
	int		collectible;
	int		exit;
	int		open;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectible;
	int		movement;
	int		happy_ending;
}	t_player;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	int			width;
	int			height;
	void		*win;
	t_img		*img;
	int			fd;
	int			finish;
	int			error;
	t_player	*player;
	t_map		*map;
}	t_game;

/* exception */
int		exception(int argc, char *map_file);

/* game_init */
int		map_init(t_map *map);
void	player_init(t_player *player);
void	image_init(t_img *img);
int		game_init(t_game *game);

/* assets_parsing */
int		check_map(t_game *game);
int		make_map(t_game *game);
void	make_buf(t_game *game, char *map_file, int fd);
int		assets_parsing(t_game *game, char *map_file);

/* ft_key */
void	end_game(t_game *game, int check_x, int check_y, int ending_flag);
void	collect_func(t_game *game, int check_x, int check_y);
void	move_player(t_game *game, int check_x, int check_y);	
void	check_path(t_game *game, int check_x, int check_y);
int		ft_key(int keycode, t_game *game);

/* so_long */
void	ending(t_game *game);
int		so_long(t_game *game);

/* utility */
int		check_surrounded(char *map);
int		check_elements(t_game *game, t_map *map_val, char *map, int y);

/* GNL */
void	add_line(char **line, char **room);
int		is_continue(int fd, int byte, char **line, char **room);
void	add_room(char **room, char *buf);
int		get_next_line(int fd, char **line);

#endif