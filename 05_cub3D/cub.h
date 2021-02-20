#ifndef CUB_H
# define CUB_H

/* header files */
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"

#include <stdio.h>

/* MACRO: Key */
# define EVENT_EXIT 0
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

/* MACRO: Screen size */
# define SW 1080
# define SH 600

/* MACRO: Wall size, Map size */
# define TILE 30
# define MW 10
# define MH 10

/* MACRO: Player eyes*/
# define FOV_W_DEG 90

/* MACRO: Player movement */
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 2

/* cub param */
typedef	struct	s_cub
{
	void		*img;
	int			width;
	int			height;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;

	void		*mlx;
	void		*win;

	double		p_x;
	double		p_y;
	double		p_th;

	int			map[MH][MW];
	int			map_x;
	int			map_y;
	double		fov_w;
	double		half_fov_w;
	double		per_fov_w;
	double		fov_h;

	int			ray_cast;
	double		ray_th;
	double		ray_x;
	double		ray_y;

	double		delta_x;
	double		delta_y;
	double		w_dir;
	double		dist;
	int			object;
}				t_cub;

enum
{
	DIR_E = 0,
	DIR_N,
	DIR_W,
	DIR_S
};

/* utility func */
double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
double			get_lower(double x, double y);
double			get_bigger(double x, double y);

/* player func */
void			get_player_data(t_cub *cub);
void			ft_player(t_cub *cub);

/* render func */
void			ft_render(t_cub *cub);
void			ft_dda(t_cub *cub);
int				ft_raycasting(t_cub *cub);

/* key func */
void			ft_move(int keycode, t_cub *cub);
void			ft_rotate(t_cub *cub, double th);
int				ft_press(int keycode, t_cub *cub);
int				ft_release(int keycode, t_cub *cub);
int				ft_exit(int keycode, t_cub *cub);

#endif