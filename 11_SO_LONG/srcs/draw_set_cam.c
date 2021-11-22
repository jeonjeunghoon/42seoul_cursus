/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:13:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:23:21 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_camera_var(t_game *game)
{
	if (game->player->x < 15)
		game->draw->camera_pivot_x = 0;
	else if (game->player->x > game->map->x - 15)
		game->draw->camera_pivot_x = game->map->x - 30;
	else
		game->draw->camera_pivot_x = game->player->x - 15;
	if (game->player->y < 10)
		game->draw->camera_pivot_y = 0;
	else if (game->player->y > game->map->y - 10)
		game->draw->camera_pivot_y = game->map->y - 20;
	else
		game->draw->camera_pivot_y = game->player->y - 10;
	if (game->map->x < 30)
		game->draw->camera_pivot_x = 0;
	if (game->map->y < 20)
		game->draw->camera_pivot_y = 0;
}

void	set_max_screen_var(t_game *game)
{
	if (game->map->x <= 30)
		game->draw->max_screen_x = game->map->x;
	else
		game->draw->max_screen_x = 30;
	if (game->map->y <= 20)
		game->draw->max_screen_y = game->map->y;
	else
		game->draw->max_screen_y = 20;
}

void	set_draw_var(t_game *game)
{
	game->draw->t_w = 40;
	game->draw->t_h = 40;
	set_max_screen_var(game);
	set_camera_var(game);
}
