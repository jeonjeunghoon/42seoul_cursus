/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:32:22 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:42:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int					g_count;
int					g_arglen;
int					g_error;

size_t				ft_strlen(const char *s);
long long			ft_atoi(const char *s, const char f);
char				*ft_itoa(long long n, const char f, char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(long long n, int fd, const char f, int minus);

#endif
