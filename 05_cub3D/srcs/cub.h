#ifndef CUB_H
# define CUB_H

/* header files */
# include "../opengl/mlx.h"
# include "../libft/libft.h"
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

/* MACRO: Window Screen size */
# define SX 1080
# define SY 680

/* MACRO: Wall size, Map size */
# define MX 24
# define MY 24
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

typedef	struct	s_ray
{
	int			ray_cast;
	double		ray;
	double		ray_x;
	double		ray_y;
	double		xstep;
	double		ystep;
	double		xslope;
	double		yslope;
	double		nx;
	double		ny;
	double		f;
	double		g;
	int			hit;
	int			hit_side;
	double		dist_v;
	double		dist_h;
	int			cell;
	int			wdir;
	double		wx;
	double		wy;
	double		dist;
}				t_ray;


typedef	struct	s_player
{
	double		x;
	double		y;
	double		th;
	double		fov_h;
	double		fovh_2;
	double		per_fov_h;
	double		fov_v;
}				t_player;

typedef	struct	s_img
{
	void		*img;
	int			width;
	int			height;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

/* sprite param */
typedef	struct	s_sprite
{
	int			vis[MX][MY];
	double		*zbuf;
	int			tex;
	int			x;
	int			y;
	double		dist;
	double		th;
}				t_sprite;


/* cub param */
typedef	struct	s_cub
{
	// 스크린 변수
	int			sx;
	int			sy;

	// mlx 변수
	void		*mlx;
	void		*win;

	// texture 변수
	int			**texture;
	int			buf[TH][TW];

	// 플레이어 정보 변수
	t_player	player;

	// 게임 정보 변수
	int			map[MX][MY];
	int			map_x;
	int			map_y;

	// DDA 변수
	t_ray		ray;

	/* img 변수 */
	t_img		img;

	/* sprite 변수 */
	t_sprite	sprite;
}				t_cub;

enum
{
	VERT,
	HORIZ
};

enum
{
	DIR_E = 0,
	DIR_N,
	DIR_W,
	DIR_S,
	DIR_F,
	DIR_C,
	DIR_SP
};

enum
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

/* utility func */
double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
double			get_min(double x, double y);
double			get_max(double x, double y);
int				get_cell(t_cub *cub, int x, int y);
int				ft_sgn(double d);
double			ft_dist(double s_x, double s_y, double e_x, double e_y);
// void			ft_swap(t_sprite *sprite, int i, int j);
// void			ft_qsort(t_sprite *sprite, int start, int end);
void			draw_pixel(t_cub *cub, int x, int y, int color);

/* player func */
void			get_player_data(t_cub *cub);
void			ft_player(t_cub *cub);

/* render func */
int				get_wall_height(t_cub *cub, double dist);
void			ft_render(t_cub *cub);
int				ft_dda(t_cub *cub);
int				ft_raycasting(t_cub *cub);

/* key func */
void			ft_move(int keycode, t_cub *cub, double move_speed, double th);
void			ft_rotate(t_cub *cub, double rotate_speed);
int				ft_key_press(int keycode, t_cub *cub);
int				ft_key_release(int keycode, t_cub *cub);

/* texture func */
double			get_fov_min_dist(t_cub *cub);
double			get_luminosity(double dist);
int				encode_color(int r, int g, int b);
void			decode_color(int color, int *r, int *g, int *b);
int				fade_color(int color, double lum);
void			check_path(t_cub *cub, char *path);
void			load_image(t_cub *cub, int *texture, char *path);
void			load_texture(t_cub *cub);
int				get_texture_color(t_cub *cub, int tx, int ty);
void			wall_render(t_cub *cub, int y0, int y1, int wh);

/* sprite func */
static int		cmp_sprites( const void* a, const void* b );
t_sprite		*ft_realloc(t_sprite *sp, int size);
t_sprite		*get_visible_sprites(t_cub *cub, int *pcnt);
void			ft_sprite(t_cub *cub);

// maps
void			draw_ray(t_cub *cub, int hit_side, double f, double g);
void			draw_tile(t_cub *cub, double x, double y, int color);
void			ft_minimap(t_cub *cub);

/* window management */
int				ft_exit(t_cub *cub);
void			ft_screen(t_cub *cub);

#endif