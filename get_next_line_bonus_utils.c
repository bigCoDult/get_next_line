#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin_old(char *s_front, char *s_back)
{
	char	*joined_str;
	size_t	i_in_front;
	size_t	i_in_back;
	size_t	i_out;

	joined_str = (char *)malloc((ft_strlen(s_front) + ft_strlen(s_back) + 1)  * sizeof(char));	
	if (joined_str == NULL)
		return (NULL);
	i_in_front = 0;
	i_in_back = 0;
	i_out = 0;
	while (s_front[i_in_front] && s_front)
		joined_str[i_out++] = s_front[i_in_front++];
	while (s_back[i_in_back] && s_back)
		joined_str[i_out++] = s_back[i_in_back++];
	return (joined_str);
}

char	*ft_join_till_c(char *s_front, char *s_back, char c)
{
	char	*joined_str;
	size_t	i_in_front;
	size_t	i_in_back;
	size_t	i_out;

	joined_str = (char *)malloc((ft_strlen(s_front) + ft_strlen(s_back) + 1)  * sizeof(char));	
	if (joined_str == NULL)
		return (NULL);
	i_in_front = 0;
	i_in_back = 0;
	i_out = 0;
	while (s_front[i_in_front] != c && s_front)
		joined_str[i_out++] = s_front[i_in_front++];
	while (s_back[i_in_back] != c && s_back)
		joined_str[i_out++] = s_back[i_in_back++];
	// free(s_front);
	// free(s_back);
	return (joined_str);
}















