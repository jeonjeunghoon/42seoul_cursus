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

double			realnum_remainder(double realnum, double div)
{
	double		sub_num;
	double		remainder;

	realnum = fabs(realnum);
	sub_num = realnum / div;
	remainder = realnum - (sub_num * div);
	return (remainder);
}
