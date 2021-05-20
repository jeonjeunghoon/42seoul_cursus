#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(const char *s1);

char *dup(const char *s1)
{
	char *ptr = malloc(sizeof(char) * (strlen(s1) + 1));
	int len = strlen(s1);

	ptr = malloc(sizeof(char) * (len + 1));
	strcpy(ptr, s1);
	return (ptr);
}

int main(void)
{
	char *ptr1 = NULL;
	char *ptr2 = NULL;
	char *ptr3 = NULL;

	printf("ft_strdup = %s", ft_strdup("Hello, World!\n"));
	ptr1 = ft_strdup("World, Hello!\n");
	printf("ft_strdup = %s\n", ptr1);

	printf("      dup = %s",       dup("Hello, World!\n"));
	ptr3 = dup("World, Hello!\n");
	printf("      dup = %s\n", ptr3);
	
	printf("C__strdup = %s",    strdup("Hello, World!\n"));
	ptr2 = strdup("World, Hello!\n");
	printf("C__strdup = %s", ptr2);


	
	return (0);
}