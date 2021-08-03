/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:35:16 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/03 23:01:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX 4096
# define BUFFER_SIZE 1024

char		*add_room(char *room, char *buf);
char		*add_line(char **line, char *room);
int			is_continue(int byte, char **line, char *room);
int			get_next_line(int fd, char **line);

#endif
