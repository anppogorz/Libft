#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char)s[i] == (unsigned char)c) && (i < n))
			return (s + i);
		i++;
	}
	return (NULL);
}
