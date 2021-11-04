/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_parsing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:45:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

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
		if (check_elements(game, game->map, game->map->map[i], i) == ERROR)
			return (ERROR);
		i++;
	}
	if (game->map->y < 2 || game->map->player == 0 || \
		game->map->exit == 0 || game->map->collectible == 0)
		return (ERROR);
	return (0);
}

int	make_map(t_game *game)
{
	t_node	*del;
	int		i;

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

void	make_buf(t_game *game, char *map_file, int fd)
{
	int		reading;
	char	*buf;
	t_node	*new_front;

	reading = fd;
	while (reading != 0)
	{
		reading = get_next_line(fd, &buf);
		new_front = (t_node *)malloc(sizeof(t_node));
		game->map->front->buf_map = ft_strdup(buf);
		new_front->next = NULL;
		game->map->front->next = new_front;
		game->map->front = new_front;
		game->map->y++;
	}
	free(buf);
}

int	assets_parsing(t_game *game, char *argv)
{
	int		fd;
	char	*map_file;

	map_file = ft_strjoin("map/", argv);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	make_buf(game, map_file, fd);
	close(fd);
	if (make_map(game) == ERROR)
		return (ERROR);
	if (check_map(game) == ERROR)
		return (ERROR);
	return (0);
}
