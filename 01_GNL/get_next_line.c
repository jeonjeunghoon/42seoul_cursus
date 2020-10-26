/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:22:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/26 16:17:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int				get_next_line(int fd, char **line)
{
	size_t		res;
	size_t		i;
	size_t		j;
	static char	*temp;
	char		s[BUFFER_SIZE + 1];

	res = 1;
	i = -1;
	j = -1;
	while ((res = read(fd, s, BUFFER_SIZE)) > 0)
	{
		while (s[i] != '\n' && i < BUFFER_SIZE)
		{
			if (s[i] == '\n')
			{
				s[i] = 0;
				while (s[++j])
					temp[j] = s[j];
				temp[j] = 0;
				*line = ft_strdup(temp);
				break ;
			}
			i++;
		}
		res = 1;
	}
	return (res);
}


int	main(void)
{
	char	*line;
	int		fd;
	int		res;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("\n%d\n", i++);
		printf("fd : %d\n", fd);
		printf("res : %d\n", res);
		printf("line : %s\n", line++);
	}
	close(fd);
	return (0);
}
