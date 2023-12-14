#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_clean(char *raw);
int		ft_strlenn(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_n(char *s, int c);
int		strlen_trunk(char *s);
char	*get_next_line(int fd);

#endif