/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:51:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/06 22:53:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				check_map(t_cub *cub)
{
	int				idx;
	int				jdx;

	idx = -1;
	cub->map.is_overlap = 0;
	while (++idx < cub->map.my)
	{
		jdx = -1;
		while (++jdx < cub->map.mx)
		{
			if (cub->map.map[idx][jdx] == 8)
			{
				check_vertex(cub, idx, jdx);
				check_row(cub, idx, jdx);
				check_col(cub, idx, jdx);
				check_etc(cub, idx, jdx);
			}
			if (cub->map.map[idx][jdx] > 'A' && cub->map.map[idx][jdx] < 'Z')
			{
				if (cub->map.is_overlap == 1)
					map_error();
				cub->map.is_overlap = 1;
			}
		}
	}
}

void				fill_space(t_cub *cub, int idx, int jdx)
{
	while (jdx < cub->map.mx)
	{
		cub->map.map[idx][jdx] = 8;
		jdx++;
	}
}

void				fill_map(t_cub *cub)
{
	if (cub->map.parsed_map[cub->map.kdx] == '\n' && \
		cub->map.jdx != 0 && cub->map.kdx < ft_strlen(cub->map.parsed_map))
	{
		while (cub->map.jdx < cub->map.mx)
			cub->map.map[cub->map.idx][cub->map.jdx++] = 8;
	}
	else if (cub->map.parsed_map[cub->map.kdx] == '0' || \
			cub->map.parsed_map[cub->map.kdx] == '1' || \
			cub->map.parsed_map[cub->map.kdx] == '2')
		cub->map.map[cub->map.idx][cub->map.jdx] = \
		cub->map.parsed_map[cub->map.kdx] - '0';
	else if (is_player(cub->map.parsed_map[cub->map.kdx]))
		cub->map.map[cub->map.idx][cub->map.jdx] = \
		cub->map.parsed_map[cub->map.kdx];
	else if (is_space(cub->map.parsed_map[cub->map.kdx]))
		cub->map.map[cub->map.idx][cub->map.jdx] = 8;
	else
		map_error();
}

void				map_init(t_cub *cub)
{
	cub->map.my += 2;
	cub->map.map = (int **)malloc(sizeof(int *) * cub->map.my);
	cub->map.idx = 0;
	cub->map.kdx = 0;
	while (cub->map.idx < cub->map.my)
	{
		cub->map.map[cub->map.idx] = (int *)malloc(sizeof(int) * (cub->map.mx));
		cub->map.jdx = 0;
		if (cub->map.idx == 0 || cub->map.idx == cub->map.my - 1)
			fill_space(cub, cub->map.idx, cub->map.jdx);
		else
		{
			while (cub->map.jdx < cub->map.mx)
			{
				fill_map(cub);
				cub->map.jdx++;
				cub->map.kdx++;
			}
		}
		cub->map.idx++;
	}
}

void				get_map(t_cub *cub, int idx)
{
	char			*room;

	room = ft_strjoin(" ", cub->map.buf[idx]);
	free(cub->map.buf[idx]);
	cub->map.buf[idx] = ft_strdup(room);
	free(room);
	room = ft_strjoin(cub->map.buf[idx], "\n");
	free(cub->map.buf[idx]);
	cub->map.buf[idx] = ft_strdup(room);
	free(room);
	if (cub->map.my == 0)
	{
		cub->map.mx = ft_strlen(cub->map.buf[idx]);
		cub->map.parsed_map = ft_strdup(cub->map.buf[idx]);
	}
	else
	{
		if (cub->map.mx < ft_strlen(cub->map.buf[idx]))
			cub->map.mx = ft_strlen(cub->map.buf[idx]);
		room = ft_strjoin(cub->map.parsed_map, cub->map.buf[idx]);
		free(cub->map.parsed_map);
		cub->map.parsed_map = ft_strdup(room);
		free(room);
	}
	free(cub->map.buf[idx]);
}
