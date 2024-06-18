#include <stdio.h>
#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	t_etc		*etc;
	char		*tmp_line;
	// char		*return_line;
	static char	*static_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		// return ("fd or BUFFER_SIZE is invalid");
		return (NULL);
	
	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		// return ("malloc etc fail");
		return (NULL);
	
	etc->buffer = malloc(BUFFER_SIZE + 1);
    if (etc->buffer == NULL) 
	{
        free(etc);
        return (NULL);
        // return ("malloc buffer fail");
    }
	static_line = ft_join_till_c("", "", '\0');
	etc->is_there_newline = false;
		
	etc->i_repeat = 0;
	
	while (etc->is_there_newline == false)
	{
		etc->i_repeat++;
		etc->read_return = read(fd, etc->buffer, BUFFER_SIZE);
		if (etc->read_return == 0)
			break;
		if (etc->read_return == -1)
		{
			free(etc->buffer);
			free(etc);
			return (NULL);
			// return ("read fail");
		}
		else
			etc->buffer[etc->read_return] = '\0';
		
		etc->i_buffer = 0;
		while (etc->buffer[etc->i_buffer] != '\0')
		{
			if (etc->buffer[etc->i_buffer] == '\n')
			{
				etc->is_there_newline = true;
				break;
			}
			etc->i_buffer++;
		}
		printf("buffer %zu		: \"%s\"\n", etc->i_repeat, etc->buffer);	
		printf("static_line before join	: \"%s\"\n", static_line);	
		static_line = ft_join_till_c(static_line, etc->buffer, '\0');
		if (static_line == NULL)
		{
			free(etc->buffer);
			free(etc);
			// return ("static_line is NULL");
			return (NULL);
		}
		printf("static_line after join	: \"%s\"\n", static_line);	
		printf("-----------------------------------\n");
	}
	
	

	
	etc->i_tmp_line = 0;
	while (static_line[etc->i_tmp_line] != '\0' && static_line[etc->i_tmp_line++] != '\n');
	// while (static_line[etc->i_tmp_line] != '\0' && static_line[etc->i_tmp_line] != '\n')
	// 	etc->i_tmp_line++;
	
	
	
	

	tmp_line = "";
	tmp_line = ft_join_till_c(tmp_line, static_line, '\0');
	tmp_line[etc->i_tmp_line] = '\0';
	// return_line = "";
	// return_line = ft_join_till_c(return_line, tmp_line, '\0');
	// free(tmp_line);
	free(etc->buffer);
	free(etc);
	return (tmp_line);
	// return (return_line);
}
