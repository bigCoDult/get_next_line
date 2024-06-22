/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:04:42 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/22 18:20:06 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	set_buf(t_etc *etc, int fd)
{
	etc->is_there_newline = false;
	// etc->i_repeat = 0;
	while (etc->is_there_newline == false)
	{
		// etc->i_repeat++;
		etc->rtn_read = read(fd, etc->buf, BUFFER_SIZE);
		if (etc->rtn_read == 0)
		{
			// free_etc(etc);
			// free(etc->buf);
			// free(etc->tmp_s);
			// free(etc->single_s);
			// free(etc);
			return (0);
		}
		if (etc->rtn_read == -1)
		{
			free_etc(etc);
			return (0);
		}
		// printf("buffer %zu: \"%s\"\n", etc->i_repeat, etc->buf);
		// printf("single_s before join: \"%s\"\n", etc->single_s);
		etc->buf[etc->rtn_read] = '\0';
		if (join_s(etc) == NULL)
			return (0);
		// printf("single_s after join: \"%s\"\n", etc->single_s);
		// printf("-----------------------------------\n");
		is_newline(etc);
	}
	return (1);
}

char	*set_tmp_s(t_etc *etc)
{
	etc->tmp_s = (char *)malloc((etc->i_tmp_s + 1) * sizeof(char));
	if (etc->tmp_s == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	etc->tmp_s[0] = '\0';
	etc->i_tmp_s = 0;
	while (etc->single_s[etc->i_single_s] != '\0' && etc->single_s[etc->i_single_s] != '\n')
		etc->tmp_s[etc->i_tmp_s++] = etc->single_s[etc->i_single_s++];
	if (etc->single_s[etc->i_single_s] == '\n')
	{
		etc->tmp_s[etc->i_tmp_s++] = '\n';
		etc->i_single_s++;
	}
	etc->tmp_s[etc->i_tmp_s] = '\0';
	return (etc->tmp_s);
}

char	*join_s(t_etc *etc)
{
	char	*new_static_line;

	new_static_line = join_s_till_c(etc->single_s, etc->buf, '\0');
	if (new_static_line == NULL)
	{
		free_etc(etc);
		return (NULL);
	}
	free(etc->single_s);
	etc->single_s = new_static_line;
	return (etc->single_s);
}

char	*join_s_till_c(char *s1, char *s2, char c)
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
