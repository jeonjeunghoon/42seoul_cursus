/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:05 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/09 01:38:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			ft_move(int keycode, t_cub *cub, double move_speed, double th)
{
	double		dx;
	double		dy;

	dx = 0.0;
	dy = 0.0;
	if (keycode == KEY_W || keycode == KEY_S)
	{
		dx = cub->player.x + move_speed * (cos(cub->player.th));
		dy = cub->player.y + move_speed * (sin(cub->player.th));
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		dx = cub->player.x + move_speed * \
			(cos(cub->player.th + deg_to_rad(th)));
		dy = cub->player.y + move_speed * \
			(sin(cub->player.th + deg_to_rad(th)));
	}
	if (get_cell(cub, dx, dy) == 1)
		return ;
	cub->player.x = dx;
	cub->player.y = dy;
}

void			ft_rotate(t_cub *cub, double rotate_speed)
{
	cub->player.th += rotate_speed;
	if (cub->player.th < 0)
		cub->player.th += deg_to_rad(360);
	else if (cub->player.th > deg_to_rad(360))
		cub->player.th -= deg_to_rad(360);
}

int				ft_key(int keycode, t_cub *cub)
{
	double		move_speed;

	move_speed = MOVE_SPEED;
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_S)
			ft_move(keycode, cub, move_speed * -1, 90);
		else if (keycode == KEY_A || keycode == KEY_W)
			ft_move(keycode, cub, move_speed, 90);
		else if (keycode == KEY_D)
			ft_move(keycode, cub, move_speed, -90);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			ft_rotate(cub, ROTATE_SPEED);
		else
			ft_rotate(cub, ROTATE_SPEED * -1);
	}
	if (keycode == KEY_ESC)
		ft_exit("Exit Cub3D");
	return (0);
}
