#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int 	i;
	
	i = 1;	
	fd1 = open("file1.txt", O_RDONLY);
	
	while (i <= 10)
	{
		printf("%d", i);
		printf("\n");
		printf("%s", get_next_line_bonus(fd1));
		printf("\n");
		i++;
	}
	close(fd1);
	return (0);
}