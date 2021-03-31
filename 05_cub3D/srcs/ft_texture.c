# include "cub.h"

double
get_fov_min_dist(t_cub *cub) /* distance to the floor-FOV intersection point */
{
    static double T = -1;
    if( T < 0 ) T = WALL_H / (2.0 * tan(cub->player.fov_v/2.0));
    return T;
}

double
get_luminosity(t_cub *cub, double dist)
{
    static double D = -1;
    if( D < 0 ) D = (cub->map.mx + cub->map.my)/2.0;
    return (dist > D) ? 0 : (1. - dist/D);
}

int
encode_color(int r, int g, int b)
{
	int color;

	color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void
decode_color(int color, int *r, int *g, int *b)
{
	*r = ((color >> 16) & 0xFF);
	*g = ((color >> 8) & 0xFF);
	*b = (color & 0xFF);
}

int
fade_color( int color, double lum )
{
    if( lum < 0 ) lum = 0;
    else if( lum > 1 ) lum = 1;
    int r, g, b;
    decode_color(color, &r, &g, &b);
    return encode_color( (int)(r*lum), (int)(g*lum), (int)(b*lum) );
}

int				get_texture_color(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->tex.texture[cub->ray.wdir][ty * TW + tx];
	return (color);
}

void			wall_render(t_cub *cub, int y0, int y1, int wh)
{
	double		txratio;
	int			color;
	int 		tx;
	int 		ty;

	if (cub->ray.wdir == DIR_W || cub->ray.wdir == DIR_E)
		txratio = cub->ray.wy - floor(cub->ray.wy);
	else
		txratio = cub->ray.wx - floor(cub->ray.wx);
	tx = (int)(txratio * TW);
	double lum = get_luminosity(cub, cub->ray.dist);
	int add = 0;
	if (y0 < 0)
		add = y0 * -1;
	y0 = get_max(0, y0);
	for (int y = y0; y <= y1; y++)
	{
		ty = (int)((y - y0 + add) * TH / wh);
		color = fade_color(get_texture_color(cub, tx, ty), lum);
		draw_pixel(cub, cub->ray.ray_cast, y, color);
	}
}

void			check_path(t_cub *cub, char *path)
{
	int			check_file;

	check_file = open(path, O_RDONLY);
	if (check_file == -1)
	{
		perror("Cub3D Error");
		ft_exit(cub);
	}
}

void			load_image(t_cub *cub, int *texture, char *path)
{
	int			x;
	int			y;

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

void			get_texture(t_cub *cub)
{
	t_img		img;

	load_image(cub, cub->tex.texture[0], cub->map.ea);
	load_image(cub, cub->tex.texture[1], cub->map.no);
	load_image(cub, cub->tex.texture[2], cub->map.we);
	load_image(cub, cub->tex.texture[3], cub->map.so);
	load_image(cub, cub->tex.texture[4], cub->map.s);
}

void			ft_texture(t_cub *cub)
{
	int			i;
	int			j;

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