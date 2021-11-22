/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 18:03:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	ending(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		ft_exit("CLEAR !!!\n");
	}
	if (game->player->bad_ending == TRUE)
	{
		ft_exit("GAME OVER !!!\n");
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	set_draw_var(game);
	x = game->draw->camera_pivot_x;
	while (x < game->draw->camera_pivot_x + game->draw->max_screen_x)
	{
		y = game->draw->camera_pivot_y;
		while (y < game->draw->camera_pivot_y + game->draw->max_screen_y)
		{
			draw_road(game, x, y);
			if (game->map->map[y][x] == WALL)
				draw_wall(game, x, y);
			else if (game->map->map[y][x] == COLLECTIBLE)
				draw_collect(game, x, y);
			else if (game->map->map[y][x] == ENEMY)
				draw_enemy(game, x, y);
			else if (game->map->map[y][x] == PLAYER)
				draw_player(game, x, y);
			else if (game->map->map[y][x] == EXIT)
				draw_exit(game, x, y);
			y++;
		}
		x++;
	}
}

int	so_long(t_game *game)
{
	char	*move_cnt;

	usleep(50000);
	move_cnt = ft_itoa(game->player->movement);
	if (game->map->enemy != 0)
		enemy_action(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x0000FF, move_cnt);
	free(move_cnt);
	if (game->player->happy_ending == TRUE || \
		game->player->bad_ending == TRUE)
		ending(game);
	return (0);
}
