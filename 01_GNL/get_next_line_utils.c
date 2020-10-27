/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:06:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/27 21:21:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *dest, size_t len)
{
	while (len--)
	{
		*(unsigned char *)dest = 0;
		dest++;
	}
}

size_t		ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (((unsigned char *)s)[res])
		res++;
	return (res);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dest_len;
	size_t result;

	dest_len = ft_strlen(dest);
	result = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (dest_len >= size)
		result += size;
	else
	{
		while (src[i] && (i < size - dest_len - 1))
			dest[j++] = src[i++];
		result += dest_len;
		dest[j] = '\0';
	}
	return (result);
}

size_t		ft_strlcpy(char *restrict d, const char *restrict s, size_t n)
{
	size_t	i;

	if (!d || !s)
		return (0);
	if (n)
	{
		i = 0;
		while (i < n - 1 && s[i])
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (ft_strlen(s));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	else
	{
		ft_strlcpy(ptr, (char *)s1, len1 + 1);
		ft_strlcat(ptr, (char *)s2, len1 + len2 + 1);
	}
	return (ptr);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))) || !s1)
		return (0);
	ptr[len] = 0;
	i = 0;
	while (len)
	{
		*(ptr + i++) = *s1++;
		len--;
	}
	return (ptr);
}

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = (unsigned char *)src;
	if (dest <= src)
	{
		while (len--)
			*(d++) = *(s++);
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dest);
}
