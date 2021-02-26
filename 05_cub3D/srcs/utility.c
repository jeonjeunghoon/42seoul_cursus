# include "cub.h"

double			deg_to_rad(double deg)
{
	double		rad;

	rad = deg * (M_PI/180);
	return (rad);
}

double			rad_to_deg(double rad)
{
	double		deg;

	deg = rad * (180/M_PI);
	return (deg);
}

double			get_lower(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

double			get_bigger(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

int				get_cell(t_cub *cub, int x, int y)
{
	if (x >= 0 && x < MW && y >= 0 && y < MH)
		return (cub->map[x][y]);
	return (-1);
}
