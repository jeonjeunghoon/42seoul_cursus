# include "cub.h"

int					get_wall_height(t_cub *cub, double dist)
{
    double			h;
	int				wall_h;

	h = 2.0 * dist * tan(cub->player.fov_v/2.0);
	wall_h = (int)(cub->sy * (WALL_H / h));
	return (wall_h);
}

void				ft_render(t_cub *cub)
{
	int				wh;
	int				y0;
	int				y1;

	cub->ray.dist = ft_dist(cub->player.x, cub->player.y, cub->ray.wx, cub->ray.wy);
	cub->ray.dist *= cos(cub->player.th - cub->ray.ray); // 어안렌즈 현상 보정
	wh = get_wall_height(cub, cub->ray.dist);
	y0 = (int)((cub->sy - wh)/2.0);
	y1 = y0 + wh - 1;
	y1 = get_min(cub->sy - 1, y1);
	int f = 0;
	while (f < y0 && y0 > 0)
		cub->img.data[f++ * cub->sx + cub->ray.ray_cast] = 0x000000;
	wall_render(cub, y0, y1, wh);
	while (y1 < cub->sy)
		cub->img.data[y1++ * cub->sx + cub->ray.ray_cast] = 0x000000;
}

int					ft_dda(t_cub *cub)
{
    int xstep = ft_sgn( cos(cub->ray.ray) );  /* +1 (right), 0 (no change), -1 (left) */
    int ystep = ft_sgn( sin(cub->ray.ray) );  /* +1 (up),    0 (no change), -1 (down) */

    double xslope = (xstep == 0) ? INFINITY : tan(cub->ray.ray);
    double yslope = (ystep == 0) ? INFINITY : 1./tan(cub->ray.ray);

    double nx = (xstep > 0) ? floor(cub->player.x)+1 : ((xstep < 0) ? ceil(cub->player.x)-1 : cub->player.x);
    double ny = (ystep > 0) ? floor(cub->player.y)+1 : ((ystep < 0) ? ceil(cub->player.y)-1 : cub->player.y);

    double f=INFINITY, g=INFINITY;
    int hit = 0;
    int hit_side; /* either VERT or HORIZ */

    while( !hit )
    {
        int mapx, mapy;

        if( xstep != 0 ) f = xslope * (nx-cub->player.x) + cub->player.y;
        if( ystep != 0 ) g = yslope * (ny-cub->player.y) + cub->player.x;

        /* which is nearer to me - VERT(nx,f) or HORIZ(g,ny)? */
        double dist_v = ft_dist(cub->player.x, cub->player.y, nx, f);
        double dist_h = ft_dist(cub->player.x, cub->player.y, g, ny);

        if( dist_v < dist_h ) { /* VERT is nearer; go along x-axis */
            mapx = (xstep == 1) ? (int)(nx) : (int)(nx)-1 ;
            mapy = (int) f;
            hit_side = VERT;
        }
        else {  /* HORIZ is nearer; go along y-axis */
            mapx = (int) g;
            mapy = (ystep == 1) ? (int)(ny) : (int)(ny)-1 ;
            hit_side = HORIZ;
        }
        int cell = get_cell(cub, mapx, mapy);
        if( cell < 0 ) break;   /* out of map */

        if( cell == 1 ) {   /* hit wall? */
            if( hit_side == VERT ) {
                cub->ray.wdir = (xstep > 0) ? DIR_W : DIR_E;
                cub->ray.wx = nx;
                cub->ray.wy = f;
            }
            else { /* HORIZ */
                cub->ray.wdir = (ystep > 0) ? DIR_S : DIR_N;
                cub->ray.wx = g;
                cub->ray.wy = ny;
            }
            hit = 1;
            break;
        }

        if( hit_side == VERT ) nx += xstep;
        else ny += ystep;
    }
    /* end of while(!hit) */

    return hit;
}


int					ft_raycasting(t_cub *cub)
{
	cub->ray.ray_cast = 0;
	while (cub->ray.ray_cast < cub->sx)
	{
		cub->ray.ray = cub->player.th + cub->player.fovh_2 - (cub->player.per_fov_h * cub->ray.ray_cast);
		if ((ft_dda(cub)) == 0)
		{
			printf("ERROR: MAP\n");
			return (INFINITY);
		}
		ft_render(cub);
		cub->sprite.zbuf[cub->ray.ray_cast] = cub->ray.dist;
		cub->ray.ray_cast++;
	}
	ft_sprite(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (1);
}