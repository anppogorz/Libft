#include <string.h>

char	*ft_strdup(const char *s1)
{
	int i;
	const char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = malloc(sizeof(s2) * i);
	if (s2 == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	return (s2);
}
