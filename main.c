#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int 	i;
	
	i = 1;	
	fd1 = open("file2.txt", O_RDONLY);
	while (i <= 5)
	{	
		printf("[get_next_line %d]\n", i);
		// printf("\n");
		// printf("\n");
		printf("--------------------------------------------------------\n");
		printf("return_line		: \"%s\"", get_next_line_bonus(fd1));
		printf("\n");
		i++;
		printf("-------------------------------------------------------------------------\n");
	}
	close(fd1);
	return (0);
}