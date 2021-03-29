#include "cub.h"

int					is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || \
		c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int					except_space(t_cub *cub, int idx)
{
	int				jdx;

	jdx = 0;
	while (is_space(cub->map.data[idx][jdx]))
		jdx++;
	if (!cub->map.data[idx][jdx])
	{
		ft_free((void *)&cub->map.data[idx]);
		return (-1);
	}
	return (jdx);
}

void				*ft_realloc(void *ptr, int type, int size)
{
	if (ptr)
	{
		ft_free((void *)&ptr);
		ptr = malloc(type * size);
		return (ptr);
	}
	return (0);
}