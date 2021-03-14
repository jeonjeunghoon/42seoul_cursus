#include "cub.h"

static int		cmp_sprites( const void* a, const void* b )
{
    return (((const t_sprite*)a)->dist > ((const t_sprite*)b)->dist) ? -1 : 1;
}

// t_sprite		*ft_realloc(t_sprite *sp, int size)
// {
// 	if (sp)
// 	{
// 		free(sp);
// 		sp = (t_sprite *)malloc(size);
// 		return (sp);
// 	}
// 	return (0);
// }

int				get_texture_color2(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->texture[cub->ray.wdir][ty * 120 + tx];
	return (color);
}

t_sprite		*get_visible_sprites(t_cub *cub, int *nsp)
{
	int			n;
	t_sprite	*sp;

	n = 0;
	sp = NULL;
	for (int x = 0; x < MX; x++) {
		for (int y = 0; y < MY; y++) {
			if (cub->ray.vis[x][y] == 0 || cub->map[x][y] <= 1)
				continue ;
			if (n == 0)
				sp = (t_sprite *)malloc(sizeof(t_sprite));
			else
				sp = (t_sprite *)realloc(sp, sizeof(t_sprite) * (n + 1));
			sp[n].tex = 6;
        	sp[n].x = x;
        	sp[n].y = y;
        	sp[n].th = atan2((y+0.5)-(cub->player.y), (x+0.5)-(cub->player.x));
        	if( sp[n].th < 0 )
				sp[n].th += M_2_PI;
        	sp[n].dist = ft_dist(cub->player.x, cub->player.y, x + 0.5, y + 0.5) * cos(cub->player.th - sp[n].th);
        	n++;
			
		}
	}
	*nsp = n;
    return (sp);
}

void			ft_sprite(t_cub *cub)
{
	int			nsp;
	t_sprite	*sp;
	int			sph;
	double		angle;
	double		PIXEL_PER_ANGLE = (cub->sx - 1) / cub->player.fov_h;

	nsp = 0;
	printf("0 ==== %d\n", nsp);
	sp = get_visible_sprites(cub, &nsp);
	printf("1 ==== %d\n", nsp);
	qsort(sp, nsp, sizeof(t_sprite), cmp_sprites);
	for (int i = 0; i < nsp; i++)
	{
		sph = get_wall_height(cub, sp[i].dist);
		angle = sp[i].th - cub->player.th;
		if (angle > deg_to_rad(180))
			angle -= deg_to_rad(90);
		else if (angle < -deg_to_rad(180))
			angle += deg_to_rad(90);

		int cx = (int)((cub->player.fovh_2 - angle) * PIXEL_PER_ANGLE);
		cub->ray.wdir = sp[i].tex;
		int xmin = get_max(0, cx - sph/2); /* clipping */
        int xmax = get_min(cub->sx, cx + sph/2);
        for (int x = xmin; x < xmax; x++)
		{
			// printf("x ===== %d\n", x);
            if (sp[i].dist > cub->sprite.zbuf[x])
				continue ; /* behind wall */
            if (sp[i].dist <= 0)
				continue ; /* too close */

			double tx_ratio = (double)(x-cx)/sph + 0.5;
            int tx = (int)(tx_ratio * 120); /* texture col # */
            int y0 = (int)((cub->sy - sph)/2.0);
			int y1 = (int)((y0 + sph) / 2.0);
			y0 = get_max(0, y0);
			y1 = get_min(cub->sy - 1, y1);
            for( int y = y0; y < y1; y++ ) {
                int ty = (int)((double)(y-y0) * 120 / sph); /* texture row # */
                int color = get_texture_color2(cub, tx, ty);
                if ( (color & 0x00ffffff) == 0 )
					continue ; /* black == transparent */
				cub->img.data[(y * cub->sx) + x] = color;
            }
        }
	}
    if (nsp > 0)
		free(sp);
	nsp = 0;
}