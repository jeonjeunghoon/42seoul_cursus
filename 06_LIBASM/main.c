/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:47:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/21 02:47:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libasm.h"

void		test_str(void)
{
	char	*ptr;
	char	*ft_ptr;
	char	*ptr1;
	char	*ft_ptr1;

	printf("\n\n#################\nTEST STR FUNCTION\n#################\n");
	printf("\nTEST STRLEN\n");
	printf("C__strlen = %zu\n",    strlen("0123456789"));
	printf("ft_strlen = %zu\n", ft_strlen("0123456789"));
	
	printf("\nTEST STRCPY\n");
	ptr = malloc(sizeof(char) * (strlen("0123456789") + 1));
	ft_ptr = malloc(sizeof(char) * (ft_strlen("0123456789") + 1));
	ptr = strcpy(ptr, "0123456789");
	ft_ptr = ft_strcpy(ft_ptr, "0123456789");
	printf("C__strcpy = %s\n", ptr);
	printf("ft_strcpy = %s\n", ft_ptr);

	printf("\nTEST STRCMP\n");
	printf("C__strcmp = %d\n",    strcmp("0123456789", "0123456789"));
	printf("ft_strcmp = %d\n", ft_strcmp("0123456789", "0123456789"));
	
	printf("\nTEST_STRDUP\n");
	ptr1 = strdup("0123456789");
	ft_ptr1 = ft_strdup("0123456789");
	printf("C__strdup = %s\n", ptr1);
	printf("ft_strdup = %s\n\n", ft_ptr1);
}

int			main(void)
{
	char	buf[BUFFER_SIZE];
	char	ft_buf[BUFFER_SIZE];
	int		fd;
	int		ft_fd;

	test_str();
	printf("#################\n TEST WRITE READ\n#################\n");
	printf("\nTEST WRITE\n");
	ft_write(1, "C__write = ", 11);
	fd = write(1, "0123456789\n", 11);
	printf("C__write fd = %d\n", fd);
	if (errno)
		printf("C__write errno = %d\n", errno);
	
	ft_write(1, "ft_write = ", 11);
	fd = ft_write(1, "0123456789\n", 11);
	printf("ft_write fd = %d\n", fd);
	if (errno)
		printf("ft_write errno = %d\n", errno);

	printf("\nTEST READ\n");
	fd = open("text/test.txt", O_RDONLY);
	printf("C__read fd = %zd\n", read(fd, buf, 10));
	buf[10] = '\0';
	printf("C__read = %s\n", buf);
	if (errno)
		printf("C__read errno = %d\n", errno);

	ft_fd = open("text/ft_test.txt", O_RDONLY);
	printf("ft_read fd = %zd\n", ft_read(ft_fd, ft_buf, 10));
	ft_buf[10] = '\0';
	printf("ft_read = %s\n", ft_buf);
	if (errno)
		printf("ft_read errno = %d\n", errno);
	printf("\n\n");
	return (0);
}
