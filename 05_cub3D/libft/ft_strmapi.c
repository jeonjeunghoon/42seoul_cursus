/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 14:50:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:12:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (!s)
		return (0);
	if (!(p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = -1;
	while (s[++i])
		p[i] = s[i];
	p[i] = 0;
	i = -1;
	while (p[++i])
		p[i] = f(i, p[i]);
	return (p);
}
