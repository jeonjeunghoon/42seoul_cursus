#include "cub.h"

void				map_init(t_cub *cub)
{
	int				idx;
	int				jdx;

	cub->map.map = (int **)malloc(sizeof(int *) * cub->map.my);
	idx = 0;
	while (idx < cub->map.my)
	{
		cub->map.map[idx] = (int *)malloc(sizeof(int) * cub->map.mx);
		jdx = 0;
		while (jdx < cub->map.mx)
		{
			if (cub->map.parsed_map[(idx * cub->map.mx) + jdx] == '0' || \
			cub->map.parsed_map[(idx * cub->map.mx) + jdx] == '1' || \
			cub->map.parsed_map[(idx * cub->map.mx) + jdx] == '2')
				cub->map.map[idx][jdx] = cub->map.parsed_map[(idx * cub->map.mx) + jdx] - '0';
			else if (is_player(cub, cub->map.parsed_map[(idx * cub->map.mx) + jdx]))
				cub->map.map[idx][jdx] = cub->map.parsed_map[(idx * cub->map.mx) + jdx];
			else
				cub->map.map[idx][jdx] = 7;
			jdx++;
		}
		idx++;
	}
	ft_free((void *)&cub->map.parsed_map);
}

void				get_map(t_cub *cub, int idx)
{
	char			*room;

	room = ft_strjoin(cub->map.buf[idx], "\n");
	ft_free((void *)&cub->map.buf[idx]);
	cub->map.buf[idx] = ft_strdup(room);
	ft_free((void *)&room);
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
		ft_free((void *)&cub->map.parsed_map);
		cub->map.parsed_map = ft_strdup(room);
		ft_free((void *)&room);
	}
	ft_free((void *)&cub->map.buf[idx]);
}

void				get_route(t_cub *cub, int idx, int jdx)
{
	int				s;
	int				end;

	end = jdx + 2;
	while (cub->map.buf[idx][end] == ' ' || cub->map.buf[idx][end] == '\t' \
	|| cub->map.buf[idx][end] == '\r' || cub->map.buf[idx][end] == '\v' || \
	cub->map.buf[idx][end] == '\f')
		end++;
	s = end;
	while (cub->map.buf[idx][end] >= 33 && cub->map.buf[idx][end] <= 126)
		end++;
	if (cub->map.buf[idx][jdx] == 'E')
		cub->map.ea = ft_substr(cub->map.buf[idx], s, end);
	else if (cub->map.buf[idx][jdx] == 'N')
		cub->map.no = ft_substr(cub->map.buf[idx], s, end);
	else if (cub->map.buf[idx][jdx] == 'W')
		cub->map.we = ft_substr(cub->map.buf[idx], s, end);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][1] == 'O')
		cub->map.so = ft_substr(cub->map.buf[idx], s, end);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][1] != 'O')
		cub->map.s = ft_substr(cub->map.buf[idx], s, end);
}

void				get_numdata(t_cub *cub, int idx, int jdx, int loop)
{
	char			*ptr;
	int				x;
	int				start;
	int				end;

	x = 0;
	end = jdx;
	while (x < loop)
	{
		while (!(cub->map.buf[idx][end] >= '0' && \
					cub->map.buf[idx][end] <= '9'))
			end++;
		start = end;
		while (cub->map.buf[idx][end] >= '0' && \
				cub->map.buf[idx][end] <= '9')
			end++;
		ptr = ft_substr(cub->map.buf[idx], start, end);
		if (cub->map.buf[idx][jdx] == 'R')
			cub->map.r[x] = ft_atoi(ptr);
		else if (cub->map.buf[idx][jdx] == 'C')
			cub->map.c[x] = ft_atoi(ptr);
		else if (cub->map.buf[idx][jdx] == 'F')
			cub->map.f[x] = ft_atoi(ptr);
		ft_free((void *)&ptr);
		x++;
	}
}

void				get_data(t_cub *cub, int idx, int jdx)
{
	if (cub->map.buf[idx][jdx] == 'R')
		get_numdata(cub, idx, jdx, 2);
	else if (cub->map.buf[idx][jdx] == 'C' || cub->map.buf[idx][jdx] == 'F')
		get_numdata(cub, idx, jdx, 3);
	else
		get_route(cub, idx, jdx);
	ft_free((void *)&cub->map.buf[idx]);
}

void				ft_parsing(t_cub *cub)
{
	// int				src[MY][MX] = {
	// 				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,'E',0,2,1,1,1,1,1,1,1,1,1,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  	// 				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	// 				};

	int				idx;
	int				jdx;
	int				is_read;
	int				fd;

	cub->map.buf = (char **)malloc(sizeof(char *) * 10);
	cub->map.mx = 0;
	cub->map.my = 0;
	fd = open("cub.map", O_RDONLY);
	idx = 0;
	is_read = fd;
	while (is_read)
	{
		is_read = get_next_line(fd, &cub->map.buf[idx]);
		jdx = except_space(cub, idx);
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
	free(cub->map.buf);
	cub->map.buf = NULL;
	close(fd);
	map_init(cub);
	// for (int i = 0; i < cub->map.my; i++)
	// {
	// 	for (int j = 0; j < cub->map.mx; j++)
	// 		printf("%d ", cub->map.map[i][j]);
	// 	printf("\n");
	// }
	// ft_memcpy(cub->map.map, src, sizeof(int) * MX * MY);
}