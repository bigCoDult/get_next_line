#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static t_etc *etc = NULL;

char *get_next_line_bonus(int fd)
{
    char *buffer;
    char *result;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return ("fd or BUFFER_SIZE is invalid");
    }

    if (etc == NULL)
    {
        etc = (t_etc *)malloc(1 * sizeof(t_etc));
        if (etc == NULL)
        {
            return ("malloc etc fail");
        }
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

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
    {
        free(etc->static_line);
        free(etc);
        return ("malloc buffer fail");
    }

    etc->is_there_newline = false;
    while (!etc->is_there_newline)
    {
        etc->read_return = read(fd, buffer, BUFFER_SIZE);
        if (etc->read_return == 0)
        {
            break;
        }
        if (etc->read_return == -1)
        {
            free(buffer);
            free(etc->static_line);
            free(etc);
            return ("read fail");
        }
        buffer[etc->read_return] = '\0';

        printf("buffer                : \"%s\"\n", buffer);
        printf("static_line before join: \"%s\"\n", etc->static_line);

        char *new_static_line = ft_join_till_c(etc->static_line, buffer, '\0');
        if (new_static_line == NULL)
        {
            free(buffer);
            free(etc->static_line);
            free(etc);
            return ("static_line is NULL");
        }
        free(etc->static_line);
        etc->static_line = new_static_line;

        printf("static_line after join: \"%s\"\n", etc->static_line);
        printf("-----------------------------------\n");

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
    }

    free(buffer);

    etc->i_tmp_line = 0;
    while (etc->static_line[etc->i_tmp_line] != '\0' && etc->static_line[etc->i_tmp_line] != '\n')
    {
        etc->i_tmp_line++;
    }
    if (etc->static_line[etc->i_tmp_line] == '\n')
    {
        etc->i_tmp_line++;
    }

    etc->tmp_line = (char *)malloc((etc->i_tmp_line + 1) * sizeof(char));
    if (etc->tmp_line == NULL)
    {
        free(etc->static_line);
        free(etc);
        return ("malloc tmp_line fail");
    }

    for (size_t i = 0; i < etc->i_tmp_line; i++)
    {
        etc->tmp_line[i] = etc->static_line[i];
    }
    etc->tmp_line[etc->i_tmp_line] = '\0';

    result = etc->tmp_line;

    // Update static_line to remove the part that was returned
    size_t len_remaining = ft_strlen(etc->static_line + etc->i_tmp_line);
    char *new_static_line = (char *)malloc((len_remaining + 1) * sizeof(char));
    if (new_static_line == NULL)
    {
        free(etc->tmp_line);
        free(etc->static_line);
        free(etc);
        return ("malloc new_static_line fail");
    }
    for (size_t i = 0; i < len_remaining; i++)
    {
        new_static_line[i] = etc->static_line[etc->i_tmp_line + i];
    }
    new_static_line[len_remaining] = '\0';

    free(etc->static_line);
    etc->static_line = new_static_line;

    // Reset indices for next call
    etc->i_static_line = 0;
    etc->i_tmp_line = 0;

    return (result);
}

void free_static_resources()
{
    if (etc)
    {
        free(etc->static_line);
        free(etc);
        etc = NULL;
    }
}
