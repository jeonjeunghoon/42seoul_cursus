#include "cub.h"

void	write_bmp_header(t_cub *cub, int fd)
{
	unsigned char bmp_h[54];
	int file_size;

	ft_bzero(bmp_h, 54);
	file_size = 4 * cub->scr.sy * cub->scr.sx + 54;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = file_size;
	bmp_h[3] = (file_size >> 8);
	bmp_h[4] = (file_size >> 16);
	bmp_h[5] = (file_size >> 24);
	bmp_h[10] = 54;
	bmp_h[14] = 40;
	bmp_h[18] = cub->scr.sx;
	bmp_h[19] = cub->scr.sx >> 8;
	bmp_h[20] = cub->scr.sx >> 16;
	bmp_h[21] = cub->scr.sx >> 24;
	bmp_h[22] = -cub->scr.sy;
	bmp_h[23] = -cub->scr.sy >> 8;
	bmp_h[24] = -cub->scr.sy >> 16;
	bmp_h[25] = -cub->scr.sy >> 24;
	bmp_h[26] = 1;
	bmp_h[28] = 32;
	write(fd, bmp_h, 54);
}

void			ft_save(t_cub *cub)
{
	int		fd;

	fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0744);
	write_bmp_header(cub, fd);
	write(fd, cub->img.data, cub->scr.sx * cub->scr.sy * 4);
	printf("cub.bmp file has been saved\n");
	close(fd);
	ft_exit(cub);
}