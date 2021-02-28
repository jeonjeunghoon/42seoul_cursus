# include "cub.h"

void			ft_move(int keycode, t_cub *cub, double move_speed, double th)
{
	double		dx;
	double		dy;

	if (keycode == KEY_W || keycode == KEY_S)
	{
		dx = cub->px + move_speed * (cos(cub->pth));
		dy = cub->py + move_speed * (sin(cub->pth));
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		dx = cub->px + move_speed * (cos(cub->pth + deg_to_rad(th)));
		dy = cub->py + move_speed * (sin(cub->pth + deg_to_rad(th)));
	}
	if (get_cell(cub, dx, dy) == 1)
	{
		printf("bump!\n");
		return ;
	}
	cub->px = dx;
	cub->py = dy;
}

void			ft_rotate(t_cub *cub, double rotate_speed)
{
	cub->pth += rotate_speed;
	if (cub->pth < 0)
		cub->pth += deg_to_rad(360);
	else if (cub->pth > deg_to_rad(360))
		cub->pth -= deg_to_rad(360);
}

int				ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_S)
			ft_move(keycode, cub, MOVE_SPEED * -1, 90);
		else if (keycode == KEY_A || keycode == KEY_W)
			ft_move(keycode, cub, MOVE_SPEED, 90);
		else if (keycode == KEY_D)
			ft_move(keycode, cub, MOVE_SPEED, -90);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			ft_rotate(cub, ROTATE_SPEED);
		else
			ft_rotate(cub, ROTATE_SPEED * -1);
	}
	if (keycode == KEY_ESC)
		ft_exit(cub);
	return (0);
}