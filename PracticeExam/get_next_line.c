/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:01:39 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/14 23:10:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *s)
{
	int			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strdup(char *room, char *s)
{
	int i;

	i = 0;
	if (!s)
		return NULL;
	if (!(room = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return NULL;
	room[ft_strlen(s)] = '\0';
	while (s[i])
	{
		room[i] = s[i];
		i++;
	}
	return (room);
}

char			*ft_strjoin(char *room, char *s)
{
	char		*temp;
	int			len1;
	int			i;

	if (!room || !s)
		return NULL;
	len1 = ft_strlen(room);
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + 2))))
	{
		free(room);
		room = NULL;
		return NULL;
	}
	temp[len1 + 1] = '\0';
	i = 0;
	while (room[i])
	{
		temp[i] = room[i];
		i++;
	}
	temp[i] = s[0];
	return (temp);
}

void			build_room(char **room, char *s)
{
	char		*temp;

	if (*room)
	{
		temp = ft_strjoin(*room, s);
		free(*room);
		*room = ft_strdup(*room, temp);
		free(temp);
	}
	else
		*room = ft_strdup(*room, s);
}

void			nextline_in(char **line, char **room, char c, int byte)
{
	if (c == '\n' && *room)
	{
		*line = ft_strdup(*line, *room);
		free(*room);
		*room = 0;
	}
	else if (c == '\n' && !(*room))
	{
		*line = ft_strdup(*line, "");
		free(*room);
		*room = 0;
	}
	else if (byte == 0)
	{
		*line = *room;
		*room = 0;
	}
}

int				get_next_line(char **line)
{
	static char	*room;
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	while ((byte = read(1, buf, BUFFER_SIZE)))
	{
		if (byte == -1)
			return (-1);
		buf[byte] = '\0';
		if (buf[0] == '\n')
			break ;
		build_room(&room, buf);
	}
	if (byte <= 0 && !room)
	{
		*line = ft_strdup(*line, "");
		return (byte);
	}
	nextline_in(line, &room, buf[0], byte);
	if (byte <= 0 && !room)
		return (byte);
	return (1);
}
