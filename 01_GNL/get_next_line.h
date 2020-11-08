/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:55:39 by jeunjeon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/02 22:04:58 by jeunjeon         ###   ########.fr       */
=======
/*   Updated: 2020/10/31 14:56:51 by jeunjeon         ###   ########.fr       */
>>>>>>> 6e5a1e21fc1aa2f516e725bb4b6fdb21ec9e280a
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX 4096
# define BUFFER_SIZE 10

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
