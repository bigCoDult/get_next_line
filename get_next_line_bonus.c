#include <stdio.h>
#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	// t_etc		*etc;
	// static char	*static_line;
	// char		*return_line;
	char		*buffer;
	static t_etc		*etc;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("fd or BUFFER_SIZE is invalid");
		// return (NULL);
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return ("malloc etc fail");
		// return (NULL);
	
    // if (etc->buffer != NULL)
        // free(etc->buffer);
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(etc);
		return ("malloc buffer fail");
		// return (NULL);
	}
	// free(etc->buffer);
	// etc->buffer = (char *)malloc(BUFFER_SIZE + 1);
    // if (etc->buffer == NULL) 
	// {
    //     free(etc);
    //     return (NULL);
    //     // return ("malloc buffer fail");
    // }
		
	etc->static_line = "";
	etc->is_there_newline = false;
	etc->i_repeat = 0;
	etc->read_return = 0;
	while (etc->is_there_newline == false)
	{
		etc->i_repeat++;
		etc->read_return = read(fd, buffer, BUFFER_SIZE);
		if (etc->read_return == 0)
			break;
		if (etc->read_return == -1)
		{
			free(buffer);
			free(etc);
			return ("read fail");
			// return (NULL);
		}
		else
			buffer[etc->read_return] = '\0';
		
		etc->i_buffer = 0;
		while (buffer[etc->i_buffer] != '\0')
		{
			if (buffer[etc->i_buffer] == '\n')
			{
				etc->is_there_newline = true;
				break;
			}
			etc->i_buffer++;
		}
		printf("buffer %zu		: \"%s\"\n", etc->i_repeat, etc->buffer);	
		// printf("static_line before join	: \"%s\"\n", static_line);	
		printf("static_line before join	: \"%s\"\n", etc->static_line);	
		// static_line = ft_join_till_c(static_line, etc->buffer, '\0');
		
		// if (static_line == NULL)
		etc->static_line = ft_join_till_c(etc->static_line, buffer, '\0');
		if (etc->static_line == NULL)
		{
			free(buffer);
			free(etc);
			free(etc->static_line);
			return ("static_line is NULL");
			// return (NULL);
		}
		// printf("static_line after join	: \"%s\"\n", static_line);	
		printf("static_line after join	: \"%s\"\n", etc->static_line);	
		// printf("-----------------------------------\n");
	}
	
	

	// etc->i_tmp_line = 0;
	
	// while (static_line[etc->i_tmp_line] != '\0' && static_line[etc->i_tmp_line++] != '\n');
	while (etc->static_line[etc->i_tmp_line] != '\0' && etc->static_line[etc->i_tmp_line++] != '\n');
	// while (static_line[etc->i_tmp_line] != '\0' && static_line[etc->i_tmp_line] != '\n')
	// 	etc->i_tmp_line++;
	
	
	
	

	// etc->tmp_line = ft_join_till_c(etc->tmp_line, static_line, '\0');
	
	
	
	
	// etc->tmp_line = ft_join_till_c(etc->tmp_line, etc->static_line, '\0');
	etc->tmp_line = "";
	etc->i_tmp_line = 0;
	while (etc->static_line[etc->i_static_line] != '\0' && etc->static_line[etc->i_static_line] != '\n')
		etc->tmp_line[etc->i_tmp_line++] = etc->static_line[etc->i_static_line++];
	
	
	
	
	
	
	
	
	
	// etc->tmp_line[etc->i_static_line] = '\0';
	// return_line = "";
	// return_line = ft_join_till_c(return_line, etc->tmp_line, '\0');
	// free(etc->tmp_line);
	free(buffer);
	// free(etc);
	return (etc->tmp_line);
	// return (return_line);
}
