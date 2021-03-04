# include "cub.h"

void				ft_render(t_cub *cub)
{
	int				wall_h;
	int				wall_start;
	int				wall_end;

	cub->dist = ft_dist(cub->px, cub->py, cub->wx, cub->wy);
	cub->dist *= cos(cub->pth - cub->ray_th); // 어안렌즈 현상 보정
	wall_h = (int)((cub->sh) * (WALL_H/(2.0 * cub->dist * tan(cub->fov_w/2.0))));
	wall_start = (int)((cub->sh - wall_h)/2.0);
	wall_end = wall_start + wall_h - 1;
	wall_end = get_lower(cub->sh - 1, wall_end);
	int f = 0;
	while (f < wall_start && wall_start > 0)
		cub->img.data[f++ * cub->sw + cub->ray_cast] = 0x0000FF;
	wall_render(cub, wall_start, wall_end, wall_h);
	while (wall_end < cub->sh)
		cub->img.data[wall_end++ * cub->sw + cub->ray_cast] = 0x00FF00;
}

int					ft_dda(t_cub *cub)
{
	cub->x_step = ft_sgn(cos(cub->ray_th));
	cub->y_step = ft_sgn(sin(cub->ray_th));
	if (cub->x_step == 0)
		cub->x_slope = INFINITY;
	else
		cub->x_slope = tan(cub->ray_th);
	if (cub->y_step == 0)
		cub->y_slope = INFINITY;
	else
		cub->y_slope = 1./tan(cub->ray_th);
	if (cub->x_step > 0)
		cub->nx = floor(cub->px) + 1;
	else if (cub->x_step < 0)
		cub->nx = ceil(cub->px) - 1;
	else
		cub->nx = cub->px;
	if (cub->y_step > 0)
		cub->ny = floor(cub->py) + 1;
	else if (cub->y_step < 0)
		cub->ny = ceil(cub->py) - 1;
	else
		cub->ny = cub->py;
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
			if (cub->x_step == 1)
				cub->map_x = (int)cub->nx;
			else
				cub->map_x = (int)(cub->nx - 1);
			cub->map_y = (int)cub->f;
			cub->hit_side = VERT;
		}
		else // HORIZ is nearer; go along y-axis
		{
			cub->map_x = (int)cub->g;
			if (cub->y_step == 1)
				cub->map_y = (int)(cub->ny);
			else
				cub->map_y = (int)(cub->ny - 1);
			cub->hit_side = HORIZ;
		}
		cub->cell = get_cell(cub, cub->map_x, cub->map_y);
		if (cub->cell < 0)
			break ; // out of map
		if (cub->cell == 1 || cub->cell == 2)
		{
			if (cub->hit_side == VERT)
			{
				if (cub->x_step > 0)
					cub->w_dir = DIR_W;
				else
					cub->w_dir = DIR_E;
				cub->wx = cub->nx;
				cub->wy = cub->f;
			}
			else
			{
				if (cub->y_step > 0)
					cub->w_dir = DIR_S;
				else
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

int					ft_raycasting(t_cub *cub, t_sprite *sprite)
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
		ft_render(cub);
		cub->sprite.zbuf[cub->ray_cast] = cub->dist;
		if (cub->cell == 2)
			ft_sprite(cub, sprite);
		cub->ray_cast++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}