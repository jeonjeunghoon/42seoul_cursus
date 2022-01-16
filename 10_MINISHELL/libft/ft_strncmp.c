/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:03:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/16 23:50:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	while (len--)
	{
		if ((*(unsigned char *)s1 != *(unsigned char *)s2) || \
		(!*(unsigned char *)s1 || !*(unsigned char *)s2))
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
