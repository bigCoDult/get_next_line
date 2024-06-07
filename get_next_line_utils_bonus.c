/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:27:45 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/18 09:27:45 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined_str;
	size_t	index_1;
	size_t	index_2;
	size_t	index_3;

	joined_str = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1)  * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	index_1 = 0;
	index_2 = 0;
	index_3 = 0;
	while (str1[index_1])
		joined_str[index_3] = str1[index_1++];
	while (str2[index_2])
		joined_str[index_3] = str2[index_2++];
	return (joined_str);
}












