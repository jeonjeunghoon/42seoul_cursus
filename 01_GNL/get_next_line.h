#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FD_MAX 5000

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dest, char *src, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
