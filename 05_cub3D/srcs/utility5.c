/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:00:17 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/14 09:40:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				check_numdata(t_cub *cub, int idx, int jdx, int check)
{
	while (cub->map.buf[idx][jdx])
	{
		if (!(cub->map.buf[idx][jdx] == ' ' || cub->map.buf[idx][jdx] == ',' \
		|| (cub->map.buf[idx][jdx] >= '0' && cub->map.buf[idx][jdx] <= '9')) \
		|| check == 0)
			map_error();
		while (cub->map.buf[idx][jdx] == ' ' || cub->map.buf[idx][jdx] == ',')
			jdx++;
		if (cub->map.buf[idx][jdx] >= '0' && cub->map.buf[idx][jdx] <= '9')
			check--;
		while (cub->map.buf[idx][jdx] >= '0' && cub->map.buf[idx][jdx] <= '9')
			jdx++;
	}
}

void				check_num(t_cub *cub)
{
	if (cub->map.r[0] <= 0 || cub->map.r[1] <= 0 || cub->map.c[0] < 0 \
	|| cub->map.c[1] < 0 || cub->map.c[2] < 0 || cub->map.f[0] < 0 \
	|| cub->map.f[1] < 0 || cub->map.f[2] < 0 || cub->map.c[0] > 255 \
	|| cub->map.c[1] > 255 || cub->map.c[2] > 255 || cub->map.f[0] > 255 \
	|| cub->map.f[1] > 255 || cub->map.f[2] > 255)
		map_error();
}

void				check_mapdata(t_cub *cub)
{
	int				j;

	j = 0;
	while (j < ft_strlen(cub->map.parsed_map))
	{
		if (cub->map.parsed_map[j] != '0' && cub->map.parsed_map[j] != '1' \
		&& cub->map.parsed_map[j] != '2' && cub->map.parsed_map[j] != ' ' \
		&& cub->map.parsed_map[j] != 'E' && cub->map.parsed_map[j] != 'N' \
		&& cub->map.parsed_map[j] != 'W' && cub->map.parsed_map[j] != 'S' \
		&& cub->map.parsed_map[j] != '\n')
			map_error();
		j++;
	}
}
