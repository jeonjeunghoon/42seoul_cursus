#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

# define EPS (1e-06)
# define is_zero(d) (fabs(d) < EPS)
# define deg2rad(d)	((d)*M_PI/180.0)
# define rad2deg(d)	((d)*180.0/M_PI)
# define min(a,b)	((a)<(b)? (a):(b))
# define max(a,b)	((a)>(b)? (a):(b))

# define X_EVENT_KEY_PRESS 2

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILES 60
# define MX 5
# define MY 5

# define SX TILES * MX
# define SY TILES * MY

# define FOV 10
# define FOV_H deg2rad(FOV)

static const double ANGLE_PER_PIXEL = FOV_H / (SX-1.);
static const double FOVH_2 = FOV_H / 2.0;

enum { VERT, HORIZ };

typedef enum { false=0, true=0 } bool;
typedef enum { DIR_N=0, DIR_E, DIR_W, DIR_S } dir_t;



typedef struct	s_wall
{
	double		wx;
	double		wy;
	double		dir;
	double		dist;
}				t_wall;

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
	t_wall		wall;
}				t_game;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
}				t_key;



// utility func
int				sign(double d)
{
	int			sign;

	sign = is_zero(d) ? 0 : ((d>0) ? 1 : -1);
	return (sign);
}

double			l2dist(double ax, double ay, double bx, double by)
{
	double		dist;

	dist = sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
	return (dist);
}

int				map_get_cell(t_game *game, int x, int y)
{
	int			res;

	if (x >= 0 && x < MX && y >= 0 && y <= MY)
		res = game->map[x][y];
	else
		res = -1;
	return (res);
}



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
					game->player.th = deg2rad(0.0);
				else if (game->map[y][x] == 'N')
					game->player.th = deg2rad(90.0);
				else if (game->map[y][x] == 'E')
					game->player.th = deg2rad(180.0);
				else
					game->player.th = deg2rad(270.0);
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
	{1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 'N', 1, 1},
	{1, 1, 1, 1, 1}
	};

	memcpy(game->map, src_map, sizeof(int) * MX * MY);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
}

int				get_wall_intersection(double ray, t_game *game)
{
	int			xstep;
	int			ystep;
	double		xslope;
	double		yslope;
	double		nx;
	double		ny;

	xstep = sign(cos(ray)); // +1: right, 0: no move, -1: left
	ystep = sign(sin(ray)); // +1: up, 0: no move, -1: down;
	xslope = (xstep == 0) ? INFINITY : tan(ray);
	yslope = (ystep == 0) ? INFINITY : 1/tan(ray);
	nx = (xstep > 0) ? floor(game->player.px)+1 : (xstep < 0) ? ceil(game->player.px)-1 : game->player.px;
	ny = (ystep > 0) ? floor(game->player.py)+1 : (ystep < 0) ? ceil(game->player.py)-1 : game->player.py;
	printf("\\nray=%.2f deg, xstep=%d, ystep=%d, xslope=%.2f, yslope=%.2f, nx=%.2f,  ny=%.2f\\n", rad2deg(ray), xstep, ystep, xslope, yslope, nx, ny);
	
	int			mapx;
	int			mapy;
	int			cell;
	int			hit_side;
	bool		hit;
	double		f;
	double		g;
	double		dist_v;
	double		dist_h;

	f = INFINITY;
	g = INFINITY;
	hit = false; // either VERT or HORIZ
	while (!hit)
	{
		if (xstep != 0)
			f = xslope * (nx - game->player.px) + game->player.py;
		if (ystep != 0)
			g = yslope * (ny - game->player.py) + game->player.px;
		dist_v = l2dist(game->player.px, game->player.py, nx, f);
		dist_h = l2dist(game->player.px, game->player.py, g, ny);
		if (dist_v < dist_h)
		{
			mapx = (xstep == 1) ? (int)(nx) : (int)(nx) - 1;
			mapy = (int)f;
			hit_side = VERT;
			printf("V(%d, %.2f) ->", mapx, f);
		}
		else
		{
			mapx = (int)g;
			mapy = (ystep == 1) ? (int)(ny) : (int)(ny) - 1;
			hit_side = HORIZ;
			printf("H(%.2f, %d) ->", g, mapy);
		}
		cell = map_get_cell(game, mapx, mapy);
		if (cell < 0)
			break ;
		if (cell == 1)
		{
			if (hit_side == VERT)
			{
				game->wall.dir = (xstep > 0) ? DIR_W : DIR_E;
				game->wall.wx = nx;
				game->wall.wy = f;
			}
			else
			{
				game->wall.dir = (ystep > 0) ? DIR_S : DIR_N;
				game->wall.wx = g;
				game->wall.wy = ny;
			}
			hit = true;
			printf(" hit wall!\n");
			break ;
		}
		if (hit_side == VERT)
			nx += xstep;
		else
			ny += ystep;
	}
	return (hit);
}

double			ft_racasting(t_game *game, int x)
{
	int			ray;

	ray = (game->player.th + FOVH_2) - (x * ANGLE_PER_PIXEL);
	if (get_wall_intersection(ray, game) == 0)
		return (INFINITY);	// no intersection - bad map
	game->wall.dist = l2dist(game->player.px, game->player.py, game->wall.wx, game->wall.wy);
	return (game->wall.dist);
}

int				main(int argc, char **argv)
{
	t_game		game;
	t_key		key;
	int			x;

	// if (argc == 2 && argv[1] == "--save");
		// save
	// else if (argc != 1)
		// return (0);
	window_init(&game);
	img_init(&game);
	key_init(&game, &key);
	map_init(&game);
	x = 0;
	while (x < SX)
	{
		game.wall.dist = ft_racasting(&game, x);
		printf("** ray %3d: dist %.2f\n", x, game.wall.dist);
		x++;
	}
	mlx_loop(game.mlx_ptr);
	return (0);
}
