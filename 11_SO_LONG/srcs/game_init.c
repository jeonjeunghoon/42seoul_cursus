/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:49:24 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:46:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_init(t_map *map)
{
	map->front = (t_node *)malloc(sizeof(t_node));
	map->rear = map->front;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	map->open = FALSE;
	return (0);
}

void	player_init(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->collectible = 0;
	player->movement = 0;
	player->happy_ending = FALSE;
}

void	image_init(t_img *img)
{
	img->data = (int *)mlx_get_data_addr(img->img, &(img->bpp), \
						&(img->size_line), &(img->endian));
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->width = 1200;
	game->height = 1000;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->img = (t_img *)malloc(sizeof(t_img));
	game->img->img = mlx_new_image(game->mlx, game->width, game->height);
	image_init(game->img);
	game->fd = 0;
	game->finish = FALSE;
	game->error = FALSE;
	game->player = (t_player *)malloc(sizeof(t_player));
	player_init(game->player);
	game->map = (t_map *)malloc(sizeof(t_map));
	if (map_init(game->map) == ERROR)
		return (ERROR);
	return (0);
}
