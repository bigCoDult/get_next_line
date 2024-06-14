#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	t_etc		*etc;
	char		*return_line;
	static char	*static_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("fd||BUFFER_SIZE fail");
		// return (NULL);
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return ("etc malloc fail");
		// return (NULL);
	
	etc->buffer = malloc(BUFFER_SIZE + 1);
    if (etc->buffer == NULL) 
	{
        free(etc);
        // return (NULL);
        return ("buffer malloc fail");
    }
	etc->is_there_newline = false;
	etc->i_newline = 0;

	etc->i_buffer = 0;
	// while (etc->is_there_newline == false)
	while (etc->i_buffer++ < 10)
	{
		// etc->read_return = read(fd, etc->buffer, 2);
		etc->read_return = read(fd, etc->buffer, BUFFER_SIZE);
		if (etc->read_return == -1)
		{
			free(etc->buffer);
			free(etc);
			// return (NULL);
			return ("read fail");
		}
		if (etc->read_return != BUFFER_SIZE)
		{
			free(etc->buffer);
			free(etc);
			return ("read enough, file ended");
			// return (NULL);
		}
		// printf("[buffer %zu]\n%s\n", etc->i_buffer, etc->buffer);	
		etc->buffer[BUFFER_SIZE] = '\0';
		etc->buffer[1] = '\0';
		// etc->i_buffer++;
		#include <stdio.h>
		printf("[buffer %zu]\n%s\n", etc->i_buffer, etc->buffer);	
		// printf("static_line: %s\n\n", static_line);	
		static_line = "";
		static_line = ft_strjoin(static_line, etc->buffer);
// #include <string.h>
		// static_line = strncat(static_line, etc->buffer, etc->read_return);
// printf("buffer: %s\n", etc->buffer);	
// printf("static_line: %s\n", static_line);	
		if (static_line == NULL)
		{
			free(etc->buffer);
			free(etc);
			return ("static_line is NULL");
			// return (NULL);
		}
		while (etc->buffer[etc->i_newline] != '\0')
		{
			if (etc->buffer[etc->i_newline] == '\n')
			{
				etc->is_there_newline = true;
				break;
			}
			etc->i_newline++;
		}
	}
	return_line = "\0";
	ft_strjoin(static_line, etc->buffer);
	free(etc->buffer);
	free(etc);
	return (return_line);
}
