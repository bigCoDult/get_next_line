#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_etc
{
	ssize_t		read_return;
	char		*buffer;
	char		*single_line;
	char		*before_line;
	size_t		index_1;
	size_t		index_2;
	size_t		index_3;
	bool		is_there_newline;
}	t_etc;

char	*get_next_line_bonus(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_memmove(char *dest, char *src, size_t count);

#endif /* GET_NEXT_LINE_BONUS_H */