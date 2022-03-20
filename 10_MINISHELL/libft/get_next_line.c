/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/11 01:26:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	set_line(char **line, char **room)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*room)[i] != '\0' && (*room)[i] != '\n')
		i++;
	if (i < ft_strlen(*room))
	{
		*line = ft_substr(*room, 0, i);
		temp = ft_substr(*room, i + 1, ft_strlen(*room));
		free(*room);
		*room = ft_strdup(temp);
		free(temp);
	}
}

int	is_continue(int byte, char **line, char **room)
{
	if (byte == 0)
	{
		if (*room == NULL)
			*line = ft_strdup("");
		else
		{
			*line = ft_strdup(*room);
			ft_free(room);
		}
		return (FALSE);
	}
	else
	{
		set_line(line, room);
		return (TRUE);
	}
}

void	add_room(char **room, char *buf)
{
	char	*temp;

	if (*room == NULL)
		*room = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*room, buf);
		free(*room);
		*room = ft_strdup(temp);
		free(temp);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (line == NULL)
		return (ERROR);
	byte = 1;
	while (byte)
	{
		byte = read(fd, buf, 1);
		if (byte < 0)
			return (ERROR);
		buf[byte] = '\0';
		add_room(&(room[fd]), buf);
		if (ft_strchr(room[fd], '\n') != NULL)
			break ;
	}
	if (is_continue(byte, line, &(room[fd])) == TRUE)
		return (TRUE);
	return (SUCCESS);
}
