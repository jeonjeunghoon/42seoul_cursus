/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/03 23:02:30 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	size_t	i;

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

void	byte_is_zero(char **line, char *room)
{
	if (!room)
		*line = ft_strdup("");
	else
		*line = ft_strdup(room);
	free((room));
}

int	get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (!line)
		return (-1);
	byte = read(fd, buf, 1);
	printf("byte = %d\nbuf = %s\n", byte, buf);
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
	if (byte == 0)
	{
		byte_is_zero(line, room[fd]);
		return (0);
	}
	room[fd] = add_line(line, room[fd]);
	return (1);
}
