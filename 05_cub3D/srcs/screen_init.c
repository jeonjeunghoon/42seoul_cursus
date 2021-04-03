/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:13:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/03 20:28:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mms/mlxbeta.h"
#include "cub.h"

int				ft_exit(t_cub *cub)
{
	if (cub->img.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	if (cub->mlx.win)
	{
		mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	}
	exit(0);
	return (0);
}

void			screen_init(t_cub *cub)
{
	int			sx;
	int			sy;

	mlx_get_screen_size(cub->mlx.mlx, &sx, &sy);
	if (cub->map.r[0] > sx || cub->map.r[1] > sy)
	{
		cub->map.r[0] = sx;
		cub->map.r[1] = sy;
	}
	cub->mlx.win = \
	mlx_new_window(cub->mlx.mlx, cub->map.r[0], cub->map.r[1], "cub3D");
	cub->img.img = \
	mlx_new_image(cub->mlx.mlx, cub->map.r[0], cub->map.r[1]);
}
