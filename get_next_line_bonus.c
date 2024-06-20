/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:08:42 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/20 15:08:42 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"


char	*get_next_line_bonus(int fd)
{
	static t_etc	*etc = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("fd or BUFFER_SIZE is invalid");
	if (etc == NULL)
	{
		etc = (t_etc *)malloc(1 * sizeof(t_etc));
		if (etc == NULL)
			return ("malloc etc fail");
		etc->static_line = (char *)malloc(1 * sizeof(char));
		if (etc->static_line == NULL)
		{
			free(etc);
			return ("malloc static_line fail");
		}
		etc->static_line[0] = '\0';
		etc->is_there_newline = false;
		etc->i_static_line = 0;
		etc->i_tmp_line = 0;
		etc->i_buf = 0;
		etc->i_repeat = 0;
	}
	etc->buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buf == NULL)
	{
		free(etc->static_line);
		free(etc);
		return ("malloc buffer fail");
	}
	etc->is_there_newline = false;
	while (!etc->is_there_newline)
	{
		etc->read_return = read(fd, etc->buf, BUFFER_SIZE);
		if (etc->read_return == 0)
			break ;
		if (etc->read_return == -1)
		{
			free(etc->buf);
			free(etc->static_line);
			free(etc);
			return ("read fail");
		}
		etc->buf[etc->read_return] = '\0';
		printf("buffer                : \"%s\"\n", etc->buf);
		printf("static_line before join: \"%s\"\n", etc->static_line);
		etc->new_static_line = ft_join_till_c(etc->static_line, etc->buf, '\0');
		if (etc->new_static_line == NULL)
		{
			free(etc->buf);
			free(etc->static_line);
			free(etc);
			return ("static_line is NULL");
		}
		free(etc->static_line);
		etc->static_line = etc->new_static_line;
		printf("static_line after join: \"%s\"\n", etc->static_line);
		printf("-----------------------------------\n");
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
	free(etc->buf);
	etc->i_tmp_line = 0;
	while (etc->static_line[etc->i_tmp_line] != '\0' && etc->static_line[etc->i_tmp_line] != '\n')
		etc->i_tmp_line++;
	if (etc->static_line[etc->i_tmp_line] == '\n')
		etc->i_tmp_line++;
	etc->tmp_line = (char *)malloc((etc->i_tmp_line + 1) * sizeof(char));
	if (etc->tmp_line == NULL)
	{
		free(etc->static_line);
		free(etc);
		return ("malloc tmp_line fail");
	}
	etc->i = 0;
	while (etc->i < etc->i_tmp_line)
	{
		etc->tmp_line[etc->i] = etc->static_line[etc->i];
		etc->i++;
	}
	etc->tmp_line[etc->i_tmp_line] = '\0';
	etc->result = etc->tmp_line;
	etc->len_remaining = ft_strlen(etc->static_line + etc->i_tmp_line);
	etc->new_static_line = (char *)malloc((etc->len_remaining + 1) * sizeof(char));
	if (etc->new_static_line == NULL)
	{
		free(etc->tmp_line);
		free(etc->static_line);
		free(etc);
		return ("malloc new_static_line fail");
	}
	etc->i = 0;
	while (etc->i < etc->len_remaining)
	{
		etc->new_static_line[etc->i] = etc->static_line[etc->i_tmp_line + etc->i];
		etc->i++;
	}
	etc->new_static_line[etc->len_remaining] = '\0';
	free(etc->static_line);
	etc->static_line = etc->new_static_line;
	etc->i_static_line = 0;
	etc->i_tmp_line = 0;
	return (etc->result);
}
