#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_etc
{
	bool		is_there_newline;
	ssize_t		read_return;
	char		*buffer;
	char 		*tmp_line;
	size_t		i_tmp_line;
	size_t		i_buffer;
	size_t		i_repeat;
}	t_etc;

char	*get_next_line_bonus(int fd);
size_t	ft_strlen(char *s);
char	*ft_join_till_c(char *s_front, char *s_back, char c);
// char	*ft_strjoin(char *s_front, char *s_back);

#endif /* GET_NEXT_LINE_BONUS_H */