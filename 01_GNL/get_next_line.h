/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:02:40 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/28 11:16:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 4

char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *dest, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);

#endif
