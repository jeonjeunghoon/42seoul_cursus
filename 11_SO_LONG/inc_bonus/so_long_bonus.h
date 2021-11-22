/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:38:54 by jeujeon           #+#    #+#             */
/*   Updated: 2021/11/22 20:28:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

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

typedef int		t_bool;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				direction;
	int				distance;
	t_bool			move;
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
	int		exit;
	int		enemy;
	t_enemy	*e_front;
	t_enemy	*e_rear;
	t_bool	open;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectible;
	int		movement;
	t_bool	happy_ending;
	t_bool	bad_ending;
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

typedef struct s_imgs
{
	t_img		road_img;
	t_img		wall_img;
	t_img		player_img;
	t_img		collect_img;
	t_img		enemy_img;
	t_img		exit_img;
}	t_imgs;

typedef struct s_draw
{
	int			ani_time;
	int			ani_flag;
	int			tile_i;
	int			tile_j;
	int			sp_w;
	int			sp_h;
	int			t_w;
	int			t_h;
	int			max_screen_x;
	int			max_screen_y;
	int			camera_pivot_x;
	int			camera_pivot_y;
}	t_draw;

typedef struct s_game
{
	void		*mlx;
	int			width;
	int			height;
	void		*win;
	t_img		img;
	t_imgs		*imgs;
	int			fd;
	t_draw		*draw;
	t_bool		finish;
	t_bool		error;
	t_player	*player;
	t_map		*map;
}	t_game;

/* draw_set_cam */
void	set_camera_var(t_game *game);
void	set_max_screen_var(t_game *game);
void	set_draw_var(t_game *game);

/* draw_sprite */
void	draw_road(t_game *game, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	draw_enemy(t_game *game, int x, int y);
void	draw_player(t_game *game, int x, int y);
void	draw_exit(t_game *game, int x, int y);
void	draw_collect(t_game *game, int x, int y);
void	make_animation(t_game *game);

/* exception */
int		exception(int argc, char *map_file);

/* game_init */
void	map_init(t_map *map);
void	draw_init(t_game *game);
void	player_init(t_player *player);
int		game_init(t_game *game);

/* draw_init */
void	sprite_init1(t_game *game);
void	sprite_init2(t_game *game);

/* assets_parsing */
int		check_map(t_game *game);
int		make_map(t_game *game);
void	make_buf(t_game *game, int fd);
int		assets_parsing(t_game *game, char *map_file);

/* ft_key */
void	end_game(t_game *game, int check_x, int check_y, int ending_flag);
void	collect_func(t_game *game, int check_x, int check_y);
void	move_player(t_game *game, int check_x, int check_y);	
void	check_path(t_game *game, int check_x, int check_y);
int		ft_key(int keycode, t_game *game);

/* enemy */
void	move_enemy(t_game *game, t_enemy *head);
int		check_direction(t_map *map, int x, int y);
void	is_player_die(t_game *game, t_enemy *head);
void	enemy_action(t_game *game);

/* so_long */
void	ending(t_game *game);
void	draw_map(t_game *game);
int		so_long(t_game *game);

/* utility */
void	get_enemy_data(t_game *game, int x, int y);
int		check_surrounded(char *map);
int		check_elements(t_game *game, t_map *map_val, char *map, int y);
int		to_coord(t_game *game, int x, int y);

/* GNL */
void	add_line(char **line, char **room);
int		is_eof(int fd, int byte, char **line, char **room);
void	add_room(char **room, char *buf);
int		get_next_line(int fd, char **line);

#endif
