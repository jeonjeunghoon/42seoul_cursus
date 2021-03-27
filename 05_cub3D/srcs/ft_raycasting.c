# include "cub.h"

int					get_wall_height(t_cub *cub, double dist)
{
    double			h;
	int				wall_h;

	h = 2.0 * dist * tan(cub->player.fov_v/2.0);
	wall_h = (int)(cub->scr.sy * (WALL_H / h));
	return (wall_h);
}

void				ft_render(t_cub *cub)
{
	int				wh;
	int				y0;
	int				y1;

	cub->ray.dist = ft_dist(cub->player.x, cub->player.y, cub->ray.wx, cub->ray.wy);
	cub->ray.dist *= cos(cub->player.th - cub->ray.ray);
	wh = get_wall_height(cub, cub->ray.dist);
	y0 = (int)((cub->scr.sy - wh)/2.0);
	y1 = y0 + wh - 1;
	y1 = get_min(cub->scr.sy - 1, y1);
	wall_render(cub, y0, y1, wh);
}

int					ft_dda(t_cub *cub)
{
    cub->ray.xstep = ft_sgn( cos(cub->ray.ray) );
    cub->ray.ystep = ft_sgn( sin(cub->ray.ray) );
	cub->ray.xslope = (cub->ray.xstep == 0) ? INFINITY : tan(cub->ray.ray);
    cub->ray.yslope = (cub->ray.ystep == 0) ? INFINITY : 1./tan(cub->ray.ray);
    cub->ray.nx = (cub->ray.xstep > 0) ? floor(cub->player.x)+1 : ((cub->ray.xstep < 0) ? ceil(cub->player.x)-1 : cub->player.x);
    cub->ray.ny = (cub->ray.ystep > 0) ? floor(cub->player.y)+1 : ((cub->ray.ystep < 0) ? ceil(cub->player.y)-1 : cub->player.y);
    cub->ray.f = INFINITY;
	cub->ray.g = INFINITY;
    cub->ray.hit = 0;
	while(!cub->ray.hit)
    {
        if (cub->ray.xstep != 0)
			cub->ray.f = cub->ray.xslope * (cub->ray.nx - cub->player.x) + cub->player.y;
        if (cub->ray.ystep != 0)
			cub->ray.g = cub->ray.yslope * (cub->ray.ny - cub->player.y) + cub->player.x;
    	cub->ray.dist_v = ft_dist(cub->player.x, cub->player.y, cub->ray.nx, cub->ray.f);
        cub->ray.dist_h = ft_dist(cub->player.x, cub->player.y, cub->ray.g, cub->ray.ny);
		if (cub->ray.dist_v < cub->ray.dist_h)
		{
			cub->map.mapx = (cub->ray.xstep == 1) ? (int)(cub->ray.nx) : (int)(cub->ray.nx)-1 ;
			cub->map.mapy = (int) cub->ray.f;
			cub->ray.hit_side = VERT;
		}
        else
		{
            cub->map.mapx = (int) cub->ray.g;
            cub->map.mapy = (cub->ray.ystep == 1) ? (int)(cub->ray.ny) : (int)(cub->ray.ny)-1 ;
            cub->ray.hit_side = HORIZ;
        }
        if (cub->map.map[cub->map.mapy][cub->map.mapx] < 0)
			break ;
        if (cub->map.map[cub->map.mapy][cub->map.mapx] == 1)
		{
            if (cub->ray.hit_side == VERT)
			{
                cub->ray.wdir = (cub->ray.xstep > 0) ? DIR_E : DIR_W;
                cub->ray.wx = cub->ray.nx;
                cub->ray.wy = cub->ray.f;
			}
            else
			{
                cub->ray.wdir = (cub->ray.ystep > 0) ? DIR_N : DIR_S;
                cub->ray.wx = cub->ray.g;
                cub->ray.wy = cub->ray.ny;
            }
            cub->ray.hit = 1;
            break ;
        }
		cub->sp.vis[cub->map.mapy][cub->map.mapx] = 1;
        if (cub->ray.hit_side == VERT)
			cub->ray.nx += cub->ray.xstep;
        else
			cub->ray.ny += cub->ray.ystep;
    }
    return cub->ray.hit;
}


int					ft_raycasting(t_cub *cub)
{
	ft_minimap(cub);
	cub->ray.ray_cast = 0;
	while (cub->ray.ray_cast < cub->scr.sx)
	{
		cub->ray.ray = cub->player.th + cub->player.fovh_2 - (cub->player.per_fov_h * cub->ray.ray_cast);
		if ((ft_dda(cub)) == 0)
		{
			printf("Cub3D Error: map file is not valid\n");
			ft_exit(cub);
		}
		ft_render(cub);
		cub->sp.zbuf[cub->ray.ray_cast] = cub->ray.dist;
		cub->ray.ray_cast++;
	}
	ft_sprite(cub);
	if (cub->bmp.save == 1)
		ft_save(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	return (1);
}