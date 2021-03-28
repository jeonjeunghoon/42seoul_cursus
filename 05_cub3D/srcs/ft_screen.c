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
	int			sx;
	int			sy;

	mlx_get_screen_size(cub->mlx.mlx, &sx, &sy);
	if (cub->map.r[0] > sx || cub->map.r[1] > sy)
	{
		cub->map.r[0] = sx;
		cub->map.r[1] = sy;
	}
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->map.r[0], cub->map.r[1], "cub3D");
	cub->img.img = mlx_new_image(cub->mlx.mlx, cub->map.r[0], cub->map.r[1]);
}