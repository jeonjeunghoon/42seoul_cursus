/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:19:24 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/28 13:42:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FD_MAX 5000

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dest, char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		nextline_in_temp(char **temp, int fd);
void		move_temp(char **temp, int fd, size_t i);
void		line_in_temp(char **temp, char **line, int fd, size_t i);
int			get_next_line(int fd, char **line);

#endif
