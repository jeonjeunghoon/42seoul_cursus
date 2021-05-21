#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct			list_s
{
	int					*data;
	struct	list_t		*next;
}						list_t;

#endif