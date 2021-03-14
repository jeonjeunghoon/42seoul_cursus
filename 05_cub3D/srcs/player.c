# include "cub.h"

void			get_player_data(t_cub *cub)
{
	if (cub->map[(int)cub->player.x][(int)cub->player.y] == 'E')
		cub->player.th = deg_to_rad(0);
	else if (cub->map[(int)cub->player.x][(int)cub->player.y] == 'N')
		cub->player.th = deg_to_rad(90);
	else if (cub->map[(int)cub->player.x][(int)cub->player.y] == 'W')
		cub->player.th = deg_to_rad(180);
	else
		cub->player.th = deg_to_rad(270);
	cub->player.fov_h = deg_to_rad(FOV);
	cub->player.fovh_2 = cub->player.fov_h / 2.0;
	cub->player.per_fov_h = cub->player.fov_h / (cub->sx - 1.0);
	cub->player.fov_v = cub->player.fov_h * (double)cub->sy / (double)cub->sx;
}

void			ft_player(t_cub *cub)
{
	double		temp;

	cub->player.x = 0;
	while (cub->player.x < MX)
	{
		cub->player.y = 0;
		while (cub->player.y < MY)
		{
			if (cub->map[(int)cub->player.x][(int)cub->player.y] > 2)
			{
				get_player_data(cub);
				cub->player.x += 0.5;
				cub->player.y += 0.5;
				return ;
			}
			cub->player.y++;
		}
		cub->player.x++;
	}
	printf("Error: No Player\n");
	ft_exit(cub);
}