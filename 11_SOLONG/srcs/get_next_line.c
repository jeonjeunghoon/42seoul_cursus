/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/10/30 18:01:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*add_room(char *room, char *buf)
{
	char	*temp;

	if (room)
	{
		temp = ft_strjoin(room, buf);
		free(room);
		room = ft_strdup(temp);
		free(temp);
	}
	else
	{
		room = ft_strdup(buf);
	}
	return (room);
}

char	*add_line(char **line, char *room)
{
	char	*temp;
	int		i;

	i = 0;
	while (room[i])
	{
		if (room[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(room))
	{
		*line = ft_substr(room, 0, i);
		temp = ft_substr(room, i + 1, ft_strlen(room));
		free(room);
		room = ft_strdup(temp);
		free(temp);
	}
	return (room);
}

int	is_continue(int fd, int byte, char **line, char **room)
{
	if (byte == 0)
	{
		if (!room[fd])
			*line = ft_strdup("");
		else
			*line = ft_strdup(room[fd]);
		free((room[fd]));
		return (0);
	}
	else
	{
		room[fd] = add_line(line, room[fd]);
		free((room[fd]));
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (!line)
		return (-1);
	byte = read(fd, buf, 1);
	while (byte)
	{
		if (byte < 0)
			return (-1);
		buf[byte] = '\0';
		room[fd] = add_room(room[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
		byte = read(fd, buf, 1);
	}
	if (is_continue(fd, byte, line, room) == 1)
		return (1);
	else
		return (0);
}
