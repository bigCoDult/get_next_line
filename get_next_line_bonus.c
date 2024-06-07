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
char	*set_single_line(t_etc *etc, char *static_line);

char	*get_next_line(int fd)
{
	t_etc		*etc;
	char		*line_arr[1024];
	char		*return_line;
	static char	*static_line;
	
	// line_arr[etc->i++] = fd;
	//배열을 어떻게 사용해야 fd 여러개를 수용할 수 있지?
	
	
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return (-1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	etc->is_there_newline = false;
	while (!etc->is_there_newline)
	{
		etc->read_return = read(fd, etc->buffer, etc->buffer_size);
		if (etc->read_return <= 0)
			return (NULL);
		etc->buffer[etc->buffer_size] = '\0';
		
		static_line = (char *)malloc((etc->buffer_size + 1) * sizeof(char));
		if (static_line == NULL)
			return (NULL);
		static_line[etc->buffer_size] = '\0';
		// 조인을 할려면 널 터미네이트 문자열이 들어가야 하는데 static_line은 지금 쓰레기값으로 차있다
		// 이걸 초기화하는 과정은 while 밖에서 해야할듯?
		// 맞나?
		// 말록한건 길이 늘리고 프리해야하는데 그게 언제지?
		static_line = ft_strjoin(static_line, etc->buffer);
		
		
		while (etc->buffer[etc->index_1] != '\0')
		{
			if (etc->buffer[etc->index_1] == '\n')
				etc->is_there_newline = true;
			etc->index_1++;
		}
		// static_line = '\0';
		

	}
	
	etc->single_line = get_single_line(etc, static_line);
	
	ft_memmove(return_line, etc->single_line, ft_strlen(etc->single_line) + 1);
	free(etc);
	return (return_line);
}

char	*set_single_line(t_etc *etc, char *static_line)
{
	//버퍼를 한번 퍼왔을때 개행문자가 몇개있을지(0,3,100) 불확실함
	etc->index_1 = 0;
	etc->index_2 = 0;
	ft_strjoin(etc->before_line, static_line);
	ft_strjoin(static_line, etc->buffer);
	while (etc->buffer[etc->index_1] != '\0')
	{
		if (etc->buffer[etc->index_1] == '\n')
		{
			//이제 뭐함?
		}
		etc->index_1++;
	
	}
	
	
	return (etc->single_line);
}