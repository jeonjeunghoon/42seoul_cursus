/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:25:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 04:06:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	check_wall(char **map, t_enemy *head)
{
	if (head->direction == UP && map[head->y - 1][head->x] == WALL)
		return (TRUE);
	else if (head->direction == RIGHT && map[head->y][head->x + 1] == WALL)
		return (TRUE);
	else if (head->direction == DOWN && map[head->y + 1][head->x] == WALL)
		return (TRUE);
	else if (head->direction == LEFT && map[head->y][head->x - 1] == WALL)
		return (TRUE);
	return (TRUE);
}

void	move_enemy(char **map, t_enemy *head)
{
	map[head->y][head->x] = ROAD;
	if (head->direction == UP)
	{
		map[head->y - 1][head->x] = ENEMY;
		head->y = head->y - 1;
	}
	else if (head->direction == DOWN)
	{
		map[head->y + 1][head->x] = ENEMY;
		head->y = head->y + 1;
	}
	else if (head->direction == RIGHT)
	{
		map[head->y][head->x + 1] = ENEMY;
		head->x = head->x + 1;
	}
	else if (head->direction == LEFT)
	{
		map[head->y][head->x - 1] = ENEMY;
		head->x = head->x - 1;
	}
}

int	check_direction(t_map *map, int x, int y, t_enemy *head)
{
	if (y < map->y - 1 && head->direction != DOWN)
	{
		if (map->map[y - 1][x] == ROAD || map->map[y - 1][x] == PLAYER)
			return (UP);
	}
	if (x < map->x - 1 && head->direction != LEFT)
	{
		if (map->map[y][x + 1] == ROAD || map->map[y][x + 1] == PLAYER)
			return (RIGHT);
	}
	if (y > 0 && head->direction != UP)
	{
		if (map->map[y + 1][x] == ROAD || map->map[y + 1][x] == PLAYER)
			return (DOWN);
	}
	if (x > 0 && head->direction != RIGHT)
	{
		if (map->map[y][x - 1] == ROAD || map->map[y][x - 1] == PLAYER)
			return (LEFT);
	}
	return (BLOCKED);
}

void	enemy_action(t_game *game)
{
	t_enemy	*head;
	int		wall;

	head = game->map->e_rear;
	while (head->next != NULL)
	{
		wall = FALSE;
		while (wall != TRUE)
		{
			head->direction = check_direction(game->map, head->x, head->y, \
												head);
			if (head->direction == BLOCKED)
				break ;
			move_enemy(game->map->map, head);
			wall = check_wall(game->map->map, head);
		}
		head = head->next;
	}
}
