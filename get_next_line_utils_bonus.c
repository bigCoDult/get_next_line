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
	size_t	in1_index;
	size_t	in2_index;
	size_t	out_index;

	joined_str = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1)  * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	in1_index = 0;
	in2_index = 0;
	out_index = 0;
	while (str1[in1_index])
		joined_str[out_index++] = str1[in1_index++];
	while (str2[in2_index])
		joined_str[out_index++] = str2[in2_index++];
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
