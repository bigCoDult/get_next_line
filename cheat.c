#include <stdio.h>
#include "get_next_line_bonus.h"

char *get_next_line_bonus(int fd)
{
    static t_etc *etc;
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
            return (NULL);
        }
        etc->static_line = (char *)malloc(1 * sizeof(char));
        if (etc->static_line == NULL) 
        {
            free(etc);
            return (NULL);
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
        return (NULL);
    }

    etc->is_there_newline = false;
    etc->i_repeat = 0;
    while (etc->is_there_newline == false)
    {
        etc->i_repeat++;
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
            return (NULL);
        }
        buffer[etc->read_return] = '\0';

        printf("buffer %zu              : \"%s\"\n", etc->i_repeat, buffer);
        printf("static_line before join : \"%s\"\n", etc->static_line);

        char *new_static_line = ft_join_till_c(etc->static_line, buffer, '\0');
        if (new_static_line == NULL)
        {
            free(buffer);
            free(etc->static_line);
            free(etc);
            return (NULL);
        }
        free(etc->static_line);
        etc->static_line = new_static_line;

        printf("static_line after join  : \"%s\"\n", etc->static_line);
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
        return (NULL);
    }

    etc->tmp_line[0] = '\0';
    etc->i_tmp_line = 0;
    while (etc->static_line[etc->i_static_line] != '\0' && etc->static_line[etc->i_static_line] != '\n')
    {
        etc->tmp_line[etc->i_tmp_line++] = etc->static_line[etc->i_static_line++];
    }
    if (etc->static_line[etc->i_static_line] == '\n')
    {
        etc->tmp_line[etc->i_tmp_line++] = '\n';
        etc->i_static_line++;
    }
    etc->tmp_line[etc->i_tmp_line] = '\0';

    result = etc->tmp_line;

    // Reset indices for next call
    if (etc->static_line[etc->i_static_line] == '\0')
    {
        free(etc->static_line);
        etc->static_line = NULL;
    }
    etc->i_static_line = 0;
    etc->i_tmp_line = 0;

    return (result);
}
