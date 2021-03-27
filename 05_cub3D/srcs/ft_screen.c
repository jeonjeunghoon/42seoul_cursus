#include "../mms/mlxbeta.h"
#include "cub.h"

int				ft_exit(t_cub *cub)
{
	int			i;

	if (cub->mlx.win)
	{
		mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	}
	i = 0;
	while (i < 8)
	{
		free(cub->tex.texture[i]);
		i++;
	}
	free(cub->tex.texture);
	free(cub->sp.zbuf);
	exit(0);
	return (0);
}

void			ft_screen(t_cub *cub)
{
	mlx_get_screen_size(cub->mlx.mlx, &cub->scr.sx, &cub->scr.sy);
	if (cub->scr.sx < SX || cub->scr.sy < SY)
	{
		cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->scr.sx, cub->scr.sy, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx.mlx, cub->scr.sx, cub->scr.sy);
	}
	else
	{
		cub->mlx.win = mlx_new_window(cub->mlx.mlx, SX, SY, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx.mlx, SX, SY);
		cub->scr.sx = SX;
		cub->scr.sy = SY;
	}
}