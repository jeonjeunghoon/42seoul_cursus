#include <stdio.h>
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2);

int		cmp(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

int 	main(void)
{
	char s1[10] = "012345";

	printf("s1 < s2\n");
	printf("ft_strcmp = %2d\n", ft_strcmp(s1, "012349"));
	printf("      cmp = %2d\n",       cmp(s1, "012349"));
	printf("C__strcmp = %2d\n\n",  strcmp(s1, "012349"));

	printf("s1 == s2\n");
	printf("ft_strcmp = %2d\n", ft_strcmp(s1, "012345"));
	printf("      cmp = %2d\n",     cmp(s1, "012345"));
	printf("C__strcmp = %2d\n\n",  strcmp(s1, "012345"));

	printf("s1 > s2\n");
	printf("ft_strcmp = %2d\n", ft_strcmp(s1, "012340"));
	printf("      cmp = %2d\n",     cmp(s1, "012340"));
	printf("C__strcmp = %2d\n",    strcmp(s1, "012340"));
	return (0);
}
