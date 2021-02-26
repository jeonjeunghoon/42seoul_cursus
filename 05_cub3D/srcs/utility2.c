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
	dist = sqrt(dx * dx + dy * dy);
    return (dist);
}