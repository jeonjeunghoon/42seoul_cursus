#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEYPRESS 2

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_game
{
	void *mlx;
	void *win;
} t_game;

typedef struct s_param
{
	int x;
} t_param;

void param_init(t_param *param)
{
	param->x = 0;
}

int press_key(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("##  x: %d\n", param->x);
	return (0);
}

int main(void)
{
	t_game game;
	t_param param;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 800, 600, "press key");
	param_init(&param);
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &press_key, &param);
	mlx_loop(game.mlx);
	return (0);
}