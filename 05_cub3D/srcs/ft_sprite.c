#include "cub.h"

static int		cmp_sprites( const void* a, const void* b )
{
    return (((const t_sprite*)a)->dist > ((const t_sprite*)b)->dist) ? -1 : 1;
}

t_sprite		*ft_realloc(t_sprite *sp, int size)
{
	if (sp)
	{
		free(sp);
		sp = (t_sprite *)malloc(size);
		return (sp);
	}
	return (0);
}

t_sprite		*get_visible_sprites(t_cub *cub, t_sprite *sprite, int *pcnt)
{
	int			n;
	t_sprite	*sp;

	n = 0;
	sp = NULL;
	for (int x = 0; x < MH; x++)
	{
		for (int y = 0; y < MW; y++)
		{
			if (cub->map[x][y] < 2)
				continue ;
			if (n == 0)
				sp = (t_sprite *)malloc(sizeof(t_sprite));
			else
				sp = (t_sprite *)realloc(sp, sizeof(t_sprite) * (n + 1));
			sp[n].tex = 6;
            sp[n].x = x;
            sp[n].y = y;
            sp[n].th = atan2((y+0.5)-(cub->py), (x+0.5)-(cub->px));
            if( sp[n].th < 0 )
				sp[n].th += M_2_PI;
            sp[n].dist = ft_dist(cub->px, cub->py, x + 0.5, y + 0.5) * cos(cub->pth - sp[n].th);
            n++;
		}
	}
	*pcnt = n;
    return (sp);
}

void			ft_sprite(t_cub *cub, t_sprite *sprite)
{
	int			nsp;
	t_sprite	*sp;
	int			sh;
	double		angle;
	double		PIXEL_PER_ANGLE = (cub->sw - 1) / cub->fov_w;

	nsp = 0;
	sp = get_visible_sprites(cub, sprite, &nsp);
	// ft_qsort(sp, nsp, sizeof(t_sprite));
	qsort(sp, nsp, sizeof(t_sprite), cmp_sprites);
	for (int i = 0; i < nsp; i++)
	{
		sh = get_wall_height(cub, sp[i].dist);
		printf("sh===%d\n", sh);
		angle = sp[i].th - cub->pth;
		if (angle > M_PI)
			angle -= M_PI_2;
		else if (angle < -M_PI)
			angle += M_PI_2;

		int cx = (int)((cub->half_fov_w - angle) * PIXEL_PER_ANGLE);
		cub->w_dir = sp[i].tex;
		int xmin = get_bigger(0, cx - sh/2); /* clipping */
        int xmax = get_lower(cub->sw, cx + sh/2);
        for (int x = xmin; x < xmax; x++)
		{
            if (sp[i].dist > sprite->zbuf[x])
				continue ; /* behind wall */
            if (sp[i].dist < 0)
				continue ; /* too close */

            double tx_ratio = (double)(x-cx)/sh + 0.5;
            int tx = (int)(tx_ratio * 120); /* texture col # */
            int y0 = (int)((cub->sh - sh)/2.0);

            for( int y=get_bigger(0, y0); y<get_lower(cub->sh, y0+sh); y++ ) {
                int ty = (int)((double)(y-y0) * 120 / sh); /* texture row # */
                int color = get_texture_color(cub, tx, ty);
                if ( (color & 0x00ffffff) == 0 )
					continue ; /* black == transparent */
				cub->img.data[y * cub->sw + x] = color;
            }
        }
	}
    if (nsp > 0)
		free(sp);
}