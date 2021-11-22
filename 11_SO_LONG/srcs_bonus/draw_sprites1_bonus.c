/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:12:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:22:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	draw_road(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = game->imgs->road_img.width;
	h = game->imgs->road_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->road_img.data[\
			j * h / game->draw->t_h * w + \
			i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j)] \
				= game->imgs->road_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}

void	draw_wall(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = game->imgs->wall_img.width;
	h = game->imgs->wall_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->wall_img.data[\
			j * h / game->draw->t_h * w + \
			i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j)] \
				= game->imgs->wall_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}

void	draw_enemy(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = game->imgs->enemy_img.width;
	h = game->imgs->enemy_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->enemy_img.data[\
			j * h / game->draw->t_h * w + \
			i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j)] \
				= game->imgs->enemy_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}

void	draw_player(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = game->imgs->player_img.width;
	h = game->imgs->player_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->player_img.data[\
			j * h / game->draw->t_h * w + \
			i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j)] \
				= game->imgs->player_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}

void	draw_exit(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = game->imgs->exit_img.width;
	h = game->imgs->exit_img.height;
	i = -1;
	while (++i < game->draw->t_w)
	{
		j = -1;
		while (++j < game->draw->t_h)
		{
			if (game->imgs->exit_img.data[\
			j * h / game->draw->t_h * w + \
			i * w / game->draw->t_w] > -1)
				game->img.data[to_coord(game, \
				game->draw->t_w * (x - game->draw->camera_pivot_x) + i, \
				game->draw->t_h * (y - game->draw->camera_pivot_y) + j)] \
				= game->imgs->exit_img.data[\
				j * h / game->draw->t_h * w + \
				i * w / game->draw->t_w];
		}
	}
}
