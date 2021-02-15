#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

# define X_EVENT_KEY_PRESS 2

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define SW 1080
# define SH 600

# define TILE 30
# define MW 10
# define MH 10

# define FOV_W_DEG 90

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef	struct	s_player
{
	int			px;
	int			py;
	double		pth;
}				t_player;

typedef	struct	s_game
{
	int			map[MH][MW];
	t_player	player;
	double		fov_w;
	double		per_fov_w;
	double		fov_h;
	double		per_fov_h;
}				t_game;

typedef	struct	s_ray
{
	int			ray_cast;
	double		ray_th;
	double		x;
	double		y;
	double		dist;
	int			wall;
}				t_ray;

double			deg_to_rad(double deg)
{
	double		rad;

	rad = deg * (M_PI/180);
	return (rad);
}

double			rad_to_deg(double rad)
{
	double		deg;

	deg = rad * (180/M_PI);
	return (deg);
}

double			get_lower(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

double			get_bigger(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

void			get_player_data(t_game *game, int my, int mx)
{
	game->player.px = mx;
	game->player.py = my;
	if (game->map[my][mx] == 'E')
		game->player.pth = deg_to_rad(0);
	else if (game->map[my][mx] == 'N')
		game->player.pth = deg_to_rad(90);
	else if (game->map[my][mx] == 'W')
		game->player.pth = deg_to_rad(180);
	else
		game->player.pth = deg_to_rad(270);
	game->fov_w = deg_to_rad(FOV_W_DEG);
	game->per_fov_w = game->fov_w/(SW-1);
	game->fov_h = (game->fov_w * SH)/SW;
	game->per_fov_h = game->fov_h/(SH-1);
}

void			ft_player(t_game *game)
{
	int			mx;
	int			my;

	my = 0;
	while (my < MH)
	{
		mx = 0;
		while (mx < MW)
		{
			if (game->map[my][mx] >= 'E' && game->map[my][mx] <= 'W')
			{
				get_player_data(game, my, mx);
				return ;
			}
			mx++;
		}
		my++;
	}
}

void			ft_map(t_game *game)
{
	int			src[MH][MW] = {
					{4, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 'E', 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
					{3, 3, 3, 3, 3, 3, 3, 3, 3, 2}
				};

	memcpy(game->map, src, sizeof(int) * MH * MW);
}

void			draw_wall(t_mlx *mlx, t_game *game, t_ray *ray)
{
	int			y_start;
	int			y_end;
	double		h;

	ray->dist = sqrt(pow(ray->x - game->player.px * TILE, 2) + pow(ray->y - game->player.py * TILE, 2));
	ray->dist *= cos(game->player.pth - (ray->ray_th + (game->per_fov_w * ray->ray_cast)));
	h = ((atan((TILE/2)/ray->dist) * SH/2) / (game->fov_h/2)) * 2;
	y_start = (int)((SH - h)/2.0);
	y_end = y_start + h - 1;
	y_start = get_bigger(0, y_start);
	y_end = get_lower(SH-1, y_end);
	while (y_start < y_end)
	{
		if (ray->wall == 1)
			mlx->img.data[y_start * SW + ray->ray_cast] = 0xFF0000;
		if (ray->wall == 2)
			mlx->img.data[y_start * SW + ray->ray_cast] = 0x00FF00;
		if (ray->wall == 3)
			mlx->img.data[y_start * SW + ray->ray_cast] = 0x0000FF;
		if (ray->wall == 4)
			mlx->img.data[y_start * SW + ray->ray_cast] = 0xFFFFFF;
		y_start++;
	}
}

void			ft_racasting(t_mlx *mlx, t_game *game, t_ray *ray)
{
	double		delta_x;
	double		delta_y;
	double		ray_step;

	ray->x = game->player.px * TILE;
	ray->y = game->player.py * TILE;
	delta_x = cos(ray->ray_th + (game->per_fov_w * ray->ray_cast));
	delta_y = sin(ray->ray_th + (game->per_fov_w * ray->ray_cast));
	ray_step = get_bigger(fabs(delta_x), fabs(delta_y));
	delta_x /= ray_step;
	delta_y /= ray_step;
	while (game->map[(int)floor(ray->y/TILE)][(int)floor(ray->x/TILE)] != 1 && game->map[(int)floor(ray->y/TILE)][(int)floor(ray->x/TILE)] != 2 \
		&& game->map[(int)floor(ray->y/TILE)][(int)floor(ray->x/TILE)] != 3 && game->map[(int)floor(ray->y/TILE)][(int)floor(ray->x/TILE)] != 4 \
		&& ray->x >= 0 && ray->y >= 0)
	{
		ray->x += delta_x;
		ray->y += delta_y;
	}
	ray->wall = game->map[(int)floor(ray->y/TILE)][(int)floor(ray->x/TILE)];
}

int				ft_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.py += 0.1;
	else if (keycode == KEY_S)
		game->player.py -= 0.1;
	else if (keycode == KEY_D)
		game->player.px += 0.1;
	else if (keycode == KEY_A)
		game->player.px -= 0.1;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int				main(void)
{
	t_mlx		mlx;
	t_game		game;
	t_ray		ray;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SW, SH, "Minecraft");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, SW, SH);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_line, &mlx.img.endian);
	ft_map(&game);
	ft_player(&game);
	ray.ray_cast = 0;
	ray.ray_th = game.player.pth - (game.fov_w / 2);
	while (ray.ray_cast < SW)
	{
		ft_racasting(&mlx, &game, &ray);
		if (ray.wall != 0)
			draw_wall(&mlx, &game, &ray);
		// else
		// 	return (0);
		ray.ray_cast++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &ft_key, &game);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
