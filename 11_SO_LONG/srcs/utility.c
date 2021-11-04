/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:58:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 01:00:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *game, int check_x, int check_y, int ending_flag)
{
	if (ending_flag == HAPPY && game->map->open == TRUE)
	{
		move_player(game, check_x, check_y); // 플레이어 이동 함수
		game->player->happy_ending = TRUE;
	}
	else if (ending_flag == BAD)
	{
		move_player(game, check_x, check_y); // 플레이어 이동 함수
		game->player->bad_ending = TRUE;
	}
}

void	collect_func(t_game *game, int check_x, int check_y)
{
	move_player(game, check_x, check_y);
	game->player->collectible++; // 플레이어가 모은 수집품
	game->map->map[game->player->y][game->player->x] = '0'; // 맵 업데이트
	game->map->collectible--; // 맵에 남아있는 수집품
	if (game->map->collectible == 0)
		game->map->open = TRUE;
}

int	check_surrounded(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_elements(t_game *game, t_map *map_val, char *map, int y)
{
	int	i;

	if (map[0] != '1' || map[map_val->x - 1] != '1')
		return (ERROR);
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
		{
			map_val->player++;
			game->player->x = i;
			game->player->y = y;
		}
		else if (map[i] == 'C')
			map_val->collectible++;
		else if (map[i] == 'E')
			map_val->exit++;
		else if (map[i] != '0' && map[i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

void	move_player(t_game *game, int check_x, int check_y)
{
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->x = check_x;
	game->player->y = check_y;
	game->map->map[check_y][check_x] = 'P';
	game->player->movement++;

	for (int i = 0; game->map->map[i]; i++)
		printf("%s\n", game->map->map[i]);

	printf("\nx: %d y: %d movement: %d\n", \
	game->player->x, game->player->y, game->player->movement);
}
