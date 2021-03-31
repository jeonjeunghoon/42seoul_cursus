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
	while (is_space(cub->map.buf[idx][jdx]))
		jdx++;
	if (!cub->map.buf[idx][jdx])
	{
		ft_free((void *)&cub->map.buf[idx]);
		return (-1);
	}
	return (jdx);
}

t_sprite			*sprite_realloc(t_sprite *ptr, int n)
{
	t_sprite		*new_ptr;
	int				i;

	if (!ptr)
		return (0);
	new_ptr = (t_sprite *)malloc(sizeof(t_sprite) * (n + 1));
	i = 0;
	while (i < n)
	{
		new_ptr[i].x = ptr[i].x;
		new_ptr[i].y = ptr[i].y;
		new_ptr[i].dist = ptr[i].dist;
		new_ptr[i].th = ptr[i].th;
		new_ptr[i].tex = ptr[i].tex;
		i++;
	}
	ft_free((void *)&ptr);
	return (new_ptr);
}

int					is_player(t_cub *cub, char player)
{
	if (player == 'E' || player == 'N' || player == 'W' || player == 'S')
	{
		if (player == 'E')
			return ('E');
		else if (player == 'N')
			return ('N');
		else if (player == 'W')
			return ('W');
		else if (player == 'S')
			return ('S');
	}
	return (0);
}