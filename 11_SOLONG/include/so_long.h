/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/10/30 18:04:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mms/mlx.h"
# define OPEN_MAX 4896
# define BUFFER_SIZE 1

/* GNL */
char	*add_room(char *room, char *buf);
char	*add_line(char **line, char *room);
int		is_continue(int fd, int byte, char **line, char **room);
int		get_next_line(int fd, char **line);

#endif
