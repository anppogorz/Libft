#include <stdlib.h>

char	*ft_strjoin(char const *s1, chqr const *s2)
{
	long long i;
	long long j;
	char const *new;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	new = malloc(sizeof(s1) * (i + j + 1));
	if (new == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j]
		j++;
	}
	new[i + j + 1] = '\0';
	return (new);
}
