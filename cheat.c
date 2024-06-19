
#include <stdio.h>
#include "get_next_line_bonus.h"

char *get_next_line_bonus(int fd) {
    static t_etc *etc = NULL;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0) return "fd or BUFFER_SIZE is invalid";

    if (etc == NULL) {
        etc = malloc(sizeof(t_etc));
        if (etc == NULL) return "malloc etc fail";
        etc->static_line = malloc(1);  // Initialize as empty string
        if (etc->static_line == NULL) {
            free(etc);
            return "malloc static_line fail";
        }
        etc->static_line[0] = '\0';
    }

    buffer = malloc(BUFFER_SIZE + 1);
    if (buffer == NULL) {
        free(etc);
        return "malloc buffer fail";
    }

    etc->is_there_newline = false;
    etc->i_repeat = 0;

    while (!etc->is_there_newline) {
        etc->read_return = read(fd, buffer, BUFFER_SIZE);
        if (etc->read_return == 0) break;
        if (etc->read_return == -1) {
            free(buffer);
            return "read fail";
        }
        buffer[etc->read_return] = '\0';

        char *new_static_line = ft_join_till_c(etc->static_line, buffer, '\0');
        free(etc->static_line); // Free old static_line
        etc->static_line = new_static_line;

        size_t i = 0;
        while (buffer[i] != '\0') {
            if (buffer[i] == '\n') {
                etc->is_there_newline = true;
                break;
            }
            i++;
        }
    }

    free(buffer);

    // Manually find the end of the line or string
    size_t line_length = 0;
    while (etc->static_line[line_length] != '\n' && etc->static_line[line_length] != '\0') {
        line_length++;
    }
    if (etc->static_line[line_length] == '\n') line_length++;

    // Copy the line to return
    char *return_line = malloc(line_length + 1);
    if (return_line == NULL) return "malloc return_line fail";
    size_t j = 0;
    while (j < line_length) {
        return_line[j] = etc->static_line[j];
        j++;
    }
    return_line[line_length] = '\0';

    // Shift the remaining characters in static_line to the start
    size_t start = 0;
    size_t k = line_length;
    while (etc->static_line[k] != '\0') {
        etc->static_line[start] = etc->static_line[k];
        start++;
        k++;
    }
    etc->static_line[start] = '\0';

    return return_line;
}
