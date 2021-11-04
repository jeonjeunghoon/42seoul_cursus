/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 00:55:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (exception(argc, argv[1]) == ERROR) // 예외 처리 함수
		ft_exit("Please check the input ERROR\n");
	if (game_init(&game) == ERROR) // 변수 메모리 할당 및 초기화 함수
		ft_exit("Game_init ERROR\n");
	if (assets_parsing(game, argv[1]) == ERROR) // 맵 파싱, 스프라이트 정보 가져오기 함수
		ft_exit("Assets ERROR\n");
	mlx_loop_hook(game->mlx, so_long, (void *)game);
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, ft_key, (void *)game);
	mlx_hook(game->win, EVENT_EXIT, 0, ft_exit, "EXIT SO_LONG\n");
	mlx_loop(game->mlx);
	return (0);
}
