# include "cub.h"

/* main funcs */
void			ft_map(t_cub *cub)
{
	int			src[MH][MW] = {
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
					{1, 0, 0, 0, 'E', 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
				};

	ft_memcpy(cub->map, src, sizeof(int) * MH * MW);
}

int				ft_exit(void)
{
	exit(0);
	return (0);
}

int				main(void)
{
	t_cub		cub;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIN_SW, WIN_SH, "Cub3D");
	// mlx_get_screen_size(cub.mlx, &cub.sw, &cub.sh);
	// if (MAP_SW > cub.sw || MAP_SH > cub.sh)
	// 	cub.img = mlx_new_image(cub.mlx, cub.sw, cub.sh);
	// else
		cub.img = mlx_new_image(cub.mlx, MAP_SW, MAP_SH);
	cub.data = (int *)mlx_get_data_addr(cub.img, &cub.bpp, &cub.size_line, &cub.endian);
	ft_map(&cub);
	ft_player(&cub);
	ft_raycasting(&cub);
	mlx_hook(cub.win, EVENT_KEY_PRESS, 0, ft_key_press, &cub);
	mlx_hook(cub.win, EVENT_EXIT, 0, ft_exit, &cub);
	mlx_loop_hook(cub.mlx, ft_raycasting, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
