# include "cub.h"

double
get_fov_min_dist(t_cub *cub) /* distance to the floor-FOV intersection point */
{
    static double T = -1;
    if( T < 0 ) T = WALL_H / (2.0 * tan(cub->player.fov_v/2.0));
    return T;
}

double
get_luminosity( double dist )
{
    static double D = -1;
    if( D < 0 ) D = (MX + MY)/2.0;
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

	color = cub->texture[cub->ray.wdir][ty * TW + tx];
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
	double lum = get_luminosity(cub->ray.dist);
	int add = 0;
	if (y0 < 0)
		add = y0 * -1;
	y0 = get_max(0, y0);
	for (int y = y0; y <= y1; y++)
	{
		if (y < TILE * MY && cub->ray.ray_cast < TILE * MX)
			continue ;
		ty = (int)((y - y0 + add) * TH / wh);
		color = fade_color(get_texture_color(cub, tx, ty), lum);
		draw_pixel(cub, cub->ray.ray_cast, y, color);
	}

	// floor, ceil
	if ( y1 < SY-1 ) {
        double EC = get_fov_min_dist(cub);

        for( int y=y1+1; y<SY; y++ ) {
            double h = (double)(SY-1-y)/SY;
            double D = EC / (1. - 2*h);
            double lum_f = get_luminosity(D);

            double d_ratio = D / cub->ray.dist;
        	double fx = cub->player.x + (cub->ray.wx - cub->player.x) * d_ratio; /* floor coord. */
        	double fy = cub->player.y + (cub->ray.wy - cub->player.y) * d_ratio;

        	/* floor */
        	int tx = (int)((fx-floor(fx)) * TW); /* texture col # */
        	int ty = (int)((fy-floor(fy)) * TH); /* texture row # */
			cub->ray.wdir = DIR_F;
			color = fade_color(get_texture_color(cub, tx, ty), lum_f);
			draw_pixel(cub, cub->ray.ray_cast, y, color);

        	/* ceiling */
			if (cub->sy - 1 - y < TILE * MY && cub->ray.ray_cast < TILE * MX)
				continue ;
        	tx = (int)((fx-floor(fx)) * TW); /* texture col # */
        	ty = (int)((fy-floor(fy)) * TH); /* texture row # */
			cub->ray.wdir = DIR_C;
			color = fade_color(get_texture_color(cub, tx, ty), lum_f);
			draw_pixel(cub, cub->ray.ray_cast, cub->sy - 1 - y, color);
		}
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

	load_image(cub, cub->texture[0], "textures/creeper.xpm");		// E
	load_image(cub, cub->texture[1], "textures/yellowmonster.xpm");	// N
	load_image(cub, cub->texture[2], "textures/zombie.xpm");		// W
	load_image(cub, cub->texture[3], "textures/halloween.xpm");		// S
	load_image(cub, cub->texture[4], "textures/fire.xpm");			// F
	load_image(cub, cub->texture[5], "textures/dirt.xpm");			// C
	load_image(cub, cub->texture[6], "textures/sprite.xpm");
	load_image(cub, cub->texture[7], "textures/diamond.xpm");
}
