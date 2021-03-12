#ifndef CUB_H
# define CUB_H

/* header files */
# include "../opengl/mlx.h"
# include "../libft/libft.h"
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
# define SW 1080
# define SH 680

/* MACRO: Wall size, Map size */
# define MW 24
# define MH 24
# define WALL_H 1.0

/* MACRO: textures */
# define TW 256
# define TH 256

/* MACRO: Player eyes*/
# define FOV_W_DEG 60

/* MACRO: Player movement */
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.03

/* img param */
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
	double		*zbuf;
	int			tex;
	int			x;
	int			y;
	double		dist;
	double		th;
	int			isin;
}				t_sprite;


/* cub param */
typedef	struct	s_cub
{
	// 스크린 변수
	int			sw;
	int			sh;

	// mlx 변수
	void		*mlx;
	void		*win;

	// texture 변수
	int			**texture;
	int			buf[SH][SW];

	// 플레이어 정보 변수
	double		px;
	double		py;
	double		pth;

	// 게임 정보 변수
	int			map[MH][MW];
	int			map_x;
	int			map_y;
	double		fov_w;
	double		half_fov_w;
	double		per_fov_w;
	double		fov_h;

	// DDA 변수
	int			ray_cast;
	double		ray_th;
	double		ray_x;
	double		ray_y;
	double		x_step;
	double		y_step;
	double		x_slope;
	double		y_slope;
	double		nx;
	double		ny;
	double		f;
	double		g;
	int			hit;
	int			hit_side;
	double		dist_x;
	double		dist_y;
	int			cell;
	int			w_dir;
	double		wx;
	double		wy;
	double		dist;

	/* img 변수 */
	t_img		img;

	/* sprite 변수 */
	t_sprite	sprite;
}				t_cub;

enum
{
	HIT_X,
	HIT_Y
};

enum
{
	DIR_E = 0,
	DIR_N,
	DIR_W,
	DIR_S
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
double			get_lower(double x, double y);
double			get_bigger(double x, double y);
int				get_cell(t_cub *cub, int x, int y);
int				ft_sgn(double d);
double			ft_dist(double s_x, double s_y, double e_x, double e_y);
void			ft_swap(t_sprite *sprite, int i, int j);
void			ft_qsort(t_sprite *sprite, int start, int end);

/* player func */
void			get_player_data(t_cub *cub);
void			ft_player(t_cub *cub);

/* render func */
int				get_wall_height(t_cub *cub, double dist);
void			ft_render(t_cub *cub);
int				ft_dda(t_cub *cub, t_sprite *sprite);
int				ft_raycasting(t_cub *cub, t_sprite *sprite);

/* key func */
void			ft_move(int keycode, t_cub *cub, double move_speed, double th);
void			ft_rotate(t_cub *cub, double rotate_speed);
int				ft_key_press(int keycode, t_cub *cub);
int				ft_key_release(int keycode, t_cub *cub);

/* texture func */
void			load_image(t_cub *cub, int *texture, char *path, t_img *img);
void			load_texture(t_cub *cub);
int				get_texture_color(t_cub *cub, int tx, int ty);
void			wall_render(t_cub *cub, int wall_start, int wall_end, int wall_h);

/* sprite func */
static int		cmp_sprites( const void* a, const void* b );
t_sprite		*ft_realloc(t_sprite *sp, int size);
t_sprite		*get_visible_sprites(t_cub *cub, t_sprite *sprite, int *pcnt);
void			ft_sprite(t_cub *cub, t_sprite *sprite);

/* window management */
int				ft_exit(t_cub *cub);
void			ft_screen(t_cub *cub);

#endif