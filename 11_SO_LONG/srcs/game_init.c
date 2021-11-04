/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:49:24 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 00:53:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	enemy_init(t_enemy *enemy)
{
	enemy->x = 0;
	enemy->y = 0;
}

int		map_init(t_map *map)
{
	map->front = (t_node *)malloc(sizeof(t_node));
	if (map->front == NULL)
		return (ERROR);
	map->rear = map->front;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	return (0);
}

void	player_init(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->collectible = 0;
	player->movement = 0;
	player->happy_ending = FALSE;
	player->bad_ending = FALSE;
}

int	game_init(t_game **game)
{
	(*game) = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
		return (ERROR);
	(*game)->mlx = mlx_init();
	(*game)->win = mlx_new_window((*game)->mlx, 500, 500, "so_long");
	(*game)->error = FALSE;
	(*game)->player = (t_player *)malloc(sizeof(t_player));
	if ((*game)->player == NULL)
		return (ERROR);
	player_init((*game)->player);
	(*game)->map = (t_map *)malloc(sizeof(t_map));
	if ((*game)->map == NULL)
		return (ERROR);
	if (map_init((*game)->map) == ERROR)
		return (ERROR);
	(*game)->enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if ((*game)->enemy == NULL)
		return (ERROR);
	enemy_init((*game)->enemy);
	return (0);
}
