#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char const *new;

	i = 0;
	new = malloc(sizeof(s) * (len + 1));
	if (new == 0)
		return (NULL);
	while (i < len)
	{
		new[i] = s[(unsigned int)i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
