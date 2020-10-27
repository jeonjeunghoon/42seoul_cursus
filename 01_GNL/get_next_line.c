/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/27 23:28:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

size_t			nextline_in_temp(char **temp, int fd)
{
	size_t		i;

	if (!(temp[fd]))
		return (0);
	i = 0;
	while (temp[fd][i])
	{
		i++;
		if (temp[fd][i] == '\n')
			return (i);
	}
	// if (!(temp[fd][i]) && temp[fd][i - 1])
	// 	return (1);
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
	while (temp[fd][i] == '\n' && temp[fd][i])
		i++;
	if (!(temp[fd][i]))
		return ;
	head = &(temp[fd][i]);
	temp[fd] = ft_strjoin(temp[fd], head);
}

void			make_line(char **temp, char **line, char fd, size_t i)
{
	temp[fd][i] = 0;
	*line = ft_strdup(temp[fd]);
}

int				get_next_line(int fd, char **line)
{
	static char	*temp[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	size_t		len;
	size_t		i;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((i = nextline_in_temp(temp, fd)) > 0)
	{
		make_line(temp, line, fd, i);
		move_temp(temp, fd, i);
		return (1);	
	}
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = 0;
		temp[fd] = ft_strjoin(temp[fd], buf);
		printf("temp : %s\n", temp[fd]);
		if ((i = nextline_in_temp(temp, fd)) > 0)
		{
			printf("121214234213123");
			make_line(temp, line, fd, i);
			move_temp(temp, fd, i);
			return (1);
		}
		else
			*line = ft_strjoin(*line, temp[fd]);
	}
	return (0);
}

int     main(void)
{
    char    *line;
    int     fd;
	int		r;
    fd = open("test.txt", O_RDONLY);
    while ((r = get_next_line(fd, &line)) > 0)
        printf("\nmain : %s\n", line);
    close(fd);
    return (0);
}