/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:00:00 by sanbaek           #+#    #+#             */
/*   Updated: 2024/06/20 19:18:03 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	i;

	i = 1;
	fd1 = open("file2.txt", O_RDONLY);
	while (i <= 5)
	{
		printf("[get_next_line %d]\n", i);
		printf("--------------------------------------------------------\n");
		printf("return_line        : \"%s\"",
			get_next_line_bonus(fd1));
		printf("\n");
		i++;
		printf("-------------------------------------------------------------------------\n");
	}
	close(fd1);
	return (0);
}
