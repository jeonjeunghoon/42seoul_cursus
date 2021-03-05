#include "cub.h"

t_sprite		*get_visible_sprites(t_cub *cub, t_sprite *sprite, int *pcnt)
{
	int			n;
	t_sprite	*sp;

	n = 0;
	sp = NULL;

	for (int x = 0; x < MW; x++)
	{
		for (int y = 0; y < MH; y++)
		{
			if (cub->map[x][y] == 0 || get_cell(cub, x, y) <= 1)
				continue ;
			if (n == 0)
				sp = (t_sprite *)malloc(sizeof(t_sprite));
			else
				sp = (t_sprite *)realloc(sp, sizeof(t_sprite) * (n + 1));
			sp[n].tex = (map_get_cell(x,y) - 1) + 5;
            sp[n].x = x;
            sp[n].y = y;
            sp[n].th = atan2((y+0.5)-(cub->py), (x+0.5)-(cub->px));
            if( sp[n].th < 0 ) sp[n].th += 180;
            sp[n].dist = l2dist(cub->px, cub->py, x+0.5, y+0.5) * cos(cub->pth - sp[n].th);
            n++;

		}
	}
	*pcnt = n;
    return (sp);
}

void			ft_sprite(t_cub *cub, t_sprite *sprite)
{
	
}