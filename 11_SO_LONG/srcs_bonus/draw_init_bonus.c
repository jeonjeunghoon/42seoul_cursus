/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:45:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:22:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	sprite_init2(t_game *game)
{
	game->imgs->collect_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/collect.xpm", &game->imgs->collect_img.width, \
	&game->imgs->collect_img.height);
	game->imgs->collect_img.data = (int *)mlx_get_data_addr(\
	game->imgs->collect_img.img, &game->imgs->collect_img.bpp, \
	&game->imgs->collect_img.size_line, &game->imgs->collect_img.endian);
	game->imgs->enemy_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/enemy.xpm", &game->imgs->enemy_img.width, \
	&game->imgs->enemy_img.height);
	game->imgs->enemy_img.data = (int *)mlx_get_data_addr(\
	game->imgs->enemy_img.img, &game->imgs->enemy_img.bpp, \
	&game->imgs->enemy_img.size_line, &game->imgs->enemy_img.endian);
	game->imgs->exit_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/exit.xpm", &game->imgs->exit_img.width, \
	&game->imgs->exit_img.height);
	game->imgs->exit_img.data = (int *)mlx_get_data_addr(\
	game->imgs->exit_img.img, &game->imgs->exit_img.bpp, \
	&game->imgs->exit_img.size_line, &game->imgs->exit_img.endian);
}

void	sprite_init1(t_game *game)
{
	game->imgs->road_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/road.xpm", &game->imgs->road_img.width, \
	&game->imgs->road_img.height);
	game->imgs->road_img.data = (int *)mlx_get_data_addr(\
	game->imgs->road_img.img, &game->imgs->road_img.bpp, \
	&game->imgs->road_img.size_line, &game->imgs->road_img.endian);
	game->imgs->wall_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/wall.xpm", &game->imgs->wall_img.width, \
	&game->imgs->wall_img.height);
	game->imgs->wall_img.data = (int *)mlx_get_data_addr(\
	game->imgs->wall_img.img, &game->imgs->wall_img.bpp, \
	&game->imgs->wall_img.size_line, &game->imgs->wall_img.endian);
	game->imgs->player_img.img = mlx_xpm_file_to_image(game->mlx, \
	"textures/player.xpm", &game->imgs->player_img.width, \
	&game->imgs->player_img.height);
	game->imgs->player_img.data = (int *)mlx_get_data_addr(\
	game->imgs->player_img.img, &game->imgs->player_img.bpp, \
	&game->imgs->player_img.size_line, &game->imgs->player_img.endian);
}
