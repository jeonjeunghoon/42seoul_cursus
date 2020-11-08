/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:51 by jeunjeon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/02 22:04:59 by jeunjeon         ###   ########.fr       */
=======
/*   Updated: 2020/10/31 14:13:44 by jeunjeon         ###   ########.fr       */
>>>>>>> 6e5a1e21fc1aa2f516e725bb4b6fdb21ec9e280a
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!(s[i]))
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

char			*nextline_in_room(char *room, char **line, int byte)
{
	int			idx;
	char		*temp;

	idx = 0;
	while (room[idx])
	{
		if (room[idx] == '\n')
			break ;
		idx++;
	}
	if ((size_t)idx < ft_strlen(room))
	{
		*line = ft_substr(room, 0, idx);
		temp = ft_substr(room, idx + 1, ft_strlen(room));
		free(room);
		room = ft_strdup(temp);
		free(temp);
	}
	else if (byte == 0)
	{
		*line = room;
		room = 0;
	}
	return (room);
}

char			*join(char *room, char *buf)
{
	char		*temp;

	if (room)
	{
		temp = ft_strjoin(room, buf);
		free(room);
		room = ft_strdup(temp);
		free(temp);
	}
	else
		room = ft_strdup(buf);
	return (room);
}

int				get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((byte = read(fd, buf, BUFFER_SIZE)))
	{
		if (byte == -1)
			return (-1);
		buf[byte] = 0;
		room[fd] = join(room[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (byte <= 0 && !(room[fd]))
	{
		*line = ft_strdup("");
		return (byte);
	}
	room[fd] = nextline_in_room(room[fd], line, byte);
	if (byte <= 0 && !(room[fd]))
		return (byte);
	return (1);
}
<<<<<<< HEAD

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char    *line;
    int     fd;
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
        printf("%s\n", line);
    close(fd);
    return (0);
}
=======
>>>>>>> 6e5a1e21fc1aa2f516e725bb4b6fdb21ec9e280a
