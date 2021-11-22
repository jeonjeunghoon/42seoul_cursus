/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:59:22 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (exception(argc, argv[1]) == ERROR)
		ft_exit("Please check the input Error\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (game_init(game) == ERROR)
		ft_exit("Game_init Error\n");
	if (assets_parsing(game, argv[1]) == ERROR)
		ft_exit("Assets Error\n");
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, ft_key, (void *)game);
	mlx_hook(game->win, EVENT_EXIT, 0, ft_exit, "EXIT GAME\n");
	mlx_loop_hook(game->mlx, so_long, (void *)game);
	mlx_loop(game->mlx);
	return (0);
}
