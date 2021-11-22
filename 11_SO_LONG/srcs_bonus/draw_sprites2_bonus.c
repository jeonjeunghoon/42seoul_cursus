/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:14:49 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:22:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	make_animation(t_game *game)
{
	if (game->draw->ani_flag == 0)
		game->draw->ani_time++;
	else if (game->draw->ani_flag == 1)
		game->draw->ani_time--;
	if (game->draw->ani_time > 9)
		game->draw->ani_flag = 1;
	else if (game->draw->ani_time < 1)
		game->draw->ani_flag = 0;
}

void	draw_collect(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	make_animation(game);
	w = game->imgs->collect_img.width;
	h = game->imgs->collect_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->collect_img.data[\
			j * h / game->draw->t_h * w + i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j - \
				game->draw->ani_time)] \
				= game->imgs->collect_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}
