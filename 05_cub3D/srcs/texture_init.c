/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/03 20:40:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				wall_render(t_cub *cub, int y0, int y1, int wh)
{
	int				color;
	int				y;

	if (cub->ray.wdir == DIR_W || cub->ray.wdir == DIR_E)
		cub->tex.txratio = cub->ray.wy - floor(cub->ray.wy);
	else
		cub->tex.txratio = cub->ray.wx - floor(cub->ray.wx);
	cub->tex.tx = (int)(cub->tex.txratio * TW);
	y = get_max(0, y0);
	while (y <= y1)
	{
		cub->tex.ty = (int)((y - y0) * TH / wh);
		color = get_texture_color(cub, cub->tex.tx, cub->tex.ty);
		draw_pixel(cub, cub->ray.ray_cast, y, color);
		y++;
	}
}

void				check_path(t_cub *cub, char *path)
{
	int				check_file;

	check_file = open(path, O_RDONLY);
	if (check_file == -1)
	{
		perror("Cub3D Error");
		ft_exit(cub);
	}
}

void				load_image(t_cub *cub, int *texture, char *path)
{
	int				x;
	int				y;

	check_path(cub, path);
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
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
}

void				get_texture(t_cub *cub)
{
	t_img			img;

	load_image(cub, cub->tex.texture[0], cub->map.ea);
	load_image(cub, cub->tex.texture[1], cub->map.no);
	load_image(cub, cub->tex.texture[2], cub->map.we);
	load_image(cub, cub->tex.texture[3], cub->map.so);
	load_image(cub, cub->tex.texture[4], cub->map.s);
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
