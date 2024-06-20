/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:27:03 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/20 19:27:06 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_etc(t_etc *etc)
{
	if (etc->st_s != NULL)
		free(etc->st_s);
	if (etc->buf != NULL)
		free(etc->buf);
	free(etc);
}

void	check_newline(t_etc *etc)
{
	etc->i_buffer = 0;
	while (etc->buf[etc->i_buffer] != '\0')
	{
		if (etc->buf[etc->i_buffer] == '\n')
		{
			etc->is_there_newline = true;
			break ;
		}
		etc->i_buffer++;
	}
}

static char	*initialize_etc(t_etc **etc)
{
	*etc = (t_etc *)malloc(sizeof(t_etc));
	if (*etc == NULL)
		return (NULL);
	(*etc)->st_s = (char *)malloc(sizeof(char));
	if ((*etc)->st_s == NULL)
	{
		free(*etc);
		return (NULL);
	}
	(*etc)->st_s[0] = '\0';
	(*etc)->is_there_newline = false;
	(*etc)->i_st_s = 0;
	(*etc)->i_tmp_s = 0;
	(*etc)->i_buffer = 0;
	(*etc)->i_repeat = 0;
	return ((*etc)->st_s);
}

char	*get_next_line_bonus(int fd)
{
	static t_etc	*etc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (etc == NULL && initialize_etc(&etc) == NULL)
		return (NULL);
	etc->buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buf == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	process_buffer(etc, fd);
	free(etc->buf);
	etc->buf = NULL;
	while (etc->st_s[etc->i_tmp_s] != '\0' && etc->st_s[etc->i_tmp_s] != '\n')
		etc->i_tmp_s++;
	if (etc->st_s[etc->i_tmp_s] == '\n')
		etc->i_tmp_s++;
	return (allocate_tmp_line(etc));
}
