/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:53:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define ENEMY 'D'
# define EXIT 'E'
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3
# define BLOCKED 4
# define HAPPY 0
# define BAD 1

# define OPEN_MAX 4896
# define BUFFER_SIZE 100

typedef struct s_enemy
{
	int				x;
	int				y;
	int				direction;
	int				distance;
	int				move;
	struct s_enemy	*next;
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
	char	**map;
	int		x;
	int		y;
	int		player;
	int		collectible;
	int		enemy;
	t_enemy	*e_front;
	t_enemy	*e_rear;
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
	int		bad_ending;
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

/* enemy */
int		check_wall(char **map, t_enemy *head);
void	move_enemy(char **map, t_enemy *head);
int		check_direction(t_map *map, int x, int y, t_enemy *head);
void	enemy_action(t_game *game);

/* so_long */
void	ending(t_game *game);
int		so_long(t_game *game);

/* utility */
void	get_enemy_data(t_game *game, int x, int y);
int		check_surrounded(char *map);
int		check_elements(t_game *game, t_map *map_val, char *map, int y);

/* GNL */
void	add_line(char **line, char **room);
int		is_continue(int fd, int byte, char **line, char **room);
void	add_room(char **room, char *buf);
int		get_next_line(int fd, char **line);

#endif
