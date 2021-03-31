#include "cub.h"

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

	y = 0;
	while (y < cub->map.my)
	{
		x = 0;
		while (x < (cub->map.mx))
		{
			if (cub->map.map[cub->map.my - 1 - y][x] == 1)
				draw_tile(cub, x, y, 0xFFFFFF);
			else if (cub->map.map[cub->map.my - 1 - y][x] == 2)
				draw_tile(cub, x, y, 0x00FF00);
			else if (cub->map.map[cub->map.my - 1 - y][x] == 0 || cub->map.map[cub->map.my - 1 - y][x] > 2)
				draw_tile(cub, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_tile(cub, cub->player.x - 0.5, cub->map.my - cub->player.y - 0.5, 0x0000FF);
}