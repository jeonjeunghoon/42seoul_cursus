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
# define FOV_RH deg_to_rad(90)
# define PER_FOV_RH FOV_RH/(SW-1)

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
	{1, 0, 'N', 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	game->py = 0;
	while (game->py < MH)
	{
		game->px = 0;
		while (game->px < MW)
		{
			if (src[game->py][game->px] == 'E')
				game->pth = 0;
			if (src[game->py][game->px] == 'W')
				game->pth = 180;
			else if (src[game->py][game->px] == 'S')
				game->pth = 90;
			else if (src[game->py][game->px] == 'N')
				game->pth = 270;
			game->px++;
		}
		game->py++;
	} 
}

void ft_raycasting(t_game *game)
{
	int x;
	int y;
	int ray;
	double slope;

	ray = 0;
	while (ray < SX)
	{
		x = 0;
		y = 0;
		slope = tan(game->pth + (FOV_RH/2 - (ray * PER_FOV_RH));
		while (x >= 0 && y >= 0)
		{
			y = slope(x - 
		}
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
