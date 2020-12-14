/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:01:39 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/15 00:44:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_free(void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

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

char			*ft_strdup(char *s)
{
	char *ptr;
	int i;

	if (!s)
		return NULL;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return NULL;
	ptr[ft_strlen(s)] = '\0';
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*temp;
	int			len1;
	int			len2;
	int			i;
	int			j;

	if (!s1 || !s2)
		return NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return NULL;
	temp[len1 + len2] = '\0';
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i + j] = s2[j];
		j++;
	}
	return (temp);
}

void			build_room(char **room, char *s)
{
	char		*temp;

	if (*room)
	{
		temp = ft_strjoin(*room, s);
		ft_free((void **)room);
		if (!temp)
			return ;
		*room = ft_strdup(temp);
		ft_free((void *)&temp);
		if (!*room)
			return ;
	}
	else
		*room = ft_strdup(s);
}

int				get_next_line(char **line)
{
	static char	*room;
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	while ((byte = read(0, buf, BUFFER_SIZE)))
	{
		if (byte == -1)
			return (-1);
		buf[byte] = '\0';
		if (buf[0] == '\n')
			break ;
		build_room(&room, buf);
	}
	if (!room || byte == 0)
	{
		*line = ft_strdup("");
		return (byte);
	}
	if (buf[0] == '\n' && room)
		*line = ft_strdup(room);
	ft_free((void *)&room);
	return (1);
}
