#include <stdlib.h>

int	ft_count(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (n == 0)
		return (1)
	return (i);
}

char	*ft_nbr(char *str, int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		str[i] = n % 10;
		n = n / 10;
		i++;
	}
	
char	*ft_itoa(int n)
{
	int i;
	int sign;
	long long nbr;
	char *str;
	

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = n;
	i = ft_count(n, sign);
	str = malloc(sizeof(char) * (i + 1);
	if (str == 0)
		return (NULL);
	
