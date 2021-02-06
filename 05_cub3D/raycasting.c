#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

# define X_EVENT_KEY_PRESS 2

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILES 60
# define MX 15
# define MY 10

# define SX TILES * MX
# define SY TILES * MY

# define FOV 10
# define FOV_H 10 / (SX - 1)

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
}				t_key;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			map[MY][MX];
	t_key		key;
}				t_game;

void			window_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, SX, SY, "Minecraft");
}

void			img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, SX, SY);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

void			draw_tiles(t_game *game, int x, int y)
{
	int			col;
	int			row;

	x *= TILES;
	y *= TILES;
	row = 0;
	while (row < TILES)
	{
		col = 0;
		while (col < TILES)
		{
			if (row == TILES - 1 || col == TILES - 1)
				game->img.data[(row + y) * SX + (col + x)] = 0xb3b3b3;
			else
				game->img.data[(row + y) * SX + (col + x)] = 0xFFFFFF;
			col++;
		}
		row++;
	}
}

void			draw_map(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (y < MY)
	{
		x = 0;
		while (x < MX)
		{
			if (game->map[y][x] == 1)
				draw_tiles(game, x, y);
			x++;
		}
		y++;
	}
}

void			map_init(t_game *game)
{
	int			src_map[MY][MX] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src_map, sizeof(int) * MX * MY);
	draw_map(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
}

int				key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key.w++;
	else if (keycode == KEY_A)
		game->key.a++;
	else if (keycode == KEY_S)
		game->key.s++;
	else if (keycode == KEY_D)
		game->key.d++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("w = %d\na = %d\ns = %d\nd = %d\n", game->key.w, game->key.a, game->key.s, game->key.d);
	return (0);
}

void			key_init(t_game *game)
{
	int			(*fptr_keypress)(int, t_game *);

	fptr_keypress = key_press;
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, fptr_keypress, &game->key);
}

int				main(int argc, char **argv)
{
	t_game		game;

	// if (argc != 4)
	// 	return (0);
	window_init(&game);
	img_init(&game);
	map_init(&game);
	// player_init(&game);
	key_init(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
