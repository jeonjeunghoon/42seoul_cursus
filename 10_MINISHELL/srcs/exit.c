/*

https://github.com/paulahemsi/minishell/blob/main/sources/builtins/exit.c

원래 다른 함수들 더 있는데 서브젝트에 옵션 없이 작성하라 해서
$> exit
기능만 넣었음
$> exit 100 << 숫자가 옵션인지 모르겠다.

*/

#include "minishell.h"

static int	get_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	return (argc);
}

void	exit_builtin(char **argv)
{
	int	argc;

	argc = get_argc(argv);
	if (argc > 1)
	{
		error_msg("exit", "too many arguments");
		return ;
	}
	printf("exit\n");
	exit(0);
}