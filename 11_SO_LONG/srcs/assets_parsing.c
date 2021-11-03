/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/04 00:57:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_surrounded(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_elements(t_map *map_val, char *map)
{
	int	i;

	if (map[0] != '1' || map[map_val->x - 1] != '1')
		return (ERROR);
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			map_val->player++;
		else if (map[i] == 'C')
			map_val->collectible++;
		else if (map[i] == 'E')
			map_val->exit++;
		else if (map[i] != '0' && map[i] != '1')
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	if (check_surrounded(game->map->map[0]) == ERROR || \
		check_surrounded(game->map->map[game->map->y - 1]))
			return (ERROR);
	game->map->x = ft_strlen(game->map->map[0]);
	while (game->map->map[i])
	{
		if (game->map->x != ft_strlen(game->map->map[i]))
		{
			return (ERROR);
		}
		if (check_elements(game->map, game->map->map[i]) == ERROR)
			return (ERROR);
		i++;
	}
	if (game->map->y < 2 || game->map->player == 0 || \
		game->map->exit == 0 || game->map->collectible == 0)
		return (ERROR);
	return (0);
}

int	make_buf(t_game *game, char *map_file, int fd)
{
	int		reading;
	char	*buf;
	t_node	*new_front;

	reading = fd;
	while (reading != 0)
	{
		reading = get_next_line(fd, &buf);
		new_front = (t_node *)malloc(sizeof(t_node));
		if (new_front == NULL)
			return (ERROR);
		// new_front->next = NULL; // 최대의 미스테리 이 부분에서 NULL값을 할당하면 buf의 값이 잘리고 (비정상 작동: 바로 아래의 new_front->next = NULL 코드를 지워야함)
		game->map->front->buf_map = ft_strdup(buf);
		new_front->next = NULL; // 이 부분에서 할당하면 buf의 값이 안전할까 ...... (정상 작동: 바로 위의 new_front->next = NULL 코드를 지워야함)
		game->map->front->next = new_front;
		game->map->front = new_front;
		game->map->y++;
	}
	free(buf);
	return (0);
}

int	make_map(t_game *game, char *map_file, int fd)
{
	t_node	*del;
	int		i;

	make_buf(game, map_file, fd);
	game->map->map = (char **)malloc(sizeof(char *) * (game->map->y + 1));
	if (game->map->map == NULL)
		return (ERROR);
	game->map->map[game->map->y] = NULL;
	i = 0;
	while (game->map->rear->next != NULL)
	{
		game->map->map[i] = ft_strdup(game->map->rear->buf_map);
		del = game->map->rear;
		game->map->rear = game->map->rear->next;
		free(del->buf_map);
		free(del);
		del = NULL;
		i++;
	}
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
	if (make_map(game, map_file, fd) == ERROR)
		return (ERROR);
	close(fd);
	if (check_map(game) == ERROR)
		return (ERROR);
	return (0);
}
