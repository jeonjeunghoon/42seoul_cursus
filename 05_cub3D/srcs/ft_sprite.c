#include "cub.h"

unsigned int		get_sprite(t_cub *cub, int tx, int ty)
{
	unsigned int	color;

	color = cub->texture[6][ty * 120 + tx];
	return (color);
}

void			sprite_render(t_cub *cub, int wall_start, int wall_end, int wall_h)
{
	double			tx_ratio;
	unsigned int	color;
	int 			tx;
	int 			ty;

	if (cub->w_dir == DIR_W || cub->w_dir == DIR_E)
		tx_ratio = cub->wy - floor(cub->wy);
	else
		tx_ratio = cub->wx - floor(cub->wx);
	tx = (int)(tx_ratio * 120 / WALL_H);
	int add = 0;
	if (wall_start < 0)
		add = wall_start * -1;
	wall_start = get_bigger(0, wall_start);
	for (int y = wall_start; y < wall_end; y++)
	{
		ty = (int)((y - wall_start + add) * 120 / wall_h);
		color = get_sprite(cub, tx, ty);
		if ((color & 0x00ffffff) == 0)
			continue ;
		cub->img.data[y * cub->sw + cub->ray_cast] = color;
	}
}

void			ft_sprite(t_cub *cub, t_sprite *sprite)
{
	int				sprite_h;
	int				sprite_start;
	int				sprite_end;

	cub->dist = ft_dist(cub->px, cub->py, cub->wx + 0.5, cub->wy + 0.5);
	cub->dist *= cos(cub->pth - cub->ray_th); // 어안렌즈 현상 보정
	sprite_h = (int)((cub->sh) * (WALL_H/(2.0 * cub->dist * tan(cub->fov_w/2.0))));
	sprite_start = (int)((cub->sh - sprite_h)/2.0);
	sprite_end = sprite_start + sprite_h - 1;
	sprite_end = get_lower(cub->sh - 1, sprite_end);
	sprite_render(cub, sprite_start, sprite_end, sprite_h);
}