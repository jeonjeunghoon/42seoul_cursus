# include "cub.h"

void			ft_move(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
	{
		cub->p_x += MOVE_SPEED * (cos(cub->p_th));
		cub->p_y += MOVE_SPEED * (sin(cub->p_th));
	}
	else if (keycode == KEY_S)
	{
		cub->p_x -= MOVE_SPEED * (cos(cub->p_th));
		cub->p_y -= MOVE_SPEED * (sin(cub->p_th));
	}
	else if (keycode == KEY_A)
	{
		cub->p_x += MOVE_SPEED * (cos(cub->p_th - deg_to_rad(90)));
		cub->p_y += MOVE_SPEED * (sin(cub->p_th - deg_to_rad(90)));
	}
	else if (keycode == KEY_D)
	{
		cub->p_x += MOVE_SPEED * (cos(cub->p_th + deg_to_rad(90)));
		cub->p_y += MOVE_SPEED * (sin(cub->p_th + deg_to_rad(90)));
	}
}

void			ft_rotate(t_cub *cub, double th)
{
	cub->p_th += deg_to_rad(th);
	if (cub->p_th < 0)
		cub->p_th += deg_to_rad(360);
	else if (cub->p_th > deg_to_rad(360))
		cub->p_th -= deg_to_rad(360);
}

int				ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D)
		ft_move(keycode, cub);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			ft_rotate(cub, ROTATE_SPEED * -1);
		else
			ft_rotate(cub, ROTATE_SPEED);
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		ft_exit();
	}
	return (0);
}