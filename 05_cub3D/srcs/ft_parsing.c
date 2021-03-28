#include "cub.h"

void				get_route(t_cub *cub, int idx)
{
	int				s;
	int				end;

	end = 2;
	while (cub->map.data[idx][end] == ' ' || cub->map.data[idx][end] == '\t' \
	|| cub->map.data[idx][end] == '\r' || cub->map.data[idx][end] == '\v' || \
	cub->map.data[idx][end] == '\f')
		end++;
	s = end;
	while (cub->map.data[idx][end] >= 33 && cub->map.data[idx][end] <= 126)
		end++;
	if (cub->map.data[idx][0] == 'E')
		cub->map.ea = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][0] == 'N')
		cub->map.no = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][0] == 'W')
		cub->map.we = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][0] == 'S' && \
	cub->map.data[idx][1] == 'O')
		cub->map.so = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][0] == 'S' && \
	cub->map.data[idx][1] != 'O')
		cub->map.s = ft_substr(cub->map.data[idx], s, end);
}

void				get_numdata(t_cub *cub, int idx, int loop)
{
	int				x;
	int				start;
	int				end;

	x = 0;
	end = 0;
	while (x < loop)
	{
		while (!(cub->map.data[idx][end] >= '0' && \
					cub->map.data[idx][end] <= '9'))
			end++;
		start = end;
		while (cub->map.data[idx][end] >= '0' && \
				cub->map.data[idx][end] <= '9')
			end++;
		if (cub->map.data[idx][0] == 'R')
			cub->map.r[x] = ft_atoi(ft_substr(cub->map.data[idx], start, end));
		else if (cub->map.data[idx][0] == 'C')
			cub->map.c[x] = ft_atoi(ft_substr(cub->map.data[idx], start, end));
		else if (cub->map.data[idx][0] == 'F')
			cub->map.f[x] = ft_atoi(ft_substr(cub->map.data[idx], start, end));
		x++;
	}
}

void				get_data(t_cub *cub)
{
	int				idx;

	idx = 0;
	while (idx < 8)
	{
		if (cub->map.data[idx][0] == 'R')
			get_numdata(cub, idx, 2);
		if (cub->map.data[idx][0] == 'C' || cub->map.data[idx][0] == 'F')
			get_numdata(cub, idx, 3);
		else
			get_route(cub, idx);
		idx++;
	}
}

void				ft_parsing(t_cub *cub)
{
	int				src[MY][MX] = {
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,'E',0,2,1,1,1,1,1,1,1,1,1,1},
  					{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
					};

	char			buf[2];
	int				idx;
	int				fd;

	cub->map.data = (char **)malloc(sizeof(char *) * 9);
	fd = open("cub.map", O_RDONLY);
	idx = 0;
	while (idx < 8)
	{
		get_next_line(fd, &cub->map.data[idx]);
		idx++;
	}
	get_data(cub);
	printf("R: %d %d\n", cub->map.r[0], cub->map.r[1]);
	printf("C: %d,%d,%d\n", cub->map.c[0], cub->map.c[1], cub->map.c[2]);
	printf("F: %d,%d,%d\n", cub->map.f[0], cub->map.f[1], cub->map.f[2]);
	printf("%s %s %s %s\n", cub->map.ea, cub->map.no, cub->map.we, cub->map.so);
	printf("%s\n", cub->map.s);
	close(fd);
	ft_memcpy(cub->map.map, src, sizeof(int) * MX * MY);
}