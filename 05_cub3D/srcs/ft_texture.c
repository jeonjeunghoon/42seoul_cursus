# include "cub.h"

int				get_texture_color(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->texture[cub->ray.wdir][ty * TW + tx];
	return (color);
}

void			wall_render(t_cub *cub, int y0, int y1, int wh)
{
	double		tx_ratio;
	int			color;
	int 		tx;
	int 		ty;

	if (cub->ray.wdir == DIR_W || cub->ray.wdir == DIR_E)
		tx_ratio = cub->ray.wy - floor(cub->ray.wy);
	else
		tx_ratio = cub->ray.wx - floor(cub->ray.wx);
	tx = (int)(tx_ratio * TW);
	int add = 0;
	if (y0 < 0)
		add = y0 * -1;
	y0 = get_max(0, y0);
	for (int y = y0; y < y1; y++)
	{
		ty = (int)((y - y0 + add) * TH / wh);
		color = get_texture_color(cub, tx, ty);
		cub->img.data[y * cub->sx + cub->ray.ray_cast] = color;
	}
}

void			load_image(t_cub *cub, int *texture, char *path)
{
	int			x;
	int			y;

	cub->img.img = mlx_xpm_file_to_image(cub->mlx, path, &cub->img.width, &cub->img.height);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.img, &cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	y = 0;
	while (y < cub->img.height)
	{
		x = 0;
		while (x < cub->img.width)
		{
			texture[cub->img.width * y + x] = cub->img.data[cub->img.width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, cub->img.img);
}

void			load_texture(t_cub *cub)
{
	t_img		img;

	load_image(cub, cub->texture[0], "textures/creeper.xpm");			// E
	load_image(cub, cub->texture[1], "textures/yellowmonster.xpm");	// N
	load_image(cub, cub->texture[2], "textures/zombie.xpm");			// W
	load_image(cub, cub->texture[3], "textures/halloween.xpm");		// S
	load_image(cub, cub->texture[4], "textures/grass.xpm");
	load_image(cub, cub->texture[5], "textures/diamond.xpm");
	load_image(cub, cub->texture[6], "textures/sprite.xpm");
	load_image(cub, cub->texture[7], "textures/wood.xpm");
}