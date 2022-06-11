

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strnl(char *s);
char	*get_read(int fd, char *s);
char	*get_next_line(int fd);
char	*stringdup(char *s);
char	*get_str(char *s);
size_t	ft_strlen_gnl(char *s);
char	*ft_free_gnl(char **s);

#endif
