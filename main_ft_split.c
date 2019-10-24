#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char c);

int	main(void)
{
	int i;

	i = 0;
	char **tab;
	char str[] = "      split       this for   me  !       ";
	char set = ' ';
	tab = ft_split(str, set);
	while (i < 6)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
