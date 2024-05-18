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
# include <unistd.h>
# include <stdlib.h>

typedef struct s_etc
{
	int						n;
	unsigned int			u;
	char					*string;
	long long unsigned int	*ads;
}	t_etc;
char	*get_next_line_bonus(int fd);

#endif /* GET_NEXT_LINE_BONUS_H */