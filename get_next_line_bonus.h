/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:26:30 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/18 09:26:30 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_etc
{
	ssize_t		read_return;
	size_t		buffer_size;
	char		*buffer;
	char		*single_line;
	char		*before_line;
	size_t		index_1;
	size_t		index_2;
	size_t		index_3;
	bool		is_there_newline;
}	t_etc;
char	*get_next_line_bonus(int fd);
char	*set_single_line(t_etc *etc, char *static_line);

#endif /* GET_NEXT_LINE_BONUS_H */