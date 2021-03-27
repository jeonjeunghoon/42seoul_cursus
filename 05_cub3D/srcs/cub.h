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
# define SY 640

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

/* MACRO: Bitmap */
# define PIXEL_SIZE   3    // 픽셀 한 개의 크기 3바이트(24비트)
# define PIXEL_ALIGN  4    // 픽셀 데이터 가로 한 줄은 4의 배수 크기로 저장됨

typedef	struct	s_sprite
{
	int			isin;
	int			vis[MX][MY];
	double		*zbuf;
	int			tex;
	double		x;
	double		y;
	int			nsp;
	double		dist;
	double		th;
}				t_sprite;

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

typedef	struct	s_map
{
	int			map[MX][MY];
	int			mapx;
	int			mapy;
}				t_map;


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

typedef	struct	s_screen
{
	int			sx;
	int			sy;	
}				t_screen;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef	struct	s_texture
{
	int			**texture;
	int			buf[TH][TW];
}				t_texture;

#pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬
typedef	struct		s_bmp
{
	int				save;
	unsigned short	id1;
	unsigned short	id2;           // BMP 파일 매직 넘버
    unsigned int	bmp_file_size;           // 파일 크기
    unsigned short	reserved1;      // 예약
    unsigned short	reserved2;      // 예약
    unsigned int	offset;
	unsigned int	dib_size;           // 현재 구조체의 크기
    int				width;          // 비트맵 이미지의 가로 크기
    int				height;         // 비트맵 이미지의 세로 크기
    unsigned short	plane;         // 사용하는 색상판의 수
    unsigned short	bpp;       // 픽셀 하나를 표현하는 비트 수
    unsigned int	compression;    // 압축 방식
    unsigned int	raw_bitmap_size;      // 비트맵 이미지의 픽셀 데이터 크기
    int				resx;  // 그림의 가로 해상도(미터당 픽셀)
    int				resy;  // 그림의 세로 해상도(미터당 픽셀)
    unsigned int	number_of_colors;        // 색상 테이블에서 실제 사용되는 색상 수
    unsigned int	important_colors;
}					t_bmp;
#pragma pack(pop)

/* cub param */
typedef	struct	s_cub
{
	t_mlx		mlx;
	t_screen	scr;
	t_texture	tex;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_img		img;
	t_sprite	sp;
	t_bmp		bmp;
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
int				get_sprite_color(t_cub *cub, int tx, int ty);
t_sprite		*get_visible_sprites(t_cub *cub);
void			ft_sprite(t_cub *cub);

// maps
void			draw_ray(t_cub *cub, int hit_side, double slope);
void			draw_tile(t_cub *cub, double x, double y, int color);
void			ft_minimap(t_cub *cub);

/* window management */
int				ft_exit(t_cub *cub);
void			ft_screen(t_cub *cub);

/* bmp */
t_bmp			get_header(t_cub *cub);
void			ft_save(t_cub *cub);

#endif