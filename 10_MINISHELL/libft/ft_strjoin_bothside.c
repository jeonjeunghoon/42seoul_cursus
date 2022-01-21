/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bothside.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:35:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/21 15:38:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_bothside(const char *s1, const char *s2, const char *s3)
{
	char	*buff;
	char	*res;

	buff = ft_strjoin(s1, s2);
	res = ft_strjoin(buff, s3);
	free(buff);
	return (res);
}
