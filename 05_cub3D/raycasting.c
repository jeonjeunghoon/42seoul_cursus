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



typedef struct	s_player
{
	double		px;
	double		py;
	double		th;
}				t_player;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map[MY][MX];
	t_img		img;
	t_player	player;
}				t_game;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
}				t_key;



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

int				key_press(int keycode, t_key *key)
{
	if (keycode == KEY_W)
		key->w++;
	else if (keycode == KEY_A)
		key->a++;
	else if (keycode == KEY_S)
		key->s++;
	else if (keycode == KEY_D)
		key->d++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("w = %d\na = %d\ns = %d\nd = %d\n", key->w, key->a, key->s, key->d);
	return (0);
}

void			key_init(t_game *game, t_key *key)
{
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &key);
}

void			draw_player(t_game *game, int x, int y)
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
			if (game->map[y/60][x/60] == 'N')
				game->img.data[(row + y) * SX + (col + x)] = 0xFF0000;
			else if (game->map[y/60][x/60] == 'S')
				game->img.data[(row + y) * SX + (col + x)] = 0x0000FF;
			else if (game->map[y/60][x/60] == 'E')
				game->img.data[(row + y) * SX + (col + x)] = 0x00FF00;
			else
				game->img.data[(row + y) * SX + (col + x)] = 0xFFFF00;
			col++;
		}
		row++;
	}
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

void			draw_minimap(t_game *game)
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
			else if (game->map[y][x] == 'E' || game->map[y][x] == 'W' || game->map[y][x] == 'S' || game->map[y][x] == 'N')
			{
				game->player.px = x;
				game->player.py = y;
				if (game->map[y][x] == 'W')
					game->player.th = 0.0;
				else if (game->map[y][x] == 'N')
					game->player.th = 90.0;
				else if (game->map[y][x] == 'E')
					game->player.th = 180.0;
				else
					game->player.th = 270.0;
				draw_player(game, x, y);
			}
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
	{1, 1, 'N', 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src_map, sizeof(int) * MX * MY);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
}

int				main(int argc, char **argv)
{
	t_game		game;
	t_key		key;
	t_player	player;

	// if (argc == 2 && argv[1] == "--save");
		// save
	// else if (argc != 1)
		// return (0);
	window_init(&game);
	img_init(&game);
	key_init(&game, &key);
	map_init(&game);
	printf("player px py th are: %f %f %f\n", game.player.px, game.player.py, game.player.th);
	mlx_loop(game.mlx_ptr);
	return (0);
}
