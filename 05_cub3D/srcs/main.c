# include "cub.h"

void			load_data(t_cub *cub)
{
	int			i;

	ft_parsing(cub);
	printf("###### %d %d\n", cub->map.mx, cub->map.my);
	ft_texture(cub);
	ft_screen(cub);
	ft_player(cub);
	cub->sp.zbuf = (double *)malloc(sizeof(double) * cub->map.r[0]);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.img, &cub->img.bpp, \
									&cub->img.size_line, &cub->img.endian);
	cub->sp.vis = (int **)malloc(sizeof(int *) * cub->map.my);
	i = 0;
	while (i < cub->map.my)
	{
		cub->sp.vis[i] = (int *)malloc(sizeof(int) * cub->map.mx);
		i++;
	}
}

void			ft_exception(int argc, char **argv, t_cub *cub)
{
	if (argc > 3 || argc < 2)
	{
		printf("Cub3D Error: Invalid number of input values");
		exit(0);
	}
	if (argc == 2 && !ft_strncmp(argv[1], "cub.map", 7))
	{
		printf("Cub3D Error: Invalid name of Mapfile");
		exit(0);
	}
	if (argc == 3 && (!ft_strncmp(argv[1], "cub.map", 7) \
					|| !ft_strncmp(argv[2], "--save", 6)))
	{
		printf("Cub3D Error: Invalid name of Inputs");
		exit(0);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		cub->save = 1;
}

int				main(int argc, char **argv)
{
	t_cub		cub;

	ft_exception(argc, argv, &cub);
	cub.mlx.mlx = mlx_init();
	load_data(&cub);
	mlx_loop_hook(cub.mlx.mlx, ft_raycasting, &cub);
	mlx_hook(cub.mlx.win, EVENT_KEY_PRESS, 0, ft_key, &cub);
	mlx_loop(cub.mlx.mlx);
	return (0);
}
