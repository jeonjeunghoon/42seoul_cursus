/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/14 11:36:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../opengl/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
# define WALL_H 1.0
# define TW 256
# define TH 256
# define FOV 60
# define MOVE_SPEED 0.2
# define ROTATE_SPEED 0.1

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
	int				sph;
	double			angle;
	double			pixel_per_angle;
	int				cx;
	int				xmin;
	int				xmax;
	double			txratio;
	int				tx;
	int				ty;
	int				color;
}					t_sprite;

typedef	struct		s_texture
{
	double			txratio;
	int				tx;
	int				ty;
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
	int				fd;
	int				is_read;
	char			**buf;
	int				*r;
	char			*ea;
	char			*no;
	char			*we;
	char			*so;
	char			*s;
	int				*c;
	int				*f;
	int				mx;
	int				my;
	char			*parsed_map;
	int				**map;
	int				mapx;
	int				mapy;
	int				idx;
	int				jdx;
	int				kdx;
	int				is_overlap;
	char			*ptr;
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

void				check_mapdata(t_cub *cub);
void				check_num(t_cub *cub);
void				check_numdata(t_cub *cub, int idx, int jdx, int check);
int					get_tile_size(t_cub *cub);
void				ft_exception(int argc, char **argv, t_cub *cub);
void				load_data(t_cub *cub);
void				load_texture(t_cub *cub);
void				parsing_init(t_cub *cub);
void				texture_init(t_cub *cub);
void				screen_init(t_cub *cub);
void				player_init(t_cub *cub);
void				get_player_data(t_cub *cub);
void				ray_init(t_cub *cub);
void				hitting(t_cub *cub);
int					is_hit(t_cub *cub);
int					ft_dda(t_cub *cub);
int					ft_raycasting(t_cub *cub);
void				ft_move(int keycode, t_cub *cub, double move_speed, \
					double th);
void				ft_rotate(t_cub *cub, double rotate_speed);
int					ft_key(int keycode, t_cub *cub);
void				wall_render(t_cub *cub, int y0, int y1, int wh);
void				check_path(char *path);
void				load_image(t_cub *cub, int *texture, char *path);
void				get_texture(t_cub *cub);
void				ft_render(t_cub *cub);
void				draw_tile(t_cub *cub, double x, double y, int color);
void				ft_minimap(t_cub *cub);
int					ft_exit(char *s);
void				get_sprite(t_cub *cub, int x, int y, t_sprite *sp);
t_sprite			*get_visible_sprites(t_cub *cub);
void				draw_col(t_cub *cub, int x, int y);
void				draw_sprite(t_cub *cub, t_sprite *sp, int i);
void				ft_sprite(t_cub *cub);
void				write_bmp_header(t_cub *cub, int fd);
void				ft_save(t_cub *cub);
void				is_valid(t_cub *cub, int idx, int jdx);
void				check_vertex(t_cub *cub, int idx, int jdx);
void				check_row(t_cub *cub, int idx, int jdx);
void				check_col(t_cub *cub, int idx, int jdx);
void				check_etc(t_cub *cub, int idx, int jdx);
void				check_map(t_cub *cub);
void				fill_space(t_cub *cub, int idx, int jdx);
void				fill_map(t_cub *cub);
void				map_init(t_cub *cub);
void				get_map(t_cub *cub, int idx);
void				get_route(t_cub *cub, int idx, int jdx);
void				get_numdata(t_cub *cub, int idx, int jdx, int loop);
void				get_data(t_cub *cub, int idx, int jdx);
void				read_map(t_cub *cub, int idx, int jdx);
double				deg_to_rad(double deg);
double				rad_to_deg(double rad);
double				get_min(double x, double y);
double				get_max(double x, double y);
int					get_cell(t_cub *cub, int x, int y);
void				draw_pixel(t_cub *cub, int x, int y, int color);
int					ft_sgn(double d);
double				ft_dist(double s_x, double s_y, double e_x, double e_y);
void				ft_swap(t_sprite *sprite, int i, int j);
void				ft_qsort(t_sprite *sprite, int start, int end);
int					is_space(char c);
int					except_space(t_cub *cub, int idx);
t_sprite			*sprite_realloc(t_sprite *ptr, int n);
int					is_player(char player);
int					get_sprite_color(t_cub *cub, int tx, int ty);
int					get_wall_height(t_cub *cub, double dist);
int					encode_color(int r, int g, int b);
void				decode_color(int color, int *r, int *g, int *b);
int					get_texture_color(t_cub *cub, int tx, int ty);
void				map_error(void);

#endif
