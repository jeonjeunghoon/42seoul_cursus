#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 1

int		get_next_line(char **line, int fd);

#endif