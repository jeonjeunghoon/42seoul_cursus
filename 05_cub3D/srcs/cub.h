#ifndef CUB_H
# define CUB_H

/* header files */
# include "../opengl/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

/* MACRO: Key */
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

/* MACRO: Wall size, Map size */
# define WALL_H 1.0

/* minimap tile */
# define TILE 10

/* MACRO: textures */
# define TW 256
# define TH 256

/* MACRO: Player eyes*/
# define FOV 60

/* MACRO: Player movement */
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.03

enum	e_hitside
{
	VERT,
	HORIZ
};

enum	e_dir
{
	DIR_E = 0,
	DIR_N,
	DIR_W,
	DIR_S,
	DIR_SP
};

enum	e_key
{
	E_KEY_OTHER,
	E_KEY_W,
	E_KEY_A,
	E_KEY_S,
	E_KEY_D,
	E_KEY_LEFT,
	E_KEY_RIGHT,
	E_KEY_ESC
};

typedef	struct		s_sprite
{
	int				isin;
	int				**vis;
	double			*zbuf;
	int				tex;
	double			x;
	double			y;
	int				nsp;
	double			dist;
	double			th;
}					t_sprite;

typedef	struct		s_texture
{
	int				**texture;
	int				buf[TH][TW];
}					t_texture;

typedef	struct		s_ray
{
	int				ray_cast;
	double			ray;
	double			ray_x;
	double			ray_y;
	double			xstep;
	double			ystep;
	double			xslope;
	double			yslope;
	double			nx;
	double			ny;
	double			f;
	double			g;
	int				hit;
	int				hit_side;
	double			dist_v;
	double			dist_h;
	int				cell;
	int				wdir;
	double			wx;
	double			wy;
	double			dist;
}					t_ray;

typedef	struct		s_player
{
	double			x;
	double			y;
	double			th;
	double			fov_h;
	double			fovh_2;
	double			per_fov_h;
	double			fov_v;
}					t_player;

typedef	struct		s_map
{
	char			**buf;
	int				r[2];
	char			*ea;
	char			*no;
	char			*we;
	char			*so;
	char			*s;
	int				c[3];
	int				f[3];
	int				mx;
	int				my;
	char			*parsed_map;
	int				**map;
	int				mapx;
	int				mapy;
}					t_map;

typedef	struct		s_img
{
	void			*img;
	int				width;
	int				height;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

/* cub param */
typedef	struct		s_cub
{
	t_mlx			mlx;
	t_img			img;
	t_player		player;
	t_map			map;
	t_ray			ray;
	t_texture		tex;
	t_sprite		sp;
	int				save;
}					t_cub;

/* player func */
void				get_player_data(t_cub *cub);
void				ft_player(t_cub *cub);

/* render func */
int					get_wall_height(t_cub *cub, double dist);
void				ft_render(t_cub *cub);
int					ft_dda(t_cub *cub);
int					ft_raycasting(t_cub *cub);

/* key func */
void				ft_move(int keycode, t_cub *cub, double move_speed, double th);
void				ft_rotate(t_cub *cub, double rotate_speed);
int					ft_key(int keycode, t_cub *cub);

/* texture func */
double				get_fov_min_dist(t_cub *cub);
double				get_luminosity(t_cub *cub, double dist);
int					encode_color(int r, int g, int b);
void				decode_color(int color, int *r, int *g, int *b);
int					fade_color(int color, double lum);
void				check_path(t_cub *cub, char *path);
void				load_image(t_cub *cub, int *texture, char *path);
void				load_texture(t_cub *cub);
void				ft_texture(t_cub *cub);
int					get_texture_color(t_cub *cub, int tx, int ty);
void				wall_render(t_cub *cub, int y0, int y1, int wh);

// maps
void				draw_tile(t_cub *cub, double x, double y, int color);
void				ft_minimap(t_cub *cub);

/* window management */
int					ft_exit(t_cub *cub);
void				ft_screen(t_cub *cub);

/* sprite func */
static int			cmp_sprites( const void* a, const void* b );
int					get_sprite_color(t_cub *cub, int tx, int ty);
t_sprite			*get_visible_sprites(t_cub *cub);
void				ft_sprite(t_cub *cub);

/* bmp */
void				write_bmp_header(t_cub *cub, int fd);
void				ft_save(t_cub *cub);

/* parsing */
void				map_init(t_cub *cub);
void				get_map(t_cub *cub, int idx);
void				get_route(t_cub *cub, int idx, int jdx);
void				get_numdata(t_cub *cub, int idx, int jdx, int loop);
void				get_data(t_cub *cub, int idx, int jdx);
void				ft_parsing(t_cub *cub);

/* utility func */
double				deg_to_rad(double deg);
double				rad_to_deg(double rad);
double				get_min(double x, double y);
double				get_max(double x, double y);
int					get_cell(t_cub *cub, int x, int y);
int					ft_sgn(double d);
double				ft_dist(double s_x, double s_y, double e_x, double e_y);
// void				ft_swap(t_sprite *sprite, int i, int j);
// void				ft_qsort(t_sprite *sprite, int start, int end);
void				draw_pixel(t_cub *cub, int x, int y, int color);
int					is_space(char c);
int					except_space(t_cub *cub, int idx);
void				*ft_realloc(void *ptr, int type, int size);
int					is_player(t_cub *cub, char player);

#endif