# include "cub.h"

void			get_player_data(t_cub *cub)
{
	if (cub->map[(int)cub->p_y][(int)cub->p_x] == 'E')
		cub->p_th = deg_to_rad(0);
	else if (cub->map[(int)cub->p_y][(int)cub->p_x] == 'N')
		cub->p_th = deg_to_rad(90);
	else if (cub->map[(int)cub->p_y][(int)cub->p_x] == 'W')
		cub->p_th = deg_to_rad(180);
	else
		cub->p_th = deg_to_rad(270);
	cub->fov_w = deg_to_rad(FOV_W_DEG);
	cub->half_fov_w = cub->fov_w / 2;
	cub->per_fov_w = cub->fov_w/(SW-1);
	cub->fov_h = (cub->fov_w * SH)/SW;
}

void			ft_player(t_cub *cub)
{
	cub->p_y = 0;
	while (cub->p_y < MH)
	{
		cub->p_x = 0;
		while (cub->p_x < MW)
		{
			if (cub->map[(int)cub->p_y][(int)cub->p_x] > 2)
			{
				get_player_data(cub);
				return ;
			}
			cub->p_x++;
		}
		cub->p_y++;
	}
}