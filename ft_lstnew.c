#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new;
	int i;

	i = 0;
	while (content[i] != '\0')
		i++;
	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	new->content = malloc(sizeof(t_list) * i);
	if (new->content == NULL)
		return (NULL)
	new->next = NULL;
	return (new);
}
