/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 01:03:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:45:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	end_game(t_game *game, int check_x, int check_y, int ending_flag)
{
	if (ending_flag == HAPPY && game->map->open == TRUE)
	{
		move_player(game, check_x, check_y);
		game->player->happy_ending = TRUE;
	}
	else if (ending_flag == BAD)
	{
		move_player(game, check_x, check_y);
		game->player->bad_ending = TRUE;
	}
}

void	collect_func(t_game *game, int check_x, int check_y)
{
	move_player(game, check_x, check_y);
	game->player->collectible++;
	game->map->map[game->player->y][game->player->x] = ROAD;
	game->map->collectible--;
	if (game->map->collectible == 0)
		game->map->open = TRUE;
}

void	move_player(t_game *game, int check_x, int check_y)
{
	game->map->map[game->player->y][game->player->x] = ROAD;
	game->player->x = check_x;
	game->player->y = check_y;
	if (game->map->map[check_y][check_x] != EXIT && \
		game->map->map[check_y][check_x] != ENEMY)
		game->map->map[check_y][check_x] = PLAYER;
	game->player->movement++;

	for (int i = 0; game->map->map[i]; i++)
		printf("%s\n", game->map->map[i]);

	printf("x: %d y: %d movement: %d\n\n", \
	game->player->x, game->player->y, game->player->movement);
}

void	check_path(t_game *game, int check_x, int check_y)
{
	if (check_x < 0 || check_y < 0)
		game->error = TRUE;
	else if (game->map->map[check_y][check_x] == ROAD)
		move_player(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == COLLECTIBLE)
		collect_func(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == ENEMY)
		end_game(game, check_x, check_y, BAD);
	else if (game->map->map[check_y][check_x] == EXIT)
		end_game(game, check_x, check_y, HAPPY);
	else if (game->map->map[check_y][check_x] == WALL)
		return ;
	else
		game->error = TRUE;
}

int	ft_key(int keycode, t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = game->player->x;
	check_y = game->player->y;
	if (keycode == KEY_ESC)
		ft_exit("EXIT SO_LONG\n");
	if (keycode == KEY_D)
		check_x++;
	else if (keycode == KEY_A)
		check_x--;
	else if (keycode == KEY_S)
		check_y++;
	else if (keycode == KEY_W)
		check_y--;
	check_path(game, check_x, check_y);
	enemy_action(game);
	return (0);
}
