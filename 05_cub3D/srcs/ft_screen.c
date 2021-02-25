#include "../mms/mlxbeta.h"
#include "cub.h"

void	ft_screen(t_cub *cub)
{
	mlx_get_screen_size(cub->mlx, &cub->sw, &cub->sh);
	if (cub->sw < WIN_SW || cub->sh < WIN_SH)
	{
		cub->win = mlx_new_window(cub->mlx, cub->sw, cub->sh, "cub3D");
		cub->img = mlx_new_image(cub->mlx, cub->sw, cub->sh);
	}
	else
	{
		cub->win = mlx_new_window(cub->mlx, WIN_SW, WIN_SH, "cub3D");
		cub->img = mlx_new_image(cub->mlx, WIN_SW, WIN_SH);
		cub->sw = WIN_SW;
		cub->sh = WIN_SH;
	}
}