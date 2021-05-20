/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeunghoon <jeonjeunghoon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:10:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/16 20:14:25 by jeonjeungho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				load_data(t_cub *cub, char *argv)
{
	int				i;

	parsing_init(cub, argv);
	texture_init(cub);
	screen_init(cub);
	player_init(cub);
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

void				ft_exception(int argc, char **argv, t_cub *cub)
{
	if (argc != 2 && argc != 3)
		ft_exit("Cub3D Error! Invalid arguments\n\nTo input 1 or 2\n1) ./cub3D map/map.cub\n2) ./cub3D map/map.cub --save");
	if (argc == 2 || argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			ft_exit("Cub3D Error! Invalid arguments");
		if (argc == 3 && \
		(ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0 \
		|| (ft_strlen(argv[2]) != ft_strlen("--save"))))
			ft_exit("Cub3D Error! Invalid arguments");
	}
	if (argc == 3)
		cub->save = 1;
}

int					main(int argc, char **argv)
{
	t_cub			cub;

	ft_exception(argc, argv, &cub);
	cub.mlx.mlx = mlx_init();
	load_data(&cub, argv[1]);
	mlx_loop_hook(cub.mlx.mlx, ft_raycasting, &cub);
	mlx_hook(cub.mlx.win, EVENT_KEY_PRESS, 0, ft_key, &cub);
	mlx_hook(cub.mlx.win, EVENT_EXIT, 0, ft_exit, "Exit Cub3D\n");
	mlx_loop(cub.mlx.mlx);
	return (0);
}
