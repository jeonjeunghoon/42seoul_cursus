#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(const char *dst, const char *src);

int		main(void)
{
	char *dst = (char *)malloc(sizeof(char) * 11);
	char src[10] = "0123456789";

	dst[0] = 'A';
	printf("ft_strcpy = %s\n", ft_strcpy(dst, NULL));
	printf("@@\n");
	printf("ft_strcpy = %s\n", dst);

	char *dst2 = (char *)malloc(sizeof(char) * 11);
	dst2[0] = 'A';
	printf("C__strcpy = %s\n", strcpy(dst2, NULL));
	printf("!!");
	printf("C__strcpy = %s\n", dst2);
	return (0);
}