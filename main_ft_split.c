#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	int i;

	i = 0;
	char **tab;
	char str[] = "bhrefgbehrjf herjferbfejr rfbh uerbfguerbr buerb frebh refr f er fer fuf  heruf ber   few e fe   ew fewf h few";
	char charset[] = " ";
	tab = ft_split(str, charset);
	while (tab[i] != '\0')
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
