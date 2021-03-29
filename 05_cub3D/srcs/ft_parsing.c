#include "cub.h"

void				get_route(t_cub *cub, int idx, int jdx)
{
	int				s;
	int				end;

	end = jdx + 2;
	while (cub->map.data[idx][end] == ' ' || cub->map.data[idx][end] == '\t' \
	|| cub->map.data[idx][end] == '\r' || cub->map.data[idx][end] == '\v' || \
	cub->map.data[idx][end] == '\f')
		end++;
	s = end;
	while (cub->map.data[idx][end] >= 33 && cub->map.data[idx][end] <= 126)
		end++;
	if (cub->map.data[idx][jdx] == 'E')
		cub->map.ea = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][jdx] == 'N')
		cub->map.no = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][jdx] == 'W')
		cub->map.we = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][jdx] == 'S' && \
	cub->map.data[idx][1] == 'O')
		cub->map.so = ft_substr(cub->map.data[idx], s, end);
	else if (cub->map.data[idx][jdx] == 'S' && \
	cub->map.data[idx][1] != 'O')
		cub->map.s = ft_substr(cub->map.data[idx], s, end);
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
		while (!(cub->map.data[idx][end] >= '0' && \
					cub->map.data[idx][end] <= '9'))
			end++;
		start = end;
		while (cub->map.data[idx][end] >= '0' && \
				cub->map.data[idx][end] <= '9')
			end++;
		ptr = ft_substr(cub->map.data[idx], start, end);
		if (cub->map.data[idx][jdx] == 'R')
			cub->map.r[x] = ft_atoi(ptr);
		else if (cub->map.data[idx][jdx] == 'C')
			cub->map.c[x] = ft_atoi(ptr);
		else if (cub->map.data[idx][jdx] == 'F')
			cub->map.f[x] = ft_atoi(ptr);
		ft_free((void *)&ptr);
		x++;
	}
}

void				get_data(t_cub *cub, int idx, int jdx)
{
	if (cub->map.data[idx][jdx] == 'R')
		get_numdata(cub, idx, jdx, 2);
	else if (cub->map.data[idx][jdx] == 'C' || cub->map.data[idx][jdx] == 'F')
		get_numdata(cub, idx, jdx, 3);
	else
		get_route(cub, idx, jdx);
	ft_free((void *)&cub->map.data[idx]);
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

	char			*head;
	int				idx;
	int				jdx;
	int				kdx;
	int				fd;

	cub->map.data = (char **)malloc(sizeof(char *) * 10);
	cub->map.mx = 0;
	cub->map.my = 0;
	fd = open("cub.map", O_RDONLY);
	idx = 0;
	kdx = 1;
	while (get_next_line(fd, &cub->map.data[idx]))
	{
		jdx = except_space(cub, idx);
		if (idx < 8 && jdx != -1)
		{
			get_data(cub, idx, jdx);
			idx++;
		}
		// if (idx == 8 && jdx != -1)
		// {
		// 	ft_realloc()
		// 	cub->map.my++;
		// }
	}
	free(cub->map.data);
	cub->map.data = NULL;
	close(fd);
	ft_memcpy(cub->map.map, src, sizeof(int) * MX * MY);
}