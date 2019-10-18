#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char dst[] = "abcdefgh";
	char src[] = "";

	printf("%zu\n", ft_strlcpy(dst, src, 8));
	return (0);
}
