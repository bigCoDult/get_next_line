/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:26:27 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/18 09:26:27 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
char	*set_single_line(t_etc *etc);

char	*get_next_line(int fd)
{
	t_etc		*etc;
	char		*line_arr[1024];
	char		*return_line;
	static char	*static_line;
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return (-1);
	line_arr[etc->i++] = fd;
	//배열을 어떻게 사용해야 fd 여러개를 수용할 수 있지?
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	etc->read_return = read(fd, etc->buffer, etc->buffer_size);
	if (etc->read_return <= 0)
		return (NULL);
	etc->buffer[etc->read_return] = '\0';
	etc->single_line = set_single_line(etc->buffer);
	ft_memmove(return_line, etc->single_line, ft_strlen(etc->single_line) + 1);
	free(etc);
	return (return_line);
}

char	*set_single_line(t_etc *etc)
{
	etc->i = 0;
	while (etc->single_line[etc->i] != '\n')
		etc->i++;
	ft_strjoin(etc->single_line);
	// 뭐에다가 뭘붙이지?
	// 그럼 스테틱은 어디에서 쓰이지?
	
	
	
	
	return (etc->single_line);
}