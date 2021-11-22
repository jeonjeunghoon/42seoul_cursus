/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:58:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 16:55:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	get_enemy_data(t_game *game, int x, int y)
{
	t_enemy	*new_e_front;

	new_e_front = (t_enemy *)malloc(sizeof(t_enemy));
	game->map->e_front->x = x;
	game->map->e_front->y = y;
	game->map->e_front->direction = BLOCKED;
	game->map->e_front->move = FALSE;
	new_e_front->next = NULL;
	game->map->e_front->next = new_e_front;
	game->map->e_front = new_e_front;
	game->map->enemy++;
}

int	check_elements(t_game *game, t_map *map_val, char *map, int y)
{
	int	i;

	if (map[0] != WALL || map[map_val->x - 1] != WALL)
		return (ERROR);
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == PLAYER)
		{
			map_val->player++;
			if (map_val->player > 1)
				return (ERROR);
			game->player->x = i;
			game->player->y = y;
		}
		else if (map[i] == COLLECTIBLE)
			map_val->collectible++;
		else if (map[i] == EXIT)
			map_val->exit++;
		else if (map[i] == ENEMY)
			get_enemy_data(game, i, y);
		else if (map[i] != ROAD && map[i] != WALL)
			return (ERROR);
	}
	return (0);
}

int	check_surrounded(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != WALL)
			return (ERROR);
		i++;
	}
	return (0);
}

int	to_coord(t_game *game, int x, int y)
{
	return (y * game->width + x);
}
