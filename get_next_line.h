/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:05:01 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/21 21:05:11 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
	size_t	i_buf;
	size_t	i_repeat;
}	t_etc;

char	*get_next_line(int fd);
void	initialize_etc(t_etc *etc);
void	free_etc(t_etc *etc);
void	check_newline(t_etc *etc);
size_t	process_buffer(t_etc *etc, int fd);
char	*allocate_tmp_line(t_etc *etc);
char	*join_lines(t_etc *etc);
char	*ft_join_till_c(char *s1, char *s2, char c);
size_t	ft_strlen(char *s);

#endif /* GET_NEXT_LINE_H */
