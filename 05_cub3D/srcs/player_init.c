/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:18 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/06 17:38:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			get_player_data(t_cub *cub)
{
	if (cub->map.map[(int)cub->player.y][(int)cub->player.x] == 'E')
		cub->player.th = deg_to_rad(0);
	else if (cub->map.map[(int)cub->player.y][(int)cub->player.x] == 'N')
		cub->player.th = deg_to_rad(90);
	else if (cub->map.map[(int)cub->player.y][(int)cub->player.x] == 'W')
		cub->player.th = deg_to_rad(180);
	else
		cub->player.th = deg_to_rad(270);
	cub->player.fov_h = deg_to_rad(FOV);
	cub->player.fovh_2 = cub->player.fov_h / 2.0;
	cub->player.per_fov_h = cub->player.fov_h / (cub->map.r[0] - 1.0);
	cub->player.fov_v = cub->player.fov_h * cub->map.r[1] / cub->map.r[0];
}

void			player_init(t_cub *cub)
{
	double		temp;

	cub->player.y = 0;
	while (cub->player.y < cub->map.my)
	{
		cub->player.x = 0;
		while (cub->player.x < cub->map.mx)
		{
			if (cub->map.map[(int)cub->player.y][(int)cub->player.x] >= 'A')
			{
				get_player_data(cub);
				cub->player.x += 0.5;
				cub->player.y += 0.5;
				return ;
			}
			cub->player.x++;
		}
		cub->player.y++;
	}
	ft_exit("Cub3D Error: doesn't exist player in map");
}
