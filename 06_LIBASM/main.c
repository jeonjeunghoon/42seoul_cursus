/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:47:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/21 01:32:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libasm.h"

void		test_str(void)
{
	char	*ptr;

	printf("#################\nTEST STR FUNCTION\n#################\n");
	printf("ft_strlen = %zu\n", ft_strlen("0123456789"));
	ptr = malloc(sizeof(char) * (ft_strlen("0123456789") + 1));
	ptr = ft_strcpy(ptr, "0123456789");
	printf("ft_strcpy = %s\n", ptr);
	printf("ft_strcmp = %d\n", ft_strcmp("0123456789", ptr));
	free(ptr);
	ptr = malloc(sizeof(char) * (ft_strlen("0123456789") + 1));
	ptr = ft_strdup("0123456789");
	printf("ft_strdup = %s\n\n", ptr);
}

int			main(void)
{
	char	buf[BUFFER_SIZE];
	int		fd;

	test_str();
	printf("#################\n TEST WRITE READ\n#################\n");
	ft_write(1, "ft_write = ", 11);
	fd = ft_write(1, "0123456789\n", 11);
	printf("ft_write fd = %d\n", fd);
	fd = open("text/test.txt", O_RDONLY);
	printf("ft_read fd = %zd\n", ft_read(fd, buf, 10));
	buf[10] = '\0';
	printf("ft_read = %s\n", buf);
	return (0);
}
