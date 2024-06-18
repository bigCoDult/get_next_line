#include <stdio.h>
#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd) {
    t_etc *etc;
    char *tmp_line;
    static char *static_line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return (NULL);
    }

    etc = malloc(sizeof(t_etc));
    if (etc == NULL) {
        return (NULL);
    }

    etc->buffer = malloc(BUFFER_SIZE + 1);
    if (etc->buffer == NULL) {
        free(etc);
        return (NULL);
    }

    if (static_line == NULL) {
        static_line = malloc(1); // Initial allocation for static_line
        if (static_line == NULL) {
            free(etc->buffer);
            free(etc);
            return (NULL);
        }
        static_line[0] = '\0'; // Initialize to an empty string
    }

    etc->is_there_newline = false;

    while (!etc->is_there_newline) {
        etc->read_return = read(fd, etc->buffer, BUFFER_SIZE);
        if (etc->read_return <= 0) {
            free(etc->buffer);
            free(etc);
            return (NULL); // End of file or read error
        }

        etc->buffer[etc->read_return] = '\0';










        char *temp = ft_join_till_c(static_line, etc->buffer, '\0'); // Join without looking for a specific char
        free(static_line); // Free the old static_line
        static_line = temp;
















        for (int i = 0; etc->buffer[i] != '\0'; i++) {
            if (etc->buffer[i] == '\n') {
                etc->is_there_newline = true;
                break;
            }
        }
    }

    // Find the newline character in static_line to determine where to cut the line
    size_t line_length = 0;
    while (static_line[line_length] != '\n' && static_line[line_length] != '\0') {
        line_length++;
    }
    if (static_line[line_length] == '\n') {
        line_length++; // Include the newline character
    }

    tmp_line = malloc(line_length + 1); // Allocate memory for tmp_line
    if (tmp_line == NULL) {
        free(etc->buffer);
        free(etc);
        return (NULL);
    }

    for (size_t i = 0; i < line_length; i++) {
        tmp_line[i] = static_line[i]; // Copy the line from static_line to tmp_line
    }
    tmp_line[line_length] = '\0'; // Null-terminate tmp_line

    // Prepare static_line for the next call
    char *new_start = ft_join_till_c(static_line + line_length, "", '\0'); // Create the new static_line from the remainder
    free(static_line);
    static_line = new_start;

    free(etc->buffer);
    free(etc);
    return tmp_line; // Return the line extracted
}
