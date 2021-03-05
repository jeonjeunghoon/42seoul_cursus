# include "cub.h"

int				ft_sgn(double d)
{
	if (fabs(d) < 1e-06)
		return (0);
	else if (d > 0)
		return (1);
	return (-1);
}

double			ft_dist(double s_x, double s_y, double e_x, double e_y)
{
    double		dx;
	double		dy;
	double		dist;

	dx = s_x - e_x;
    dy = s_y - e_y;
	dist = sqrt(pow(dx, 2) + pow(dy, 2));
    return (dist);
}

void			ft_swap(t_sprite *sprite, int i, int j)
{
	t_sprite	buf;

	buf = sprite[i];
	sprite[i] = sprite[j];
	sprite[j] = buf;
}

int				partition(t_sprite *sprite, int start, int end)
{
	double		pivot_dist;
	int			i;

	pivot_dist = sprite[end].dist;
	i = start - 1;
	while (start < end)
	{
		if (pivot_dist > sprite[start].dist)
		{
			i++;
			ft_swap(sprite, start, i);
		}
		start++;
	}
	ft_swap(sprite, end, i + 1);
	return (i + 1);
}

void			qsort(t_sprite *sprite, int start, int end)
{
	int			pivot_i;

	if (start < end)
	{
		pivot_i = partition(sprite, start, end);
		qsort(sprite, start, pivot_i - 1);
		qsort(sprite, pivot_i + 1, end);
	}
}