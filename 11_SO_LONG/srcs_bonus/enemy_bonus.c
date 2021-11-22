/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:25:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/22 20:27:58 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	move_enemy(t_game *game, t_enemy *head)
{
	game->map->map[head->y][head->x] = ROAD;
	if (head->direction == UP)
	{
		game->map->map[head->y - 1][head->x] = ENEMY;
		head->y = head->y - 1;
	}
	else if (head->direction == DOWN)
	{
		game->map->map[head->y + 1][head->x] = ENEMY;
		head->y = head->y + 1;
	}
	else if (head->direction == RIGHT)
	{
		game->map->map[head->y][head->x + 1] = ENEMY;
		head->x = head->x + 1;
	}
	else if (head->direction == LEFT)
	{
		game->map->map[head->y][head->x - 1] = ENEMY;
		head->x = head->x - 1;
	}
}

void	is_player_die(t_game *game, t_enemy *head)
{
	if (head->direction == UP)
	{
		if (game->map->map[head->y - 1][head->x] == PLAYER)
			game->player->bad_ending = TRUE;
	}
	else if (head->direction == DOWN)
	{
		if (game->map->map[head->y + 1][head->x] == PLAYER)
			game->player->bad_ending = TRUE;
	}
	else if (head->direction == RIGHT)
	{
		if (game->map->map[head->y][head->x + 1] == PLAYER)
			game->player->bad_ending = TRUE;
	}
	else if (head->direction == LEFT)
	{
		if (game->map->map[head->y][head->x - 1] == PLAYER)
			game->player->bad_ending = TRUE;
	}
}

int	check_direction(t_map *map, int x, int y)
{
	int	direction;

	direction = rand() % 4;
	if (y < map->y - 1 && direction == 0)
	{
		if (map->map[y - 1][x] == ROAD || map->map[y - 1][x] == PLAYER)
			return (UP);
	}
	if (x < map->x - 1 && direction == 1)
	{
		if (map->map[y][x + 1] == ROAD || map->map[y][x + 1] == PLAYER)
			return (RIGHT);
	}
	if (y > 0 && direction == 2)
	{
		if (map->map[y + 1][x] == ROAD || map->map[y + 1][x] == PLAYER)
			return (DOWN);
	}
	if (x > 0 && direction == 3)
	{
		if (map->map[y][x - 1] == ROAD || map->map[y][x - 1] == PLAYER)
			return (LEFT);
	}
	return (BLOCKED);
}

void	enemy_action(t_game *game)
{
	t_enemy	*head;

	head = game->map->e_rear;
	while (head->next != NULL)
	{
		head->direction = check_direction(game->map, head->x, head->y);
		if (head->direction == BLOCKED)
			break ;
		is_player_die(game, head);
		move_enemy(game, head);
		head = head->next;
	}
}
