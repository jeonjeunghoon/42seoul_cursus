/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/02 23:42:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		cmp_sprites(const void* a, const void* b)
{
    return (((const t_sprite*)a)->dist > ((const t_sprite*)b)->dist) ? -1 : 1;
}

int				get_sprite_color(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->tex.texture[cub->ray.wdir][ty * 120 + tx];
	return (color);
}

t_sprite		*get_visible_sprites(t_cub *cub)
{
	int			n;
	t_sprite	*sp;

	n = 0;
	sp = NULL;
	for (int y = 0; y < cub->map.my; y++) {
		for (int x = 0; x < cub->map.mx; x++) {
			if( cub->sp.vis[y][x] == 0 || cub->map.map[y][x] != 2)
                continue;
			if (n == 0)
				sp = (t_sprite *)malloc(sizeof(t_sprite));
			else
				sp = sprite_realloc(sp, n);
			sp[n].tex = DIR_SP;
        	sp[n].x = x + 0.5;
        	sp[n].y = y + 0.5;
        	sp[n].th = atan2(sp[n].y - cub->player.y, sp[n].x - cub->player.x);
        	if( sp[n].th < 0 )
				sp[n].th += deg_to_rad(360);
        	sp[n].dist = ft_dist(cub->player.x, cub->player.y, sp[n].x, sp[n].y);
			sp[n].dist *= cos(cub->player.th - sp[n].th);
        	n++;
		}
	}
	cub->sp.nsp = n;
    return (sp);
}

void			ft_sprite(t_cub *cub)
{
	t_sprite	*sp;
	int			sph;
	double		angle;
	double		pixel_per_angle;

	pixel_per_angle = (cub->map.r[0] - 1) / cub->player.fov_h;
	sp = get_visible_sprites(cub);
	qsort(sp, cub->sp.nsp, sizeof(t_sprite), cmp_sprites);
	// ft_qsort(sp, cub->sp.nsp, sizeof(t_sprite));
	for (int i = 0; i < cub->sp.nsp; i++)
	{
		sph = get_wall_height(cub, sp[i].dist);
		double lum = get_luminosity(cub, sp[i].dist);
		cub->ray.wdir = sp[i].tex;
		angle = sp[i].th - cub->player.th;
		if (angle > M_PI)
			angle -= M_PI * 2;
		else if (angle < -M_PI)
			angle += M_PI * 2;
		int cx = (int)((cub->player.fovh_2 - angle) * pixel_per_angle);
		int xmin = get_max(0, cx - sph/2); /* clipping */
		int xmax = get_min(cub->map.r[0], cx + sph/2);
		for (int x = xmin; x < xmax; x++)
		{
			if (sp[i].dist > cub->sp.zbuf[x])
				continue ;
			if (sp[i].dist <= 0.5)
				continue ;
			double txratio = (double)(x-cx)/sph + 0.5;
			int tx = (int)(txratio * 120); /* texture col # */
			int y0 = (int)((cub->map.r[1] - sph)/2.0);
			int y1 = y0 + sph;
			int add = 0;
			if (y0 < 0)
				add = y0 * -1;
			y0 = get_max(0, y0);
			y1 = get_min(cub->map.r[1], y1);
			for( int y = y0; y < y1; y++ ) {
				int ty = (int)((double)(y - y0 + add) * 120 / sph); /* texture row # */
				int color = get_sprite_color(cub, tx, ty);
				if ( (color & 0x00ffffff) == 0 || (y < TILE * cub->map.my && x < TILE * cub->map.mx))
					continue ; /* black == transparent */
				color = fade_color(color, lum);
				draw_pixel(cub, x, y, color);
			}
		}
	}
	if (cub->sp.nsp > 0)
		ft_free((void *)&sp);
}
