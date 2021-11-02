/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:58:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 01:58:08 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int check_x, int check_y)
{
	game->player->x = check_x;
	game->player->y = check_y;
	game->player->movement++;
	printf("x: %d y: %d movement: %d\n", \
	game->player->x, game->player->y, game->player->movement);
}
