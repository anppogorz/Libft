char	*ft_find_sentence(char *readstring, char **line, char c);

int	main(void)
{
	char readstring[] = "abcde\nfghijk";
	char *line;
	char *rest;

	printf("Ceci est rest: %s", rest = ft_find_sentence(readstring, &line, '\n'));
	return (0);
}
