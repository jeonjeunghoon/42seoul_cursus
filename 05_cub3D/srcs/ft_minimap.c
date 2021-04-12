/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/10 01:47:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				get_tile_size(t_cub *cub)
{
	int			tile;

	tile = cub->map.r[0] / 100;
	return (tile);
}

void			draw_tile(t_cub *cub, double x, double y, int color)
{
	int			tx;
	int			ty;
	int			tile;

	tile = get_tile_size(cub);
	ty = y * tile;
	while (ty < (y + 1) * tile)
	{
		tx = x * tile;
		while (tx < (x + 1) * tile)
		{
			if (ty == y * tile || ty == (y + 1) * tile - 1 ||
				tx == x * tile || tx == (x + 1) * tile - 1)
				draw_pixel(cub, tx, ty, 0x808080);
			else
				draw_pixel(cub, tx, ty, color);
			tx++;
		}
		ty++;
	}
}

void			ft_minimap(t_cub *cub)
{
	int			x;
	int			y;
	int			reverse_x;

	reverse_x = cub->map.mx - 1;
	y = 0;
	while (y < cub->map.my)
	{
		x = 0;
		while (x < cub->map.mx)
		{
			if (cub->map.map[y][x] == 1)
				draw_tile(cub, reverse_x - x, y, 0xFFFFFF);
			else if (cub->map.map[y][x] == 2)
				draw_tile(cub, reverse_x - x, y, 0x00FF00);
			else if (cub->map.map[y][x] == 0 || \
					cub->map.map[y][x] > 10)
				draw_tile(cub, reverse_x - x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_tile(cub, reverse_x - cub->player.x + 0.5, cub->player.y - 0.5, \
	0x0000FF);
}
