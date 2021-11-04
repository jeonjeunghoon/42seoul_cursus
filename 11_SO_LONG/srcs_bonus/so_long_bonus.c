/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:45:25 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	ending(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		ft_exit("happy ending!\n");
	}
	if (game->player->bad_ending == TRUE)
	{
		ft_exit("bad ending!\n");
	}
}

int	so_long(t_game *game)
{
	if (game->player->happy_ending == TRUE || \
		game->player->bad_ending == TRUE)
		ending(game);
	return (0);
}
