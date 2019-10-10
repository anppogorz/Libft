#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;
	size_t i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
