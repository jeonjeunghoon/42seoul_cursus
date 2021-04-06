/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:50 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/06 22:13:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int					is_space(char c)
{
	if (c == ' ')
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

int					is_player(char player)
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

int					get_sprite_color(t_cub *cub, int tx, int ty)
{
	int			color;

	color = cub->tex.texture[cub->ray.wdir][ty * 120 + tx];
	return (color);
}
