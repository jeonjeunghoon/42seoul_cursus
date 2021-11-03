/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 17:57:56 by jeunjeon         ###   ########.fr       */
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
# define ROAD 0
# define WALL 1
# define COLLECTIBLE 2
# define ENEMY 3
# define EXIT 4

# define OPEN_MAX 4896
# define BUFFER_SIZE 100

typedef struct s_enemy
{
	int		x;
	int		y;
}	t_enemy;

typedef struct s_node
{
	char			*buf_map;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	t_node	*front;
	t_node	*rear;
	int		**map;
	int		x;
	int		y;
	int		player;
	int		collectible;
	int		exit;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectible;
	int		movement;
	int		happy_ending;
	int		bad_ending;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	int			is_error;
	t_player	*player;
	t_map		*map;
	t_enemy		*enemy;
}	t_game;

/* exception */
int		exception(int argc, char *map_file);

/* game_init */
void	enemy_init(t_enemy *enemy);
int		map_init(t_map *map);
void	player_init(t_player *player);
int		game_init(t_game *game);

/* assets_parsing */
int		check_surrounded(char *buf);
int		check_elements(t_game *game, char *buf, int x_len);
int		check_map(t_game *game, char *map_file, int fd);
int		make_buf_map(t_game *game, char *map_file, int fd);
int		assets_parsing(t_game *game, char *map_file);

/* start_game */
void	encounter_enemy(t_game *game, int check_x, int check_y);
void	collect_func(t_game *game, int check_x, int check_y);
void	check_path(t_game *game, int check_x, int check_y);
int		ft_key(int keycode, t_game *game);
int		start_game(t_game *game);

/* end_game */
void	end_game(t_game *game);

/* utility */
void	move_player(t_game *game, int check_x, int check_y);	

/* GNL */
void	add_line(char **line, char **room);
int		is_continue(int fd, int byte, char **line, char **room);
void	add_room(char **room, char *buf);
int		get_next_line(int fd, char **line);

#endif
