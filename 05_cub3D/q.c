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

# define SW 720
# define SH 480

# define TILE 30
# define MW 6
# define MH 6

# define FOV_DW 90

typedef	struct	s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef	struct	s_game
{
	int			map[MH][MW];
	int			px;
	int			py;
	double		pth;
	double		fov_w;
	double		per_fov_w;
	double		fov_h;
	double		per_fov_h;
}				t_game;

typedef	struct	s_ray
{
	double		ray_x;
	double		ray_y;
	double		dist;
}				t_ray;

double			ft_deg_to_rad(double deg)
{
	double		rad;

	rad = deg * (M_PI/180);
	return (rad);
}

void			ft_player_data(t_game *game, int my, int mx)
{
	game->px = mx;
	game->py = my;
	if (game->map[my][mx] == 'E')
		game->pth = ft_deg_to_rad(0);
	else if (game->map[my][mx] == 'N')
		game->pth = ft_deg_to_rad(90);
	else if (game->map[my][mx] == 'W')
		game->pth = ft_deg_to_rad(180);
	else
		game->pth = ft_deg_to_rad(270);
	game->fov_w = ft_deg_to_rad(FOV_DW);
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
			if (game->map[my][mx] >= 65 && game->map[my][mx] <= 90)
			{
				ft_player_data(game, my, mx);
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
					{1, 1, 1, 1, 1, 1},
					{1, 'N', 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1}
				};

	memcpy(game->map, src, sizeof(int) * MH * MW);
}

void			draw_wall(t_game *game, t_ray *ray, t_img *img, int cast_ray)
{
	int			x;
	int			y;
	int			h;
	double		pixel_h;

	ray->dist = sqrt(pow(ray->ray_x - game->px, 2) + pow(ray->ray_y - game->py, 2));
	pixel_h = ((atan((TILE/2)/ray->dist) * SH/2) / (game->fov_h/2) * 2);
	h = fabs(pixel_h);
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < SW)
		{
			img->data[((SH-h + y) * SW + x] = 0xFF0000;
			x++;
		}
		y++;
	}
}

void			ft_racasting(t_game *game, t_ray *ray, t_img *img)
{
	int			cast_ray;
	double		ray_th;
	double		delta_x;
	double		delta_y;
	double		ray_step;

	cast_ray = 0;
	ray_th = game->pth - (game->fov_w / 2);
	while (cast_ray < SW)
	{
		ray->ray_x = game->px * TILE;
		ray->ray_y = game->py * TILE;
		delta_x = cos(ray_th + (game->per_fov_w * cast_ray));
		delta_y = sin(ray_th + (game->per_fov_w * cast_ray));
		if (fabs(delta_x) > fabs(delta_y))
			ray_step = delta_x;
		else
			ray_step = delta_y;
		delta_x /= ray_step;
		delta_y /= ray_step;
		while (game->map[(int)floor(ray->ray_y/TILE)][(int)floor(ray->ray_x/TILE)] != 1)
		{
			ray->ray_x += delta_x;
			ray->ray_y += delta_y;
		}
		draw_wall(game, ray, img, cast_ray);
		cast_ray++;
	}
}

int				ft_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->py += 0.1;
	else if (keycode == KEY_S)
		game->py -= 0.1;
	else if (keycode == KEY_D)
		game->px += 0.1;
	else if (keycode == KEY_A)
		game->px -= 0.1;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int				main(void)
{
	t_mlx		mlx;
	t_img		img;
	t_game		game;
	t_ray		ray;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SW, SH, "Minecraft");
	img.width = TILE * SW;
	img.height = TILE * SH;
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, img.width, img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	ft_map(&game);
	ft_player(&game);
	ft_racasting(&game, &ray, &img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &ft_key, &game);
	mlx_loop(mlx.mlx_ptr);
}
