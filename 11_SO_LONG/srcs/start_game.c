/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 01:01:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_path(t_game *game, int check_x, int check_y)
{
	if (check_x < 0 || check_y < 0)
		game->error = TRUE;
	else if (game->map->map[check_y][check_x] == ROAD) // 길
		move_player(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == COLLECTIBLE) // 수집품
		collect_func(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == ENEMY) // 적
		end_game(game, check_x, check_y, BAD);
	else if (game->map->map[check_y][check_x] == EXIT) // 출구
		end_game(game, check_x, check_y, HAPPY);
	else if (game->map->map[check_y][check_x] == WALL) // 벽
		return ;
	else // 그 외의 알 수 없는 에러 발생 시
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
	check_path(game, check_x, check_y); // 플레이어가 이동 전에 check_x check_y로 미리 경로를 체크
	return (0);
}

int	so_long(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		ft_exit("happy ending!\n");
	}
	if (game->player->bad_ending == TRUE)
	{
		ft_exit("bad ending!\n");
	}
	return (0);
}
