/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:18:43 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/23 14:18:44 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd1;
	int		i;
	char	*line;

	i = 1;
	fd1 = open("file2.txt", O_RDONLY);
	while (1)
	{
		printf("[get_next_line %d]\n", i);
		line = get_next_line(fd1);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		printf("-----------------------------\n");
		printf("return_line        : \"%s\"", line);
		printf("\n");
		free(line);
		i++;
		printf("-----------------------------------------------------------\n");
	}
	close(fd1);
	return (0);
}
