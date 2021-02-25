# include "cub.h"

void			decide_dir(t_cub *cub)
{
	int			g;

	g = TILE - 1;
	cub->w_dir = -1;
	if ((int)cub->ray_x % TILE == 0 && (int)cub->ray_y % TILE != 0 && \
		(int) cub->ray_y % TILE != g)
		cub->w_dir = DIR_E;
	else if ((int)cub->ray_x % TILE != 0 && (int)cub->ray_y % TILE == g && \
			(int) cub->ray_x % TILE != g)
		cub->w_dir = DIR_N;
	else if ((int)cub->ray_x % TILE == g && (int)cub->ray_y % TILE != 0 && \
			(int) cub->ray_y % TILE != g)
		cub->w_dir = DIR_W;
	else if ((int)cub->ray_x % TILE != 0 && (int)cub->ray_y % TILE == 0 && \
			(int) cub->ray_x % TILE != g)
		cub->w_dir = DIR_S;
	else
		cub->w_dir = DIR_C;
}

void			render_wall(t_cub *cub, int draw_start)
{
	decide_dir(cub);
	if (cub->w_dir == DIR_C)
		cub->data[draw_start * cub->sw + cub->ray_cast] = 0xFFFFFF;
	else if (cub->w_dir == DIR_E)
		cub->data[draw_start * cub->sw + cub->ray_cast] = 0x745974;
	else if (cub->w_dir == DIR_N)
		cub->data[draw_start * cub->sw + cub->ray_cast] = 0x9996A5;
	else if (cub->w_dir == DIR_W)
		cub->data[draw_start * cub->sw + cub->ray_cast] = 0xE0BBB6;
	else if (cub->w_dir == DIR_S)
		cub->data[draw_start * cub->sw + cub->ray_cast] = 0xE7AB63;
}

void			ft_render(t_cub *cub)
{
	int			draw_start;
	int			wall_start;
	int			wall_end;
	double		wall_h;

	cub->dist = sqrt(pow(cub->ray_x - cub->p_x * TILE, 2) + pow(cub->ray_y - cub->p_y * TILE, 2));
	cub->dist *= cos(cub->p_th - cub->ray_th);
	wall_h = ((atan((TILE / 2) / cub->dist) * cub->sh / 2) / (cub->fov_h / 2)) * 2;
	wall_start = (int)((cub->sh - wall_h)/2.0 - 1);
	wall_end = wall_start + wall_h - 1;
	wall_start = get_bigger(0, wall_start);
	wall_end = get_lower(cub->sh-1, wall_end);
	draw_start = 0;
	while (draw_start < cub->sh - 1)
	{
		if (draw_start < wall_start)
			cub->data[draw_start * cub->sw + cub->ray_cast] = 0xC1D7E2;
		else if (draw_start >= wall_start && draw_start < wall_end)
			render_wall(cub, draw_start);
		else if (draw_start < cub->sh - 1)
			cub->data[draw_start * cub->sw + cub->ray_cast] = 0x47302E;
		draw_start++;
	}
}

void			ft_dda(t_cub *cub)
{
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
	while (cub->ray_cast < cub->sw)
	{
		cub->ray_th = cub->p_th - cub->half_fov_w + cub->per_fov_w * cub->ray_cast;
		ft_dda(cub);
		if ((cub->object != 1 && cub->object != 2) || cub->p_x < 0 || \
			cub->p_y < 0 || cub->p_x >= MW - 1 || cub->p_y >= MH - 1)
		{
			printf("ERROR: MAP\n");
			exit(0);
		}
		else if (cub->object == 1)
			ft_render(cub);
		// else
		// 	ft_sprite(cub);
		cub->ray_cast++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (1);
}