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
	mlx_get_screen_size(cub->mlx, &cub->sw, &cub->sh);
	if (cub->sw < SW || cub->sh < SH)
	{
		cub->win = mlx_new_window(cub->mlx, cub->sw, cub->sh, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx, cub->sw, cub->sh);
	}
	else
	{
		cub->win = mlx_new_window(cub->mlx, SW, SH, "cub3D");
		cub->img.img = mlx_new_image(cub->mlx, SW, SH);
		cub->sw = SW;
		cub->sh = SH;
	}
}