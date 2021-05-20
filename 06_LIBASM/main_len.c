#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

int		main(void)
{
	char s[10] = "0123456789";

	printf("ft_strlen = %zu\n", ft_strlen(s));
	printf("C__strlen = %lu\n", strlen(s));
	return (0);
}