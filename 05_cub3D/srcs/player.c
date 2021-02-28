# include "cub.h"

void			get_player_data(t_cub *cub)
{
	if (cub->map[(int)cub->py][(int)cub->px] == 'E')
		cub->pth = deg_to_rad(0);
	else if (cub->map[(int)cub->py][(int)cub->px] == 'N')
		cub->pth = deg_to_rad(90);
	else if (cub->map[(int)cub->py][(int)cub->px] == 'W')
		cub->pth = deg_to_rad(180);
	else
		cub->pth = deg_to_rad(270);
	cub->fov_w = deg_to_rad(FOV_W_DEG);
	cub->half_fov_w = cub->fov_w / 2.0;
	cub->per_fov_w = cub->fov_w/(cub->sw-1.0);
	cub->fov_h = cub->fov_w * cub->sh/cub->sw;
}

void			ft_player(t_cub *cub)
{
	cub->py = 0;
	while (cub->py < MH)
	{
		cub->px = 0;
		while (cub->px < MW)
		{
			if (cub->map[(int)cub->py][(int)cub->px] >= 'E')
			{
				get_player_data(cub);
				return ;
			}
			cub->px++;
		}
		cub->py++;
	}
}