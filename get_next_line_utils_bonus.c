#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
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
		joined_str[index_3++] = str1[index_1++];
	while (str2[index_2])
		joined_str[index_3++] = str2[index_2++];
	return (joined_str);
}

// char	*ft_memmove(char *dest, char *src, size_t count)
// {
// 	unsigned char	*dest_tmp;
// 	unsigned char	*src_tmp;
// 	size_t			index;

// 	index = 0;
// 	dest_tmp = (unsigned char *)dest;
// 	src_tmp = (unsigned char *)src;
// 	if (dest_tmp > src_tmp)
// 	{
// 		while (count--)
// 			dest_tmp[count] = src_tmp[count];
// 	}
// 	else
// 		while (count--)
// 		{
// 			dest_tmp[index] = src_tmp[index];
// 			index++;
// 		}
// 	return (dest);
// }
