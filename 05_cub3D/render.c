# include "cub.h"

void			decide_dir(t_cub *cub, int draw_start)
{
	cub->dir_e = 0;
	cub->dir_w = 0;
	cub->dir_s = 0;
	cub->dir_n = 0;
	if (fabs(cub->delta_x) == 1.0)
	{
		if (cub->delta_x < 0)
			cub->dir_w = 1;
		else
			cub->dir_e = 1;
	}
	else if (fabs(cub->delta_y) == 1.0)
	{
		if (cub->delta_y < 0)
			cub->dir_n = 1;
		else
			cub->dir_s = 1;
	}
}

void			render_wall(t_cub *cub, int draw_start)
{
	decide_dir(cub, draw_start);
	if (cub->dir_e == 1)											// E
		cub->data[draw_start * SW + cub->ray_cast] = 0xFF0000;
	else if (cub->dir_s == 1)										// S
		cub->data[draw_start * SW + cub->ray_cast] = 0x00FF00;
	else if (cub->dir_w == 1)										// W
		cub->data[draw_start * SW + cub->ray_cast] = 0x0000FF;
	else if (cub->dir_n == 1)										// N
		cub->data[draw_start * SW + cub->ray_cast] = 0xFF00FF;
}

void			ft_render(t_cub *cub)
{
	int			draw_start;
	int			wall_start;
	int			wall_end;
	double		wall_h;

	cub->dist = sqrt(pow(cub->ray_x - cub->p_x * TILE, 2) + pow(cub->ray_y - cub->p_y * TILE, 2));
	cub->dist *= cos(cub->p_th - cub->ray_th);
	wall_h = ((atan((TILE / 2) / cub->dist) * SH / 2) / (cub->fov_h / 2)) * 2;
	wall_start = (int)((SH - wall_h)/2.0 - 1);
	wall_end = wall_start + wall_h - 1;
	wall_start = get_bigger(0, wall_start);
	wall_end = get_lower(SH-1, wall_end);
	draw_start = 0;
	while (draw_start < SH - 1)
	{
		if (draw_start < wall_start)
			cub->data[draw_start * SW + cub->ray_cast] = 0xc7e8ed;
		else if (draw_start >= wall_start && draw_start < wall_end)
			render_wall(cub, draw_start);
		else if (draw_start < SH - 1)
			cub->data[draw_start * SW + cub->ray_cast] = 0x4a2505;
		draw_start++;
	}
}

void			ft_dda(t_cub *cub)
{
	// double		delta_x;
	// double		delta_y;
	double		ray_step;

	cub->delta_x = cos(cub->ray_th);
	cub->delta_y = sin(cub->ray_th);
	ray_step = get_bigger(fabs(cub->delta_x), fabs(cub->delta_y));
	cub->delta_x /= ray_step;
	cub->delta_y /= ray_step;
	cub->ray_x = cub->p_x * TILE;
	cub->ray_y = cub->p_y * TILE;
	cub->map_x = (int)floor(cub->ray_x/TILE);
	cub->map_y = (int)floor(cub->ray_y/TILE);
	while (cub->map[cub->map_y][cub->map_x] != 1 \
		&& cub->map[cub->map_y][cub->map_x] != 2)
	{
		cub->ray_x += cub->delta_x;
		cub->ray_y += cub->delta_y;
		cub->map_x = (int)floor(cub->ray_x/TILE);
		cub->map_y = (int)floor(cub->ray_y/TILE);
	}
	cub->object = cub->map[cub->map_y][cub->map_x];
}

int				ft_raycasting(t_cub *cub)
{
	cub->ray_cast = 0;
	while (cub->ray_cast < SW)
	{
		cub->ray_th = cub->p_th - cub->half_fov_w + cub->per_fov_w * cub->ray_cast;
		ft_dda(cub);
		if ((cub->object != 1 && cub->object != 2) || cub->p_x < 0 || \
			cub->p_y < 0 || cub->p_x >= MW - 1 || cub->p_y >= MH - 1)
		{
			printf("ERROR: MAP\n");
			exit(0);
		}
		else
			ft_render(cub);
		cub->ray_cast++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (1);
}