# include "cub.h"

void				load_image(t_cub *cub, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	printf("%d\n", img->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
			texture[img->width * y + x] = img->data[img->width * y + x];
	}
	mlx_destroy_image(cub->mlx, img->img);
}

void				load_texture(t_cub *cub)
{
	t_img			img;

	load_image(cub, cub->texture[0], "textures/wall_e.xpm", &img);
	load_image(cub, cub->texture[1], "textures/wall_n.xpm", &img);
	load_image(cub, cub->texture[2], "textures/wall_w.xpm", &img);
	load_image(cub, cub->texture[3], "textures/wall_s.xpm", &img);
}

unsigned int		get_texture_color(t_cub *cub, int tx, int ty)
{
	unsigned int	color;

	if (cub->w_dir == DIR_E)
		color = cub->texture[0][ty * TW + tx];
	else if (cub->w_dir == DIR_N)
		color = cub->texture[1][ty * TW + tx];
	else if (cub->w_dir == DIR_W)
		color = cub->texture[2][ty * TW + tx];
	else if (cub->w_dir == DIR_S)
		color = cub->texture[3][ty * TW + tx];
	return (color);
}

void				wall_render(t_cub *cub, int wall_start, int wall_end, int f)
{
	double			tx_ratio;
	unsigned int	color;
	int 			tx;
	int 			ty;

	if (cub->w_dir == DIR_W || cub->w_dir == DIR_E)
		tx_ratio = cub->wy - floor(cub->wy);
	else
		tx_ratio = cub->wx - floor(cub->wx);
	tx = (int)(tx_ratio * (TW / WALL_H));
	while (wall_start <= wall_end)
	{
		ty = (int)(wall_start - f) * (TH / WALL_H);
		color = get_texture_color(cub, tx, ty);
		cub->img.data[wall_start * cub->sw + cub->ray_cast] = color;
		wall_start++;
	}
}