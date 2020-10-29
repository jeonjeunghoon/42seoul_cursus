/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/29 11:23:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t			nextline_in_temp(char **temp, int fd)
{
	size_t		idx;

	if (!(temp[fd]))
		return (0);
	idx = 0;
	while (temp[fd][idx])
	{
		// printf("%s\n", temp[fd]);
		if (temp[fd][idx] == '\n' && idx)
		{
			// printf("10 %c\n", temp[fd][idx]);
			// printf("10\n");
			return (idx);
		}
		else if (temp[fd][idx] == '\n' && idx == 0)
		{
			// printf("11 + 1 : %c\n", temp[fd][idx + 1]);
			// printf("11 : %c\n", temp[fd][idx]);
			return (1);
		}
		// printf("12\n");
		idx++;
	}
	// printf("12\n");
	return (0);
}

void			move_temp(char **temp, int fd, size_t idx)
{
	char		*head;

	if (!(temp[fd][++idx]))
	{
		free(temp[fd]);
		temp[fd] = 0;
		return ;
	}
	head = &(temp[fd][idx]);
	temp[fd] = ft_strdup(head);
}

void			line_in_temp(char **temp, char **line, int fd, size_t idx)
{
	temp[fd][idx] = 0;
	*line = ft_strdup(temp[fd]);
	move_temp(temp, fd, idx);
}

int				get_next_line(int fd, char **line)
{
	static char	*temp[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	size_t		len;
	size_t		idx;
	static int	a = 0, b = 0;

	// if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	// 		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((idx = nextline_in_temp(temp, fd)) > 0)
	{
		line_in_temp(temp, line, fd, idx);
		return (1);
	}
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = 0;
		temp[fd] = ft_strjoin(temp[fd], buf);
		// free(buf);
		if ((idx = nextline_in_temp(temp, fd)) > 0)
		{
			line_in_temp(temp, line, fd, idx);
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

/* 해결해야할 문제 : 마지막 문자열 예외처리, 중간에 개행문자 나올 때 출력, */