/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:47 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/21 17:41:12 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void		check_newline(t_etc *etc);
void		free_etc(t_etc *etc);
static char	*initialize_etc(t_etc *etc);

char	*get_next_line_bonus(int fd)
{
	static t_etc	*etc = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (etc == NULL)
	{
		etc = (t_etc *)malloc(sizeof(t_etc));
		if (etc == NULL || initialize_etc(etc) == NULL)
		{
			free(etc);
			return (NULL);
		}
	}
	etc->buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buf == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	process_buffer(etc, fd);
	free(etc->buf);
	etc->buf = NULL;
	while (etc->st_s[etc->i_tmp_s] != '\0' && etc->st_s[etc->i_tmp_s++] != '\n')
		;
	return (allocate_tmp_line(etc));
}

static char	*initialize_etc(t_etc *etc)
{
	etc->st_s = (char *)malloc(sizeof(char));
	if (etc->st_s == NULL)
	{
		return (NULL);
	}
	etc->st_s[0] = '\0';
	etc->is_there_newline = false;
	etc->tmp_s = NULL;
	etc->i_st_s = 0;
	etc->i_tmp_s = 0;
	etc->i_buf = 0;
	etc->i_repeat = 0;
	return (etc->st_s);
}

void	free_etc(t_etc *etc)
{
	if (etc->st_s != NULL)
		free(etc->st_s);
	if (etc->buf != NULL)
		free(etc->buf);
	if (etc->tmp_s != NULL)
		free(etc->tmp_s);
	free(etc);
}

void	check_newline(t_etc *etc)
{
	etc->i_buf = 0;
	while (etc->buf[etc->i_buf] != '\0')
	{
		if (etc->buf[etc->i_buf] == '\n')
		{
			etc->is_there_newline = true;
			break ;
		}
		etc->i_buf++;
	}
}
