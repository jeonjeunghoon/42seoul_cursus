#include "cub.h"

void			draw_ray(t_cub *cub, int hit_side, double slope)
{
	int			start;
	int			end;
	int			tx;
	int			ty;

	if (hit_side == VERT)
	{
		tx = (int)cub->ray.wx * TILE;
		ty = (int)f * TILE;
	}
	else
	{
		tx = (int)g * TILE;
		ty = (int)cub->ray.wy * TILE;
	}
	start = 0;
	end = TILE;
	while (start < end)
	{
		draw_pixel(cub, tx + start, ty, 0xFF0000);
		start++;
	}
}

void			draw_tile(t_cub *cub, double x, double y, int color)
{
	int			tx;
	int			ty;

	ty = y * TILE;
	while (ty < (y + 1) * TILE)
	{
		tx = x * TILE;
		while (tx < (x + 1) * TILE)
		{
			if (ty == y * TILE || ty == (y + 1) * TILE - 1 ||
				tx == x * TILE || tx == (x + 1) * TILE - 1)
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
	int			z;

	y = 0;
	while (y < MY)
	{
		x = 0;
		while (x < MX)
		{
			if (cub->map[y][x] == 1)
				draw_tile(cub, x, y, 0xFFFFFF);
			else if (cub->map[y][x] == 2)
				draw_tile(cub, x, y, 0x00FF00);
			else
				draw_tile(cub, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_tile(cub, cub->player.x, cub->player.y, 0x0000FF);
}