/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:48:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ending(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		ft_exit("happy ending!\n");
	}
}

int	so_long(t_game *game)
{
	if (game->player->happy_ending == TRUE)
		ending(game);
	return (0);
}
