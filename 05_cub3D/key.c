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

void			ft_rotate(int keycode, t_cub *cub)
{
	if (keycode == KEY_RIGHT)
	{
		if (cub->p_th < deg_to_rad(360))
		{
			cub->p_th += deg_to_rad(ROTATE_SPEED);
		}
		else
		{
			cub->p_th = 0;
			cub->p_th += deg_to_rad(ROTATE_SPEED);
		}
	}
	else if (keycode == KEY_LEFT)
	{
		if (cub->p_th > deg_to_rad(0))
		{
			cub->p_th -= deg_to_rad(ROTATE_SPEED);
		}
		else
		{
			cub->p_th = deg_to_rad(360);
			cub->p_th -= deg_to_rad(ROTATE_SPEED);
		}
	}
}

int				ft_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D)
		ft_move(keycode, cub);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		ft_rotate(keycode, cub);
	if (keycode == KEY_ESC)
		exit(0);
	printf("p_x: %f p_y: %f p_th: %f\n", cub->p_x, cub->p_y, cub->p_th);
	return (0);
}

int				ft_release(int keycode, t_cub *cub)
{
	return (0);
}

int				ft_exit(int keycode, t_cub *cub)
{
	return (0);
}