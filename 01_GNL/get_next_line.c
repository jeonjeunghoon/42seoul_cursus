/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/29 15:31:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			move_temp(char **temp, int fd, size_t idx)
{
	char		*head;

	head = ft_strdup(temp[fd] + idx);
	free(temp[fd]);
	temp[fd] = ft_strdup(head);
	free(head);
	head = 0;
}

size_t			nextline_in_temp(char **temp, int fd, char **line, size_t len)
{
	size_t		idx;

	if (!(temp[fd]))
		return (0);
	idx = 0;
	if (temp[fd][idx] == '\n')
	{
		temp[fd][idx] = 0;
		*line = ft_strdup("");
		move_temp(temp, fd, idx + 1);
		return (1);
	}
	while (temp[fd][idx])
	{
		if (temp[fd][idx] == '\n')
		{
			temp[fd][idx] = 0;
			*line = ft_strdup(temp[fd]);
			move_temp(temp, fd, ++idx);
			return (1);
		}
		idx++;
	}
	return (0);
}

int				join_buf(char **temp, int fd, char *buf)
{
	if (!buf)
		return (0);
	if (!(temp[fd]))
		temp[fd] = ft_strdup(buf);
	else
		temp[fd] = ft_strjoin(temp[fd], buf);
	free(buf);
	return (1);
}

int				last_line(char **temp, int fd, char **line)
{
	size_t		i;

	i = 0;
	if (!(temp[fd]))
		return (0);
	*line = ft_strdup(temp[fd]);
	free(temp[fd]);
	temp[fd] = 0;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*temp[FD_MAX];
	char		*buf;
	size_t		len;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	len = 0;
	if ((nextline_in_temp(temp, fd, line, len)) > 0)
		return (1);
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = 0;
		if (!(join_buf(temp, fd, buf)) || len < 0)
			return (-1);
		if ((nextline_in_temp(temp, fd, line, len)) > 0)
			return (1);
		if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	if (last_line(temp, fd, line))
		return (1);
	return (0);
}
