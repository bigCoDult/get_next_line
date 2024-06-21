#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_etc
{
	bool	is_there_newline;
	ssize_t	read_return;
	char	*st_s;
	char	*buf;
	char	*tmp_s;
	size_t	i_st_s;
	size_t	i_tmp_s;
	size_t	i_buffer;
	size_t	i_repeat;
}	t_etc;

char	*get_next_line_bonus(int fd);
char	*join_lines(t_etc *etc);
char	*allocate_tmp_line(t_etc *etc);
void	check_newline(t_etc *etc);
void	process_buffer(t_etc *etc, int fd);
void	free_etc(t_etc *etc);
char	*ft_join_till_c(char *s1, char *s2, char c);

#endif /* GET_NEXT_LINE_BONUS_H */
