#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static t_etc *etc = NULL;

char *get_next_line_bonus(int fd)
{
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
		etc->i_buffer = 0;
		etc->i_repeat = 0;
	}

	etc->buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (etc->buffer == NULL)
	{
		free(etc->static_line);
		free(etc);
		return ("malloc buffer fail");
	}

	etc->is_there_newline = false;
	while (!etc->is_there_newline)
	{
		etc->read_return = read(fd, etc->buffer, BUFFER_SIZE);
		if (etc->read_return == 0)
			break;
		if (etc->read_return == -1)
		{
			free(etc->buffer);
			free(etc->static_line);
			free(etc);
			return ("read fail");
		}
		etc->buffer[etc->read_return] = '\0';

		printf("buffer                : \"%s\"\n", etc->buffer);
		printf("static_line before join: \"%s\"\n", etc->static_line);

		etc->new_static_line = ft_join_till_c(etc->static_line, etc->buffer, '\0');
		if (etc->new_static_line == NULL)
		{
			free(etc->buffer);
			free(etc->static_line);
			free(etc);
			return ("static_line is NULL");
		}
		free(etc->static_line);
		etc->static_line = etc->new_static_line;

		printf("static_line after join: \"%s\"\n", etc->static_line);
		printf("-----------------------------------\n");

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
	}

	free(etc->buffer);

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

	size_t i = 0;
	while (i < etc->i_tmp_line)
	{
		etc->tmp_line[i] = etc->static_line[i];
		i++;
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
	i = 0;
	while (i < etc->len_remaining)
	{
		etc->new_static_line[i] = etc->static_line[etc->i_tmp_line + i];
		i++;
	}
	etc->new_static_line[etc->len_remaining] = '\0';

	free(etc->static_line);
	etc->static_line = etc->new_static_line;

	etc->i_static_line = 0;
	etc->i_tmp_line = 0;

	return (etc->result);
}

void free_static_resources()
{
	if (etc)
	{
		if (etc->static_line)
			free(etc->static_line);
		if (etc->tmp_line)
			free(etc->tmp_line);
		free(etc);
		etc = NULL;
	}
}
