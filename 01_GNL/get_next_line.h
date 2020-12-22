/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:35:16 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/22 13:08:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX 4096

int			ft_strlen(char *s);
int			ft_strchr(char *s, char c);
char		*ft_strdup(char *s);
char		*ft_substr(char *s, int begin, int end);
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);

#endif
