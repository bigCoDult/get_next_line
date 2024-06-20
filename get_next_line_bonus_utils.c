#include "get_next_line_bonus.h"

size_t ft_strlen(char *s)
{
	size_t length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}

char *ft_join_till_c(char *s_front, char *s_back, char c)
{
	char *joined_str;
	size_t i_in_front = 0;
	size_t i_in_back = 0;
	size_t i_out = 0;

	if (s_front == NULL || s_back == NULL)
		return (NULL);
	joined_str = (char *)malloc((ft_strlen(s_front) + ft_strlen(s_back) + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	while (s_front && s_front[i_in_front] != c)
		joined_str[i_out++] = s_front[i_in_front++];
	while (s_back && s_back[i_in_back] != c)
		joined_str[i_out++] = s_back[i_in_back++];
	joined_str[i_out] = '\0';

	return (joined_str);
}
