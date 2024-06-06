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


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_etc
{
	ssize_t		read_return;
	size_t		buffer_size;
	char		*buffer;
	char		*single_line;
	ssize_t		i;


}	t_etc;
char	*get_next_line_bonus(int fd);
char	*set_single_line(t_etc *etc);

#endif /* GET_NEXT_LINE_BONUS_H */