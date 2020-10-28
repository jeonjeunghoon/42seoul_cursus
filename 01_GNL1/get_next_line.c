/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/28 13:52:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t			nextline_in_temp(char **temp, int fd)
{
	size_t		i;

	if (!(temp[fd]))
		return (0);
	i = 0;
	while (temp[fd][i])
	{
		if (temp[fd][i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void			move_temp(char **temp, int fd, size_t i)
{
	char		*head;

	if (!(temp[fd][++i]))
	{
		free(temp[fd]);
		temp[fd] = 0;
		return ;
	}
	head = &(temp[fd][i]);
	temp[fd] = ft_strdup(head);
}

void			line_in_temp(char **temp, char **line, int fd, size_t i)
{
	temp[fd][i] = 0;
	*line = ft_strdup(temp[fd]);
	temp[fd][i] = '\n';
	move_temp(temp, fd, i);
}

int				get_next_line(int fd, char **line)
{
	static char	*temp[FD_MAX];
	char		*buf;
	size_t		len;
	size_t		i;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((i = nextline_in_temp(temp, fd)) > 0)
	{
		line_in_temp(temp, line, fd, i);
		return (1);
	}
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = 0;
		temp[fd] = ft_strjoin(temp[fd], buf);
		free(buf);
		if ((i = nextline_in_temp(temp, fd)) > 0)
		{
			line_in_temp(temp, line, fd, i);
			return (1);
		}
	}
	return (0);
}

#include <fcntl.h>

int     main(void)
{
    char    *line;
    int     fd;
	
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
        printf("main : %s\n", line);
    close(fd);
    return (0);
}