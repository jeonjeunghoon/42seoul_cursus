#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 해상도 매크로
# define SW 720
# define SH 480

// 수학 관련 매크로
# define deg_to_rad(d) (d*(M_PI/180))
# define rad_to_deg(d) (d*(180/M_PI))

// Filed Of View 매크로
# define FOV_DH 90
# define FOV_H deg_to_rad(FOV_DH)
# define PER_FOV_H (FOV_H/(SW-1))

// 맵 타일 크기와 맵 크기 매크로
# define TILES 30
# define MW 10
# define MH 6

typedef struct	s_game
{
	int			px;
	int			py;
	double		pth;
	int			map[MH][MW];
}				t_game;

void map_init(t_game *game)
{
	int			src[MH][MW] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 'S', 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src, sizeof(int) * MH * MW);
	game->pth = -1;
	game->py = 0;
	while (game->py < MH)
	{
		game->px = 0;
		while (game->px < MW)
		{
			if (src[game->py][game->px] == 'E')
				game->pth = deg_to_rad(0);
			if (src[game->py][game->px] == 'W')
				game->pth = deg_to_rad(180);
			else if (src[game->py][game->px] == 'S')
				game->pth = deg_to_rad(270);
			else if (src[game->py][game->px] == 'N')
				game->pth = deg_to_rad(90);
			if (game->pth >= 0)
				return ;
			game->px++;
		}
		game->py++;
	}
}

void draw_pixel(t_game *game, double dist)
{
	
}

void ft_raycasting(t_game *game)
{
	double	delta_x;
	double	delta_y;
	double	sight_x;
	double	sight_y;
	double	th;
	int		ray;
	double	step;
	double	dist;

	ray = 0;
	th = game->pth - (FOV_H/2);
	while (ray < SW)
	{
		sight_x = game->px * TILES;
		sight_y = game->py * TILES;
		delta_x = cos(th + (PER_FOV_H * ray));
		delta_y = sin(th + (PER_FOV_H * ray));
		step = fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y);
		delta_x /= step;
		delta_y /= step;
		while (game->map[(int)floor(sight_y / TILES)][(int)floor(sight_x / TILES)] != 1)
		{
			sight_x += delta_x;
			sight_y += delta_y;
		}
		dist = sqrt(pow(sight_x - game->px * TILES, 2) + pow(sight_y - game->py * TILES, 2));
		draw_pixel(game, dist);
		ray++;
	}
}

int main(void)
{
	t_game		game;

	map_init(&game);
	ft_raycasting(&game);
	return (0);
}
