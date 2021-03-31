/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/03/31 21:02:56 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_free(void **p)
{
	if (!p || !*p)
		return ;
	else
	{
		free(*p);
		*p = NULL;
	}
}

char			*add_room(char *room, char *buf)
{
	char		*temp;

	if (room)
	{
		temp = ft_strjoin(room, buf);
		ft_free((void *)&room);
		room = ft_strdup(temp);
		ft_free((void *)&temp);
	}
	else
	{
		room = ft_strdup(buf);
	}
	return (room);
}

char			*add_line(char **line, char *room)
{
	char		*temp;
	int			i;

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
		ft_free((void *)&room);
		room = ft_strdup(temp);
		ft_free((void *)&temp);
	}
	return (room);
}

int				get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (!line)
		return (-1);
	while ((byte = read(fd, buf, 1)))
	{
		if (byte < 0)
			return (-1);
		buf[byte] = '\0';
		room[fd] = add_room(room[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (byte == 0)
	{
		if (!room[fd])
			*line = ft_strdup("");
		else
			*line = ft_strdup(room[fd]);
		ft_free((void *)&(room[fd]));
		return (0);
	}
	else
	{
		room[fd] = add_line(line, room[fd]);
		ft_free((void *)&(room[fd]));
		return (1);
	}
}