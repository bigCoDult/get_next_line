/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:04:42 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/21 21:11:25 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	process_buffer(t_etc *etc, int fd)
{
	etc->is_there_newline = false;
	// etc->i_repeat = 0;
	while (etc->is_there_newline == false)
	{
		// etc->i_repeat++;
		etc->read_return = read(fd, etc->buf, BUFFER_SIZE);
		if (etc->read_return == 0)
			return (0);
		if (etc->read_return == -1)
		{
			free_etc(etc);
			return (1);
		}
		etc->buf[etc->read_return] = '\0';
		// printf("buffer %zu: \"%s\"\n", etc->i_repeat, etc->buf);
		// printf("st_s before join: \"%s\"\n", etc->st_s);
		if (join_lines(etc) == NULL)
			return (1);
		// printf("st_s after join: \"%s\"\n", etc->st_s);
		// printf("-----------------------------------\n");
		check_newline(etc);
	}
	return (1);
}

char	*allocate_tmp_line(t_etc *etc)
{
	etc->tmp_s = (char *)malloc((etc->i_tmp_s + 1) * sizeof(char));
	if (etc->tmp_s == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	etc->tmp_s[0] = '\0';
	etc->i_tmp_s = 0;
	while (etc->st_s[etc->i_st_s] != '\0' && etc->st_s[etc->i_st_s] != '\n')
		etc->tmp_s[etc->i_tmp_s++] = etc->st_s[etc->i_st_s++];
	if (etc->st_s[etc->i_st_s] == '\n')
	{
		etc->tmp_s[etc->i_tmp_s++] = '\n';
		etc->i_st_s++;
	}
	etc->tmp_s[etc->i_tmp_s] = '\0';
	return (etc->tmp_s);
}

char	*join_lines(t_etc *etc)
{
	char	*new_static_line;

	new_static_line = ft_join_till_c(etc->st_s, etc->buf, '\0');
	if (new_static_line == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	free(etc->st_s);
	etc->st_s = new_static_line;
	return (etc->st_s);
}

char	*ft_join_till_c(char *s1, char *s2, char c)
{
	char	*out_s;
	size_t	i_in_s1;
	size_t	i_in_s2;
	size_t	i_out;

	i_in_s1 = 0;
	i_in_s2 = 0;
	i_out = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	out_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (out_s == NULL)
		return (NULL);
	while (s1 && s1[i_in_s1] != c)
		out_s[i_out++] = s1[i_in_s1++];
	while (s2 && s2[i_in_s2] != c)
		out_s[i_out++] = s2[i_in_s2++];
	out_s[i_out] = '\0';
	return (out_s);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}
