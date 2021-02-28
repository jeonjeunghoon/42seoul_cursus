# include "cub.h"

void				ft_render(t_cub *cub)
{
	int				wall_h;
	int				wall_start;
	int				wall_end;
	int				f;
	unsigned int	color;

	cub->dist *= cos(cub->pth - cub->ray_th); // 어안렌즈 현상 보정
	wall_h = (int)((cub->sh) * (WALL_H/(2.0 * cub->dist * tan(cub->fov_w/2.0))));
	f = (int)((cub->sh - wall_h)/2.0);
	wall_end = f + wall_h - 1;
	wall_start = get_bigger(0, f);
	wall_end = get_lower(cub->sh - 1, wall_end);
	int draw_start = 0;
	while (draw_start < wall_start)
			cub->img.data[draw_start++ * cub->sw + cub->ray_cast] = 0x0000FF;
	while (wall_start <= wall_end)
			cub->img.data[wall_start++ * cub->sw + cub->ray_cast] = 0xFFFFFF;
	while (wall_end < cub->sh - 1)
			cub->img.data[wall_end++ * cub->sw + cub->ray_cast] = 0x00FF00;
}

int					ft_dda(t_cub *cub)
{
	double			ray_step;

	cub->x_step = ft_sgn(cos(cub->ray_th));
	cub->y_step = ft_sgn(sin(cub->ray_th));
	cub->x_slope = tan(cub->ray_th);
	if (cub->x_step == 0)
		cub->x_slope = INFINITY;
	cub->y_slope = 1./tan(cub->ray_th);
	if (cub->y_step == 0)
		cub->y_slope = INFINITY;
	cub->nx = cub->px;
	if (cub->x_step > 0)
		cub->nx = floor(cub->px) + 1;
	else if (cub->x_step < 0)
		cub->nx = ceil(cub->px) - 1;
	cub->ny = cub->py;
	if (cub->y_step > 0)
		cub->ny = floor(cub->py) + 1;
	else if (cub->y_step < 0)
		cub->ny = ceil(cub->py) - 1;
	cub->f = INFINITY;
	cub->g = INFINITY;
	cub->hit = 0;
	while (!cub->hit)
	{
		if (cub->x_step != 0)
			cub->f = cub->x_slope * (cub->nx - cub->px) + cub->py;
		if (cub->y_step != 0)
			cub->g = cub->y_slope * (cub->ny - cub->py) + cub->px;
		// which is nearer to me - VERT(nx, f) or HORIZ(g, ny)?
		cub->dist_v = ft_dist(cub->px, cub->py, cub->nx, cub->f);
		cub->dist_h = ft_dist(cub->px, cub->py, cub->g, cub->ny);
		if (cub->dist_v < cub->dist_h) // VERT is nearer; go along x-axis
		{
			cub->map_x = ((int)(cub->nx)) - 1;
			if (cub->x_step == 1)
				cub->map_x = (int)cub->nx;
			cub->map_y = (int)cub->f;
			cub->hit_side = VERT;
		}
		else // HORIZ is nearer; go along y-axis
		{
			cub->map_x = (int)cub->g;
			cub->map_y = ((int)(cub->ny) - 1);
			if (cub->y_step == 1)
				cub->map_y = (int)(cub->ny);
			cub->hit_side = HORIZ;
		}
		cub->cell = get_cell(cub, cub->map_x, cub->map_y);
		if (cub->cell < 0)
			break ; // out of map
		if (cub->cell != 0)
		{
			if (cub->hit_side == VERT)
			{
				cub->w_dir = DIR_W;
				if (cub->x_step > 0)
					cub->w_dir = DIR_E;
				cub->wx = cub->nx;
				cub->wy = cub->f;
			}
			else
			{
				cub->w_dir = DIR_S;
				if (cub->y_step > 0)
					cub->w_dir = DIR_N;
				cub->wx = cub->g;
				cub->wy = cub->ny;
			}
			cub->hit = 1;
			break ;
		}
		if (cub->hit_side == VERT)
			cub->nx += cub->x_step;
		else
			cub->ny += cub->y_step;
	}
	return (cub->hit);
}

int					ft_raycasting(t_cub *cub)
{
	cub->ray_cast = 0;
	while (cub->ray_cast < cub->sw)
	{
		cub->ray_th = cub->pth + cub->half_fov_w - (cub->per_fov_w * cub->ray_cast);
		if ((ft_dda(cub)) == 0)
		{
			printf("ERROR: MAP\n");
			return (INFINITY);
		}
		cub->dist = ft_dist(cub->px, cub->py, cub->wx, cub->wy);
		ft_render(cub);
		cub->ray_cast++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}