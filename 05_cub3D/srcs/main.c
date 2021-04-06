/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:10:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/06 22:17:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				load_data(t_cub *cub)
{
	int				i;

	parsing_init(cub);
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
	if (argc == 3 || argc == 2)
	{
		if (argc == 3 && \
		(ft_strlen(argv[1]) == ft_strlen("cub.map")) && \
		(ft_strlen(argv[2]) == ft_strlen("--save")))
		{
			if ((ft_strncmp(argv[1], "cub.map", ft_strlen("cub.map")) != 1))
				ft_exit("Cub3D Error: Invalid arguments");
			if ((ft_strncmp(argv[2], "--save", ft_strlen("--save")) != 1))
				ft_exit("Cub3D Error: Invalid arguments");
			cub->save = 1;
			return ;
		}
		else if (argc == 2 && \
		(ft_strlen(argv[1]) == ft_strlen("cub.map")))
		{
			if ((ft_strncmp(argv[1], "cub.map", ft_strlen("cub.map")) != 1))
				ft_exit("Cub3D Error: Invalid arguments");
			return ;
		}
	}
	ft_exit("Cub3D Error: Invalid arguments");
}

int					main(int argc, char **argv)
{
	t_cub			cub;

	ft_exception(argc, argv, &cub);
	cub.mlx.mlx = mlx_init();
	load_data(&cub);
	mlx_loop_hook(cub.mlx.mlx, ft_raycasting, &cub);
	mlx_hook(cub.mlx.win, EVENT_KEY_PRESS, 0, ft_key, &cub);
	mlx_hook(cub.mlx.win, EVENT_EXIT, 0, ft_exit, &cub);
	mlx_loop(cub.mlx.mlx);
	return (0);
}
