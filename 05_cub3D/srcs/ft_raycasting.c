/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/05 16:33:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				ray_init(t_cub *cub)
{
	cub->ray.xstep = ft_sgn(cos(cub->ray.ray));
	cub->ray.ystep = ft_sgn(sin(cub->ray.ray));
	if (cub->ray.xstep == 0)
		cub->ray.xslope = INFINITY;
	else
		cub->ray.xslope = tan(cub->ray.ray);
	if (cub->ray.ystep == 0)
		cub->ray.yslope = INFINITY;
	else
		cub->ray.yslope = 1. / tan(cub->ray.ray);
	if (cub->ray.xstep > 0)
		cub->ray.nx = floor(cub->player.x) + 1;
	else if (cub->ray.xstep < 0)
		cub->ray.nx = ceil(cub->player.x) - 1;
	else
		cub->ray.nx = cub->player.x;
	if (cub->ray.ystep > 0)
		cub->ray.ny = floor(cub->player.y) + 1;
	else if (cub->ray.ystep < 0)
		cub->ray.ny = ceil(cub->player.y) - 1;
	else
		cub->ray.ny = cub->player.y;
	cub->ray.f = INFINITY;
	cub->ray.g = INFINITY;
	cub->ray.hit = 0;
}

void				hitting(t_cub *cub)
{
	cub->ray.dist_v = \
	ft_dist(cub->player.x, cub->player.y, cub->ray.nx, cub->ray.f);
	cub->ray.dist_h = \
	ft_dist(cub->player.x, cub->player.y, cub->ray.g, cub->ray.ny);
	if (cub->ray.dist_v < cub->ray.dist_h)
	{
		if (cub->ray.xstep == 1)
			cub->map.mapx = (int)(cub->ray.nx);
		else
			cub->map.mapx = (int)(cub->ray.nx) - 1;
		cub->map.mapy = (int)cub->ray.f;
		cub->ray.hit_side = VERT;
	}
	else
	{
		cub->map.mapx = (int)cub->ray.g;
		if (cub->ray.ystep == 1)
			cub->map.mapy = (int)(cub->ray.ny);
		else
			cub->map.mapy = (int)(cub->ray.ny) - 1;
		cub->ray.hit_side = HORIZ;
	}
}

int					is_hit(t_cub *cub)
{
	if (cub->map.map[cub->map.mapy][cub->map.mapx] == 1)
	{
		if (cub->ray.hit_side == VERT)
		{
			if (cub->ray.xstep > 0)
				cub->ray.wdir = DIR_W;
			else
				cub->ray.wdir = DIR_E;
			cub->ray.wx = cub->ray.nx;
			cub->ray.wy = cub->ray.f;
		}
		else
		{
			if (cub->ray.ystep > 0)
				cub->ray.wdir = DIR_S;
			else
				cub->ray.wdir = DIR_N;
			cub->ray.wx = cub->ray.g;
			cub->ray.wy = cub->ray.ny;
		}
		cub->ray.hit = 1;
		return (0);
	}
	return (1);
}

int					ft_dda(t_cub *cub)
{
	ray_init(cub);
	while (!cub->ray.hit)
	{
		if (cub->ray.xstep != 0)
			cub->ray.f = \
			cub->ray.xslope * (cub->ray.nx - cub->player.x) + cub->player.y;
		if (cub->ray.ystep != 0)
			cub->ray.g = \
			cub->ray.yslope * (cub->ray.ny - cub->player.y) + cub->player.x;
		hitting(cub);
		if (cub->map.map[cub->map.mapy][cub->map.mapx] < 0)
			return (0);
		if ((is_hit(cub) == 0))
			break ;
		cub->sp.vis[cub->map.mapy][cub->map.mapx] = 1;
		if (cub->ray.hit_side == VERT)
			cub->ray.nx += cub->ray.xstep;
		else
			cub->ray.ny += cub->ray.ystep;
	}
	return (cub->ray.hit);
}

int					ft_raycasting(t_cub *cub)
{
	cub->ray.ray_cast = 0;
	while (cub->ray.ray_cast < cub->map.r[0])
	{
		cub->ray.ray = cub->player.th + \
		cub->player.fovh_2 - (cub->player.per_fov_h * cub->ray.ray_cast);
		if ((ft_dda(cub)) == 0)
		{
			printf("Cub3D Error: map file is not valid\n");
			ft_exit(cub);
		}
		ft_render(cub);
		cub->sp.zbuf[cub->ray.ray_cast] = cub->ray.dist;
		cub->ray.ray_cast++;
	}
	ft_minimap(cub);
	ft_sprite(cub);
	if (cub->save == 1)
		ft_save(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	return (1);
}
