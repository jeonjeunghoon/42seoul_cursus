/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:53:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 01:53:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		// 이미지 삭제 이후 해피엔딩 출력
	}
	if (game->player->bad_ending == TRUE)
	{
		// 이미지 삭제 이후 베드엔딩 출력
	}
	// free_resource(game); 메모리 릭이 나지 않는다면 굳이 해야하나 싶어서 아직 구현 안함
}
