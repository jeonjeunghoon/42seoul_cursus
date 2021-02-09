#include <mlx.h>
#include <stdlib.h>

#define X_EVENT_KEYPRESS 2
#define KEY_ESC 53

typedef struct s_param
{
	int x;
} t_param;

int press(int keycode, t_param param)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	void *img;
	int width;
	int height;
	t_param param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "HI");
	img = mlx_xpm_file_to_image(mlx, "./textures/wall_s.xpm", &width, &height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_hook(win, X_EVENT_KEYPRESS, 0, &press, &param);
	mlx_loop(mlx);
	return (0);
}