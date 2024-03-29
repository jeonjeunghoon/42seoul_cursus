/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/16 10:57:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				check_path(char *path)
{
	int				check_file;

	check_file = open(path, O_RDONLY);
	if (check_file == -1)
	{
		perror("Cub3D Error");
		exit(0);
	}
}

void				load_image(t_cub *cub, int *texture, char *path)
{
	int				x;
	int				y;

	check_path(path);
	cub->img.img = mlx_xpm_file_to_image(cub->mlx.mlx, path, &cub->img.width, \
															&cub->img.height);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.img, &cub->img.bpp, \
									&cub->img.size_line, &cub->img.endian);
	y = 0;
	while (y < cub->img.height)
	{
		x = 0;
		while (x < cub->img.width)
		{
			texture[cub->img.width * y + x] = \
			cub->img.data[cub->img.width * y + x];
			x++;
		}
		y++;
	}
}

void				get_texture(t_cub *cub)
{
	load_image(cub, cub->tex.texture[0], cub->map.ea);
	cub->tex.e_h = cub->img.height;
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	load_image(cub, cub->tex.texture[1], cub->map.no);
	cub->tex.w_h = cub->img.height;
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	load_image(cub, cub->tex.texture[2], cub->map.we);
	cub->tex.s_h = cub->img.height;
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	load_image(cub, cub->tex.texture[3], cub->map.so);
	cub->tex.n_h = cub->img.height;
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	load_image(cub, cub->tex.texture[4], cub->map.s);
	cub->sp.h = cub->img.height;
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	free(cub->map.ea);
	free(cub->map.no);
	free(cub->map.we);
	free(cub->map.so);
	free(cub->map.s);
}

void				texture_init(t_cub *cub)
{
	int				i;
	int				j;

	cub->tex.texture = (int **)malloc(sizeof(int *) * 5);
	i = 0;
	while (i < 5)
		cub->tex.texture[i++] = (int *)malloc(sizeof(int) * (TW * TH));
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TW * TH)
		{
			cub->tex.texture[i][j] = 0;
			j++;
		}
		i++;
	}
	get_texture(cub);
}
