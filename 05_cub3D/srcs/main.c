# include "cub.h"

/* main funcs */
void			ft_map(t_cub *cub)
{
	int			src[MX][MY] = {
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
  					{1,1,1,1,1,1,1,1,1,1,0,'E',0,1,1,1,1,1,1,1,1,1,1,1},
  					{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
				};

	ft_memcpy(cub->map, src, sizeof(int) * MX * MY);
}

int				main(int argc, char **argv)
{
	t_cub		cub;

	if (argc > 3)
		printf("wrong usage\n");
	// else if (argc == 2)
	// 	// --save
	else
	{
		cub.mlx = mlx_init();
		cub.texture = (int **)malloc(sizeof(int *) * 8); // free 필요
		for (int i = 0; i < 8; i++)
			cub.texture[i] = (int *)malloc(sizeof(int) * (TW * TH)); // free 필요
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < TW * TH; j++)
				cub.texture[i][j] = 0;
		load_texture(&cub);
		ft_screen(&cub);
		ft_map(&cub);
		ft_player(&cub);
		cub.sprite.zbuf = (double *)malloc(sizeof(double) * cub.sx); // free 필요
		cub.img.data = (int *)mlx_get_data_addr(cub.img.img, &cub.img.bpp, &cub.img.size_line, &cub.img.endian);
		mlx_loop_hook(cub.mlx, ft_raycasting, &cub);
		mlx_hook(cub.win, EVENT_KEY_PRESS, 0, ft_key_press, &cub);
		mlx_hook(cub.win, EVENT_EXIT, 0, ft_exit, &cub);
		mlx_loop(cub.mlx);
	}
	return (0);
}
