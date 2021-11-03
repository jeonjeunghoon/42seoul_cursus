/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 18:36:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_surrounded(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_elements(t_game *game, char *buf, int x_len)
{
	int	i;

	i = 0;
	if (buf[0] != '1')
		return (ERROR);
	while (buf[i] != '\0')
	{
		if (buf[i] == 'P')
			game->map->player++;
		else if (buf[i] == 'C')
			game->map->collectible++;
		else if (buf[i] == 'E')
			game->map->exit++;
		i++;
	}
	if (x_len != i)
		return (ERROR);
	if (buf[i - 1] != '1')
		return (ERROR);
	return (0);
}

int	check_map(t_game *game, char *map_file, int fd)
{
	int		reading;
	int		x_len;
	char	*buf;

	reading = fd;
	while (reading)
	{
		if (buf != NULL)
		{
			free(buf);
			buf = NULL;
		}
		reading = get_next_line(fd, &buf);
		if (game->map->y == 0)
		{
			if (check_surrounded(buf) == ERROR)
				return (ERROR);
			x_len = ft_strlen(buf);
		}
		check_elements(game, buf, x_len);
		game->map->y++;
	}
	if (check_surrounded(buf) == ERROR || game->map->y < 2 || \
		game->map->player == 0 || game->map->exit == 0 || \
		game->map->collectible == 0) // 서브젝트 내용이 살짝 이상한데 플레이어 위치가 두 개 이상이어도 되나?
		return (ERROR);
	return (0);
}

int	make_buf_map(t_game *game, char *map_file, int fd)
{
	int		reading;
	char	*buf;
	t_node	*new_front;

	reading = fd;
	while (reading)
	{
		reading = get_next_line(fd, &buf);
		printf("%s\n\n", buf);
		game->map->front->buf_map = ft_strdup(buf);
		new_front = (t_node *)malloc(sizeof(t_node));
		if (new_front == NULL)
			return (ERROR);
		new_front->next = NULL;
		game->map->front->next = new_front;
		game->map->front = new_front;
		game->map->y++;
	}
	free(buf);
	return (0);
}

int	assets_parsing(t_game *game, char *argv)
{
	int		fd;
	char	*map_file;

	map_file = ft_strjoin("map/", argv);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	make_buf_map(game, map_file, fd);
	system("leaks so_long");
	while (1);
	// while (game->map->rear != NULL)
	// {
	// 	printf("%s\n", game->map->rear->buf_map);
	// 	game->map->rear = game->map->rear->next;
	// }
	close(fd);
	if (check_map(game, map_file, fd) == ERROR)
		return (ERROR);
	return (0);
}
