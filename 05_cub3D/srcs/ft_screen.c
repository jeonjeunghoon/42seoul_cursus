#include "../mms/mlxbeta.h"
#include "cub.h"

int				ft_exit(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

void			ft_screen(t_cub *cub)
{
	mlx_get_screen_size(cub->mlx, &cub->sx, &cub->sy);
	if (cub->sx < SX || cub->sy < SY)
	{
		cub->win = mlx_new_window(cub->mlx, cub->sx, cub->sy, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx, cub->sx, cub->sy);
	}
	else
	{
		cub->win = mlx_new_window(cub->mlx, SX, SY, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx, SX, SY);
		cub->sx = SX;
		cub->sy = SY;
	}
}