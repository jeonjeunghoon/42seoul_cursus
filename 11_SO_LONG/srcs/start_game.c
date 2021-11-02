/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 02:06:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	encounter_enemy(t_game *game, int check_x, int check_y)
{
	move_player(game, check_x, check_y); // 플레이어 이동 함수
	game->player->bad_ending = TRUE; // 플레이어 사망
}

void	collect_func(t_game *game, int check_x, int check_y)
{
	move_player(game, check_x, check_y);
	game->player->collectible++; // 플레이어가 모은 수집품
	game->map->map[game->player->y][game->player->x] = 0; // 맵 업데이트
	game->map->collectible--; // 맵에 남아있는 수집품
}

void	check_path(t_game *game, int check_x, int check_y)
{
	if (game->map->map[check_y][check_x] == ROAD) // 갈 수 있는 경우
		move_player(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == COLLECTIBLE) // 수집품인 경우
		collect_func(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == ENEMY) // 적인 경우
		encounter_enemy(game, check_x, check_y);
	else if (game->map->map[check_y][check_x] == WALL) // 벽인 경우
		return ;
	else // 그 외의 알 수 없는 에러 발생 시
		game->is_error = TRUE;
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

int	start_game(t_game *game)
{
	// mlx_loop_hook(game->mlx, , game);
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, ft_key, game);
	mlx_hook(game->win, EVENT_EXIT, 0, ft_exit, "EXIT SO_LONG\n");
	if (game->player->happy_ending == TRUE || \
		game->player->bad_ending == TRUE) // 게임 종료 조건: 수집품을 다 모으거나 적과 닿아서 죽거나
		return (0);
	if (game->is_error == TRUE)
		return (ERROR);
	mlx_loop(game->mlx);
	return (0);
}
