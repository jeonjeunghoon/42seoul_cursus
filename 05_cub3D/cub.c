#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* MACRO: Key */
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_EXIT 0
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

/* MACRO: Screen size */
# define SW 1080
# define SH 600

/* MACRO: Wall size, Map size */
# define TILE 30
# define MW 10
# define MH 10

/* MACRO: Player eyes*/
# define FOV_W_DEG 90

/* MACRO: Player movement */
# define MOVE_SPEED 0.1
# define TURN_SPEED 2

typedef	struct	s_cub
{
	void		*img_ptr;
	int			width;
	int			height;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;

	void		*mlx;
	void		*win;

	double		px;
	double		py;
	double		pth;

	int			map[MH][MW];
	double		fov_w;
	double		per_fov_w;
	double		fov_h;
	double		per_fov_h;
	int			ray_cast;
	double		ray_th;
	double		x;
	double		y;
	double		dist;
	int			wall;
}				t_cub;


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

void			get_player_data(t_cub *cub, int my, int mx)
{
	cub->px = mx;
	cub->py = my;
	if (cub->map[my][mx] == 'E')
		cub->pth = deg_to_rad(0);
	else if (cub->map[my][mx] == 'N')
		cub->pth = deg_to_rad(90);
	else if (cub->map[my][mx] == 'W')
		cub->pth = deg_to_rad(180);
	else
		cub->pth = deg_to_rad(270);
	cub->fov_w = deg_to_rad(FOV_W_DEG);
	cub->per_fov_w = cub->fov_w/(SW-1);
	cub->fov_h = (cub->fov_w * SH)/SW;
	cub->per_fov_h = cub->fov_h/(SH-1);
}

void			ft_player(t_cub *cub)
{
	int			mx;
	int			my;

	my = 0;
	while (my < MH)
	{
		mx = 0;
		while (mx < MW)
		{
			if (cub->map[my][mx] >= 'E' && cub->map[my][mx] <= 'W')
			{
				get_player_data(cub, my, mx);
				return ;
			}
			mx++;
		}
		my++;
	}
}

void			ft_map(t_cub *cub)
{
	int			src[MH][MW] = {
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					{1, 0, 0, 0, 'E', 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
				};

	memcpy(cub->map, src, sizeof(int) * MH * MW);
}

void			ft_render(t_cub *cub)
{
	int			draw_start;
	int			wall_start;
	int			wall_end;
	double		h;

	cub->dist = sqrt(pow(cub->x - cub->px * TILE, 2) + pow(cub->y - cub->py * TILE, 2));
	cub->dist *= cos(cub->pth - (cub->ray_th + (cub->per_fov_w * cub->ray_cast)));
	h = ((atan((TILE/2)/cub->dist) * SH/2) / (cub->fov_h/2)) * 2;
	wall_start = (int)((SH - h)/2.0);
	wall_end = wall_start + h - 1;
	wall_start = get_bigger(0, wall_start);
	wall_end = get_lower(SH-1, wall_end);
	draw_start = 0;
	while (draw_start < SH - 1)
	{
		if (draw_start < wall_start)
			cub->data[draw_start * SW + cub->ray_cast] = 0xc7e8ed;
		else if (draw_start >= wall_start && draw_start < wall_end)
			cub->data[draw_start * SW + cub->ray_cast] = 0xFFFFFF;
		else if (draw_start < SH - 1)
			cub->data[draw_start * SW + cub->ray_cast] = 0x4a2505;
		draw_start++;
	}
}

void			ft_dda(t_cub *cub)
{
	double		delta_x;
	double		delta_y;
	double		ray_step;

	cub->x = cub->px * TILE;
	cub->y = cub->py * TILE;
	delta_x = cos(cub->ray_th + (cub->per_fov_w * cub->ray_cast));
	delta_y = sin(cub->ray_th + (cub->per_fov_w * cub->ray_cast));
	ray_step = get_bigger(fabs(delta_x), fabs(delta_y));
	delta_x /= ray_step;
	delta_y /= ray_step;
	while (cub->map[(int)floor(cub->y/TILE)][(int)floor(cub->x/TILE)] != 1 && cub->x >= 0 && cub->y >= 0)
	{
		cub->x += delta_x;
		cub->y += delta_y;
	}
	cub->wall = cub->map[(int)floor(cub->y/TILE)][(int)floor(cub->x/TILE)];
}

void			ft_racasting(t_cub *cub)
{
	cub->ray_cast = 0;
	cub->ray_th = cub->pth - (cub->fov_w / 2);
	while (cub->ray_cast < SW)
	{
		ft_dda(cub);
		if (cub->wall != 0)
			ft_render(cub);
		else
		{
			printf("ERROR: MAP\n");
			exit(0);
		}
		cub->ray_cast++;
	}
}

int				update_render(t_cub *cub)
{
	ft_racasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
	return (0);
}

int				ft_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
	{
		cub->px += MOVE_SPEED * (cos(cub->pth));
		cub->py += MOVE_SPEED * (sin(cub->pth));
	}
	else if (keycode == KEY_S)
	{
		cub->px -= MOVE_SPEED * (cos(cub->pth));
		cub->py -= MOVE_SPEED * (sin(cub->pth));
	}
	else if (keycode == KEY_A)
	{
		cub->px += MOVE_SPEED * (cos(cub->pth - deg_to_rad(90)));
		cub->py += MOVE_SPEED * (sin(cub->pth - deg_to_rad(90)));
	}
	else if (keycode == KEY_D)
	{
		cub->px += MOVE_SPEED * (cos(cub->pth + deg_to_rad(90)));
		cub->py += MOVE_SPEED * (sin(cub->pth + deg_to_rad(90)));
	}
	else if (keycode == KEY_RIGHT)
	{
		if (cub->pth < deg_to_rad(360))
			cub->pth += deg_to_rad(TURN_SPEED);
		else
		{
			cub->pth = 0;
			cub->pth += deg_to_rad(TURN_SPEED);
		}
	}
	else if (keycode == KEY_LEFT)
	{
		if (cub->pth > deg_to_rad(0))
			cub->pth -= deg_to_rad(TURN_SPEED);
		else
		{
			cub->pth = deg_to_rad(360);
			cub->pth -= deg_to_rad(TURN_SPEED);
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	printf("px py th: %f %f %f\n", cub->px, cub->py, cub->pth);
	return (0);
}

int				ft_release(int keycode, t_cub *cub)
{
	return (0);
}

int				ft_exit(int keycode, t_cub *cub)
{
	return (0);
}

int				mlx_start(t_cub *cub)
{
	mlx_hook(cub->win, EVENT_KEY_PRESS, 0, &ft_press, cub);
	mlx_hook(cub->win, EVENT_KEY_RELEASE, 0, &ft_release, cub);
	mlx_hook(cub->win, EVENT_EXIT, 0, &ft_exit, cub);
	mlx_loop_hook(cub->mlx, update_render, cub);
	mlx_loop(cub->mlx);
	return (1);
}

int				main(void)
{
	t_cub		cub;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, SW, SH, "Minecraft");
	cub.img_ptr = mlx_new_image(cub.mlx, SW, SH);
	cub.data = (int *)mlx_get_data_addr(cub.img_ptr, &cub.bpp, &cub.size_line, &cub.endian);
	ft_map(&cub);
	ft_player(&cub);
	update_render(&cub);
	mlx_start(&cub);
	return (0);
}
