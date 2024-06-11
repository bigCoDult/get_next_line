#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	t_etc		*etc;
	char		*return_line;
	static char	*static_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return (NULL);
	
	etc->buffer = malloc(BUFFER_SIZE + 1);
    if (etc->buffer == NULL) 
	{
        free(etc);
        return NULL;
    }
	etc->is_there_newline = false;
	etc->index_1 = 0;

	while (etc->is_there_newline == false)
	{
		// etc->read_return = read(fd, etc->buffer, BUFFER_SIZE);
		etc->read_return = read(fd, etc->buffer, 2);
		if (etc->read_return <= 0)
		{
			free(etc->buffer);
			free(etc);
			return (NULL);
		}
		// etc->buffer[BUFFER_SIZE] = '\0';
		etc->buffer[1] = '\0';
					#include <stdio.h>
					printf("buffer: %s\n", etc->buffer);	
					printf("static_line: %s\n", static_line);	
		static_line = "";
		static_line = ft_strjoin(static_line, etc->buffer);
					printf("buffer: %s\n", etc->buffer);	
					printf("static_line: %s\n", static_line);	
		if (static_line == NULL)
		{
			free(etc->buffer);
			free(etc);
			return (NULL);
		}
		while (etc->buffer[etc->index_1] != '\0')
		{
			if (etc->buffer[etc->index_1] == '\n')
			{
				etc->is_there_newline = true;
				break;
			}
			etc->index_1++;
		}
	}
	return_line = "\0";
	ft_strjoin(static_line, etc->buffer);
	free(etc->buffer);
	free(etc);
	return (return_line);
}
