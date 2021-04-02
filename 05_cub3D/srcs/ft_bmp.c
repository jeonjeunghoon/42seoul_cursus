/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/01 12:15:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				write_bmp_header(t_cub *cub, int fd)
{
	unsigned char	bmp_h[54];
	int				file_size;

	ft_bzero(bmp_h, 54);
	file_size = 4 * cub->map.r[1] * cub->map.r[0] + 54;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = file_size;
	bmp_h[3] = (file_size >> 8);
	bmp_h[4] = (file_size >> 16);
	bmp_h[5] = (file_size >> 24);
	bmp_h[10] = 54;
	bmp_h[14] = 40;
	bmp_h[18] = cub->map.r[0];
	bmp_h[19] = cub->map.r[0] >> 8;
	bmp_h[20] = cub->map.r[0] >> 16;
	bmp_h[21] = cub->map.r[0] >> 24;
	bmp_h[22] = -cub->map.r[1];
	bmp_h[23] = -cub->map.r[1] >> 8;
	bmp_h[24] = -cub->map.r[1] >> 16;
	bmp_h[25] = -cub->map.r[1] >> 24;
	bmp_h[26] = 1;
	bmp_h[28] = 32;
	write(fd, bmp_h, 54);
}

void				ft_save(t_cub *cub)
{
	int				fd;

	fd = open("bmp/cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0744);
	write_bmp_header(cub, fd);
	write(fd, cub->img.data, cub->map.r[0] * cub->map.r[1] * 4);
	printf("cub.bmp file has been saved\n");
	close(fd);
	ft_exit(cub);
}
