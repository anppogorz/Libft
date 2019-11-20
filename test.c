#include <stdio.h>
#include <stdlib.h>

char *ft_malloc(char *str)
{
	char *str_malloc;
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str_malloc = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != '\0')
	{
		str_malloc[i] = str[i];
		i++;
	}
	str_malloc[i] = '\0';
	return (str_malloc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		j++;
	i = -1;
	while (s2[++i] != '\0')
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - j);
}

int main(void)
{
	char str1[] = "";
	char str2[] = "fghij";
	printf("%s", ft_malloc(ft_strjoin(str1, str2)));
	return (0);
}