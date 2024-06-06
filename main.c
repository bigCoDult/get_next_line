#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;
	int 	i;

	i = 1;	
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	
	while (i <= 10)
	{
		printf("%d", i);
		printf("\n");
		printf("%s", get_next_line(fd1));
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	printf("\n");
	
	i = 1;
	while (i <= 10)
	{
		printf("%d", i);
		printf("\n");
		printf("%s", get_next_line(fd2));
		printf("\n");
	}
	close(fd1);
	close(fd2);
	return (0);
}