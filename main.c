#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	i;

	i = 1;
	fd1 = open("file2.txt", O_RDONLY);
	// fd1 = 1;
	while (i <= 4)
	{
		printf("[get_next_line %d]\n", i);
		printf("--------------------------------------------------------\n");
		printf("return_line        : \"%s\"", get_next_line_bonus(fd1));
		free_static_resources();  // Ensure resources are freed at the end
		printf("\n");
		i++;
		printf("-------------------------------------------------------------------------\n");
	}
	close(fd1);
	return (0);
}
