#include "../inc/minishell.h"

/*

https://github.com/paulahemsi/minishell/
여기서 참고하셈

*/

static char	*get_current_working_directory(void)
{
	char	*buffer;
	char	*cwd;

	buffer = NULL;
	cwd = getcwd(buffer, 0);
	return (cwd);
}

void	ft_pwd(void)
{
	char	*cwd;

	cwd = get_current_working_directory();
	if (cwd)
		printf("%s\n", cwd);
	else
		error_msg("pwd", strerror(errno));
	free(cwd);
}
