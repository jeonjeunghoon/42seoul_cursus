# include "cub.h"

// void			decide_dir(t_cub *cub)
// {
// 	int			g;

// 	g = TILE - 1;
// 	cub->w_dir = -1;
// 	if ((int)cub->ray_x % TILE == 0 && (int)cub->ray_y % TILE != 0 && \
// 		(int) cub->ray_y % TILE != g)
// 		cub->w_dir = DIR_E;
// 	else if ((int)cub->ray_x % TILE != 0 && (int)cub->ray_y % TILE == g && \
// 			(int) cub->ray_x % TILE != g)
// 		cub->w_dir = DIR_N;
// 	else if ((int)cub->ray_x % TILE == g && (int)cub->ray_y % TILE != 0 && \
// 			(int) cub->ray_y % TILE != g)
// 		cub->w_dir = DIR_W;
// 	else if ((int)cub->ray_x % TILE != 0 && (int)cub->ray_y % TILE == 0 && \
// 			(int) cub->ray_x % TILE != g)
// 		cub->w_dir = DIR_S;
// 	else
// 		cub->w_dir = DIR_C;
// }

void			render_wall(t_cub *cub, int draw_start)
{
	// decide_dir(cub);
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
	int			wall_h;

	cub->dist *= cos(cub->p_th - cub->ray_th);
	wall_h = (int)((cub->sh) * (WALL_H/(2.0 * cub->dist * tan(cub->fov_w/2.0))));
	wall_start = (int)((cub->sh - wall_h)/2.0);
	wall_end = wall_start + wall_h - 1;
	wall_start = get_bigger(0, wall_start);
	wall_end = get_lower(cub->sh - 1, wall_end);
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

int				ft_dda(t_cub *cub)
{
	double		ray_step;

	// 42ray
	cub->x_step = ft_sgn(cos(cub->ray_th));
	cub->y_step = ft_sgn(sin(cub->ray_th));
	cub->x_slope = tan(cub->ray_th);
	if (cub->x_step == 0)
		cub->x_slope = INFINITY;
	cub->y_slope = 1./tan(cub->ray_th);
	if (cub->y_step == 0)
		cub->y_slope = INFINITY;
	cub->nx = cub->p_x;
	if (cub->x_step > 0)
		cub->nx = floor(cub->p_x) + 1;
	else if (cub->x_step < 0)
		cub->nx = ceil(cub->p_x) - 1;
	cub->ny = cub->p_y;
	if (cub->y_step > 0)
		cub->ny = floor(cub->p_y) + 1;
	else if (cub->y_step < 0)
		cub->ny = ceil(cub->p_y) - 1;
	cub->f = INFINITY;
	cub->g = INFINITY;
	cub->hit = 0;
	while (!cub->hit)
	{
		if (cub->x_step != 0)
			cub->f = cub->x_slope * (cub->nx - cub->p_x) + cub->p_y;
		if (cub->y_step != 0)
			cub->g = cub->y_slope * (cub->ny - cub->p_y) + cub->p_x;
		// which is nearer to me - VERT(nx, f) or HORIZ(g, ny)?
		cub->dist_v = ft_dist(cub->p_x, cub->p_y, cub->nx, cub->f);
		cub->dist_h = ft_dist(cub->p_x, cub->p_y, cub->g, cub->ny);
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
		if (cub->cell == 1)
		{
			if (cub->hit_side == VERT)
			{
				cub->w_dir = DIR_E;
				if (cub->x_step > 0)
					cub->w_dir = DIR_W;
				cub->wx = cub->nx;
				cub->wy = cub->f;
			}
			else
			{
				cub->w_dir = DIR_N;
				if (cub->y_step > 0)
					cub->w_dir = DIR_S;
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

int				ft_raycasting(t_cub *cub)
{
	cub->ray_cast = 0;
	while (cub->ray_cast < cub->sw)
	{
		cub->ray_th = cub->p_th + cub->half_fov_w - (cub->per_fov_w * cub->ray_cast);
		if ((ft_dda(cub)) == 0)
		{
			printf("ERROR: MAP\n");
			return (INFINITY);
		}
		cub->dist = ft_dist(cub->p_x, cub->p_y, cub->wx, cub->wy);
		// printf("px: %f py: %f wx: %f wy: %f dist: %f\n", cub->p_x, cub->p_y, cub->wx, cub->wy, cub->dist);
		ft_render(cub);
		cub->ray_cast++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (1);
}