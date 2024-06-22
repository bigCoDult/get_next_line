/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:04:48 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/22 18:10:11 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_etc	*etc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (etc == NULL)
	{
		etc = (t_etc *)malloc(1 * sizeof(t_etc));
		if (etc == NULL)
			return (NULL);
		init_etc(etc);
	}
	etc->buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buf == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	if (set_buf(etc, fd) == 0 && etc->single_s[etc->i_single_s] == '\0')
		return (NULL);
	free(etc->buf);
	etc->buf = NULL;
	while (etc->single_s[etc->i_tmp_s] != '\0' && etc->single_s[etc->i_tmp_s++] != '\n')
		;
	return (set_tmp_s(etc));
}

void	init_etc(t_etc *etc)
{
	etc->single_s = (char *)malloc(sizeof(char));
	if (etc->single_s == NULL)
		return ;
	etc->single_s[0] = '\0';
	etc->is_there_newline = false;
	etc->tmp_s = NULL;
	etc->i_single_s = 0;
	etc->i_tmp_s = 0;
	etc->i_buf = 0;
	// etc->i_repeat = 0;
	return ;
}

void	free_etc(t_etc *etc)
{
	if (etc->single_s != NULL)
		free(etc->single_s);
	if (etc->buf != NULL)
		free(etc->buf);
	if (etc->tmp_s != NULL)
		free(etc->tmp_s);
	free(etc);
}

void	is_newline(t_etc *etc)
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
