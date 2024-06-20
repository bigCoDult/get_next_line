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

static t_etc	*g_etc = NULL;

char	*get_next_line_bonus(int fd)
{
	char	*buffer;
	char	*result;
	char	*new_static_line;
	size_t	len_remaining;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("fd or BUFFER_SIZE is invalid");
	if (g_etc == NULL)
	{
		g_etc = (t_etc *)malloc(1 * sizeof(t_etc));
		if (g_etc == NULL)
			return ("malloc etc fail");
		g_etc->static_line = (char *)malloc(1 * sizeof(char));
		if (g_etc->static_line == NULL)
		{
			free(g_etc);
			return ("malloc static_line fail");
		}
		g_etc->static_line[0] = '\0';
		g_etc->is_there_newline = false;
		g_etc->i_static_line = 0;
		g_etc->i_tmp_line = 0;
		g_etc->i_buffer = 0;
		g_etc->i_repeat = 0;
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(g_etc->static_line);
		free(g_etc);
		return ("malloc buffer fail");
	}
	g_etc->is_there_newline = false;
	while (!g_etc->is_there_newline)
	{
		g_etc->read_return = read(fd, buffer, BUFFER_SIZE);
		if (g_etc->read_return == 0)
			break ;
		if (g_etc->read_return == -1)
		{
			free(buffer);
			free(g_etc->static_line);
			free(g_etc);
			return ("read fail");
		}
		buffer[g_etc->read_return] = '\0';
		printf("buffer                : \"%s\"\n", buffer);
		printf("static_line before join: \"%s\"\n", g_etc->static_line);
		new_static_line = ft_join_till_c(g_etc->static_line, buffer, '\0');
		if (new_static_line == NULL)
		{
			free(buffer);
			free(g_etc->static_line);
			free(g_etc);
			return ("static_line is NULL");
		}
		free(g_etc->static_line);
		g_etc->static_line = new_static_line;
		printf("static_line after join: \"%s\"\n", g_etc->static_line);
		printf("-----------------------------------\n");
		g_etc->i_buffer = 0;
		while (buffer[g_etc->i_buffer] != '\0')
		{
			if (buffer[g_etc->i_buffer] == '\n')
			{
				g_etc->is_there_newline = true;
				break ;
			}
			g_etc->i_buffer++;
		}
	}
	free(buffer);
	g_etc->i_tmp_line = 0;
	while (g_etc->static_line[g_etc->i_tmp_line] != '\0' && g_etc->static_line[g_etc->i_tmp_line] != '\n')
		g_etc->i_tmp_line++;
	if (g_etc->static_line[g_etc->i_tmp_line] == '\n')
		g_etc->i_tmp_line++;
	g_etc->tmp_line = (char *)malloc((g_etc->i_tmp_line + 1) * sizeof(char));
	if (g_etc->tmp_line == NULL)
	{
		free(g_etc->static_line);
		free(g_etc);
		return ("malloc tmp_line fail");
	}
	i = 0;
	while (i < g_etc->i_tmp_line)
	{
		g_etc->tmp_line[i] = g_etc->static_line[i];
		i++;
	}
	g_etc->tmp_line[g_etc->i_tmp_line] = '\0';
	result = g_etc->tmp_line;
	len_remaining = ft_strlen(g_etc->static_line + g_etc->i_tmp_line);
	new_static_line = (char *)malloc((len_remaining + 1) * sizeof(char));
	if (new_static_line == NULL)
	{
		free(g_etc->tmp_line);
		free(g_etc->static_line);
		free(g_etc);
		return ("malloc new_static_line fail");
	}
	i = 0;
	while (i < len_remaining)
	{
		new_static_line[i] = g_etc->static_line[g_etc->i_tmp_line + i];
		i++;
	}
	new_static_line[len_remaining] = '\0';
	free(g_etc->static_line);
	g_etc->static_line = new_static_line;
	g_etc->i_static_line = 0;
	g_etc->i_tmp_line = 0;
	return (result);
}

void	free_static_resources(void)
{
	if (g_etc)
	{
		if (g_etc->static_line)
			free(g_etc->static_line);
		if (g_etc->tmp_line)
			free(g_etc->tmp_line);
		free(g_etc);
		g_etc = NULL;
	}
}
