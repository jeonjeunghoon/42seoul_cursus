# include "cub.h"

void			load_image(t_cub *cub, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(cub->mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
			texture[img->width * y + x] = img->data[img->width * y + x];
	}
	mlx_destroy_image(cub->mlx, img->img);
}

void			load_texture(t_cub *cub)
{
	t_img		img;

	load_image(cub, cub->texture[0], "textures/creeper.xpm", &img);
	load_image(cub, cub->texture[1], "textures/yellowmonster.xpm", &img);
	load_image(cub, cub->texture[2], "textures/zombie.xpm", &img);
	load_image(cub, cub->texture[3], "textures/halloween.xpm", &img);
	load_image(cub, cub->texture[4], "textures/grass.xpm", &img);
	load_image(cub, cub->texture[5], "textures/diamond.xpm", &img);
	load_image(cub, cub->texture[6], "textures/sprite.xpm", &img);
	load_image(cub, cub->texture[7], "textures/wood.xpm", &img);
}

int				get_texture_color(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->texture[cub->w_dir][ty * TW + tx];
	return (color);
}

void			wall_render(t_cub *cub, int wall_start, int wall_end, int wall_h)
{
	double		tx_ratio;
	int			color;
	int 		tx;
	int 		ty;

	if (cub->w_dir == DIR_W || cub->w_dir == DIR_E)
		tx_ratio = cub->wy - floor(cub->wy);
	else
		tx_ratio = cub->wx - floor(cub->wx);
	tx = (int)(tx_ratio * TW / WALL_H);
	int add = 0;
	if (wall_start < 0)
		add = wall_start * -1;
	wall_start = get_bigger(0, wall_start);
	for (int y = wall_start; y < wall_end; y++)
	{
		ty = (int)((y - wall_start + add) * TH / wall_h);
		color = get_texture_color(cub, tx, ty);
		cub->img.data[y * cub->sw + cub->ray_cast] = color;
	}
}