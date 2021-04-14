/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:15 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/14 11:39:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				get_route(t_cub *cub, int idx, int jdx)
{
	char			*ptr;
	int				s;
	int				end;

	end = jdx + 2;
	while (is_space(cub->map.buf[idx][end]))
		end++;
	s = end;
	while (cub->map.buf[idx][end] >= 33 && cub->map.buf[idx][end] <= 126)
		end++;
	ptr = ft_substr(cub->map.buf[idx], s, end);
	if (cub->map.buf[idx][jdx] == 'E')
		cub->map.ea = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'N')
		cub->map.no = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'W')
		cub->map.we = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][jdx + 1] == 'O')
		cub->map.so = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][jdx + 1] != 'O')
		cub->map.s = ft_strdup(ptr);
	free(ptr);
}

void				get_numdata(t_cub *cub, int idx, int jdx, int loop)
{
	int				x;
	int				start;
	int				end;

	x = -1;
	end = jdx + 1;
	while (++x < loop)
	{
		while (cub->map.buf[idx][end] == ' ' || cub->map.buf[idx][end] == ',')
			end++;
		start = end;
		while (cub->map.buf[idx][end] >= '0' && \
				cub->map.buf[idx][end] <= '9')
			end++;
		cub->map.ptr = ft_substr(cub->map.buf[idx], start, end);
		if (cub->map.buf[idx][jdx] == 'R')
			cub->map.r[x] = ft_atoi(cub->map.ptr);
		else if (cub->map.buf[idx][jdx] == 'C')
			cub->map.c[x] = ft_atoi(cub->map.ptr);
		else if (cub->map.buf[idx][jdx] == 'F')
			cub->map.f[x] = ft_atoi(cub->map.ptr);
		free(cub->map.ptr);
	}
}

void				get_data(t_cub *cub, int idx, int jdx)
{
	if (cub->map.buf[idx][jdx] == 'R')
	{
		check_numdata(cub, idx, jdx + 1, 2);
		get_numdata(cub, idx, jdx, 2);
	}
	else if (cub->map.buf[idx][jdx] == 'C' || cub->map.buf[idx][jdx] == 'F')
	{
		check_numdata(cub, idx, jdx + 1, 3);
		get_numdata(cub, idx, jdx, 3);
	}
	else if (cub->map.buf[idx][jdx] == 'E' || cub->map.buf[idx][jdx] == 'N' \
	|| cub->map.buf[idx][jdx] == 'W' || cub->map.buf[idx][jdx] == 'S')
		get_route(cub, idx, jdx);
	else
		map_error();
	free(cub->map.buf[idx]);
}

void				read_map(t_cub *cub, int idx, int jdx)
{
	idx = 0;
	cub->map.is_read = cub->map.fd;
	while (cub->map.is_read)
	{
		cub->map.is_read = get_next_line(cub->map.fd, &cub->map.buf[idx]);
		jdx = except_space(cub, idx);
		if (cub->map.my > 0 && jdx == -1)
			map_error();
		if (jdx != -1 && cub->map.buf[idx])
		{
			if (idx < 8)
			{
				get_data(cub, idx, jdx);
				idx++;
			}
			else if (idx == 8)
			{
				get_map(cub, idx);
				cub->map.my++;
			}
		}
	}
}

void				parsing_init(t_cub *cub)
{
	int				idx;
	int				jdx;

	cub->map.buf = (char **)malloc(sizeof(char *) * 10);
	cub->map.fd = open("cub.map", O_RDONLY);
	idx = 0;
	jdx = 0;
	cub->map.r = (int *)malloc(sizeof(int) * 2);
	cub->map.c = (int *)malloc(sizeof(int) * 3);
	cub->map.f = (int *)malloc(sizeof(int) * 3);
	read_map(cub, idx, jdx);
	free(cub->map.buf);
	close(cub->map.fd);
	check_num(cub);
	check_mapdata(cub);
	map_init(cub);
	check_map(cub);
	free(cub->map.parsed_map);
}
