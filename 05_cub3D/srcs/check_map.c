/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:51:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/09 20:10:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				is_wall(t_cub *cub, int idx, int jdx)
{
	if (cub->map.map[idx][jdx] == 0)
		map_error();
}

void				check_vertex(t_cub *cub, int idx, int jdx)
{
	if (idx == 0 && jdx == 0)
	{
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx + 1, jdx + 1);
	}
	else if (idx == 0 && jdx == cub->map.mx - 1)
	{
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx + 1, jdx - 1);
	}
	else if (idx == cub->map.my - 1 && jdx == 0)
	{
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx - 1, jdx + 1);
	}
	else if (idx == cub->map.my - 1 && jdx == cub->map.mx - 1)
	{
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx - 1, jdx - 1);
	}
}

void				check_row(t_cub *cub, int idx, int jdx)
{
	if (jdx == 0 && idx != 0 && idx != cub->map.my - 1)
	{
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx - 1, jdx + 1);
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx + 1, jdx + 1);
	}
	else if (jdx == cub->map.mx - 1 && idx != 0 && idx != cub->map.my - 1)
	{
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx - 1, jdx - 1);
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx + 1, jdx - 1);
	}
}

void				check_col(t_cub *cub, int idx, int jdx)
{
	if (idx == 0 && jdx != 0 && jdx != cub->map.mx - 1)
	{
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx + 1, jdx - 1);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx + 1, jdx + 1);
	}
	else if (idx == cub->map.my - 1 && jdx != 0 && jdx != cub->map.mx - 1)
	{
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx - 1, jdx - 1);
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx - 1, jdx + 1);
	}
}

void				check_etc(t_cub *cub, int idx, int jdx)
{
	if (idx != 0 && jdx != 0 && \
		idx != cub->map.my - 1 && jdx != cub->map.mx - 1)
	{
		is_wall(cub, idx - 1, jdx - 1);
		is_wall(cub, idx - 1, jdx);
		is_wall(cub, idx - 1, jdx + 1);
		is_wall(cub, idx, jdx - 1);
		is_wall(cub, idx, jdx + 1);
		is_wall(cub, idx + 1, jdx - 1);
		is_wall(cub, idx + 1, jdx);
		is_wall(cub, idx + 1, jdx + 1);
	}
}
