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

int				cmp_sprite(double d1, double d2)
{
	if (d1 > d2)
		return (-1);
	return (1);
}

// void			qsort()