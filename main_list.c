#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s", list->content);
		list = list->next;
	}
}

int	main(void)
{
	t_list **list;
	t_list *new;
	char str[] = "ABCDE";

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = str;
		new->next = NULL;
	}
	*list = NULL;
	ft_lstadd_front(list, new);
//	ft_lstadd_front(list, new);
	printf("%d\n", ft_lstsize(*list));
	print_list(*list);
	return (0);
}
