/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/27 16:26:30 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

void			**move_temp(char **temp, int fd, size_t i)
{
	char		*head;
	size_t		j;

	if (!(head = malloc(sizeof(char) * ft_strlen(temp[fd]) + 1)))
		return (0);
	if (!(temp[fd][i + 1]))
		return (0);
	j = 0;
	while (temp[fd][++i])
		head[j++] = temp[fd][i];
	i = -1;
	while (++i < j)
		temp[fd][i] = head[i];
	return (0);
}

int				line_in_temp(char *buf, char **line, char **temp, int fd)
{
	size_t		i;

	i = 0;
	while (temp[fd][i] != '\n' && temp[fd][i])
		i++;
	if (temp[fd][i] == '\n')
	{
		temp[fd][i] = 0;
		*line = ft_strdup(temp[fd]);
		move_temp(temp, fd, i);
		return (1);
	}
	return (0);
}

char			*get_line(int fd, char **line, char *buf, size_t i)
{
	static char	**temp;
	int			res;
	
	if (!(line_in_temp(buf, line, temp, fd)))
	{
		while ((res = read(fd, buf, BUFFER_SIZE)))
		{
			while (temp[fd][i] != '\n' && temp[fd][i])
				i++;
			if (temp[fd][i] == '\n')
			{
				*line = ft_strdup(temp[fd]);
				return (*line);
			}
			else
				get_line(fd, line, buf, i);
		}
	}
	return (*line);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			res;
	size_t		i;
	
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || !fd)
		return (0);
	ft_bzero(*line, ft_strlen(*line));
	i = 0;
	*line = get_line(fd, line, buf, i);
	return (0);
}

int     main(void)
{
    char    *line;
    int     fd;
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
        printf("\nmain : %s\n", line);
    close(fd);
    return (0);
}