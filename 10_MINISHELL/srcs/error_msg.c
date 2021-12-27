#include "../inc/minishell.h"

void	error_msg(char *input, char *error_msg)
{
	printf("%s: %s\n", input, error_msg);
}
