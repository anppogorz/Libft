/*
#include "libft.h"
#include <stdio.h>

int main()
{
    
ft_split(NULL, 'm');
ft_putendl_fd("Test finished 1", 1);
ft_split(NULL, 'K');
ft_putendl_fd("Test finished 2", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 3", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 4", 1);
ft_split("XW2eo73erDu2MAkygRAEh0PkFIqgSOniPxueE89o8NmbVeHpB5STXf8SXsmRSzHd", '\0');
ft_putendl_fd("Test finished 5", 1);
ft_split(NULL, '\0');
ft_putendl_fd("Test finished 6", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 7", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 8", 1);
ft_split("rXyp", '\0');
ft_putendl_fd("Test finished 9", 1);
ft_split("", 'k');
ft_putendl_fd("Test finished 10", 1);
ft_split("cOcdzZZw2awNSCByI19isdSwldlroljtCGulWn3U3SJB2", '5');
ft_putendl_fd("Test finished 11", 1);
ft_split(NULL, '\0');
ft_putendl_fd("Test finished 12", 1);
ft_split(NULL, 'Z');
ft_putendl_fd("Test finished 13", 1);
ft_split(NULL, '\0');
ft_putendl_fd("Test finished 14", 1);
ft_split("gQFhbNnZYX3aPFMrNmSSvOBFQQTnwehPAxvuEr7HZXExlUPqtakxMasctjgwZM1yEhAFmP1NUeTivi", 'G');
ft_putendl_fd("Test finished 15", 1);
ft_split("", 'K');
ft_putendl_fd("Test finished 16", 1);
ft_split("", 'u');
ft_putendl_fd("Test finished 17", 1);
ft_split("18rdO1jCs3rsE73TrcFIDWJNj59OZg0HE5ShD", 'j');
ft_putendl_fd("Test finished 18", 1);
ft_split("y8uISpG8n1a4z66XVv7zJDaNy6EpnL9Y6HBTP187KJiGYvvZi46UMIdIwQRwejQ0l", 'K');
ft_putendl_fd("Test finished 19", 1);
ft_split("OTjRU2Cx8Xk7xvdUEIcY0RWCrQBsPDR4H86Gi0tWp3jfSskEwY2zo45KLiKbBkgQ", 'A');
ft_putendl_fd("Test finished 20", 1);
ft_split("v7ZJDF81IrDn9BBkCZWGiYAVVMqETLnn8HAH3gjzXzQmmgKXRbBQvEt0Sui4igEU1P60shJIKCd68UIFR7n2qzA3Q0yhnh8Z", 'u');
ft_putendl_fd("Test finished 21", 1);
ft_split("dhl4br7mqPGmn4fPdM3", '2');
ft_putendl_fd("Test finished 22", 1);
ft_split("", '2');
ft_putendl_fd("Test finished 23", 1);
ft_split(NULL, 'q');
ft_putendl_fd("Test finished 24", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 25", 1);
ft_split("", 'E');
ft_putendl_fd("Test finished 26", 1);
ft_split("", '\0');
ft_putendl_fd("Test finished 27", 1);
ft_split("", 'M');
ft_putendl_fd("Test finished 28", 1);
ft_split(NULL, '\0');
ft_putendl_fd("Test finished 29", 1);
ft_putendl_fd("Test finished 30", 1);


t_list  **lst = NULL;
int a;
t_list *new;

lst = (t_list **)malloc(2000);
*lst = NULL;
a = 5;
new = ft_lstnew((void *)&a);
printf("%i\n", *((int *)new->content));
ft_lstadd_front(lst, new);
printf("GO\n");
while (*lst != NULL)
{
    printf("%i\n", *((int *)(*lst)->content));
    *lst = (*lst)->next;
}
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"	// If you don't use libft_bonus.h just replace the following include.
/*

char ft_lstnew_test(void);
char ft_lstadd_front_test(void);
void ft_lstadd_front_protected(void);
char ft_lstsize_test(void);
void ft_lstsize_protected(void);
char ft_lstlast_test(void);
void ft_lstlast_protected(void);
char ft_lstadd_back_test(void);
void ft_lstadd_back_protected(void);
char ft_lstdelone_test(void);
void ft_lstdelone_protected(void);
char ft_lstclear_test(void);
void ft_lstclear_protected(void);
char ft_lstiter_test(void);
void ft_lstiter_protected(void);
char ft_lstmap_test(void);
void ft_lstmap_protected(void);

int function_ko = 0;
int	good_game = 1;

int main()
{
	printf("0wn3d by marandre and mbochet\nAll your database are belong to us.\n");
    printf("Each function depends on the other, so if one is failing, the test will stop.\n\n");
	
    if (ft_lstnew_test())
		return (1);
	
	if (ft_lstadd_front_test())
		return (1);
	
	if (ft_lstsize_test())
		return (1);
	
	if (ft_lstlast_test())
		return (1);
	
	if (ft_lstadd_back_test())
		return (1);
	
	if (ft_lstdelone_test())
		return (1);
	
	if (ft_lstclear_test())
		return (1);
	
	if (ft_lstiter_test())
		return (1);
	
	if (ft_lstmap_test())
		return (1);
	
    printf("\nTesting function protection:\n");
    ft_lstadd_front_protected();
	ft_lstsize_protected();
	ft_lstlast_protected();
	ft_lstadd_back_protected();
	ft_lstdelone_protected();
	ft_lstclear_protected();
	ft_lstiter_protected();
	ft_lstmap_protected();
	
	printf("\n");
	if (good_game)
		printf("GOOD GAME !\n");
	return (0);
}

void ko_print(char *txt)
{
    printf("\t\033[31m[KO]\033[0m : %s\n", txt);
    function_ko = 1;
}

void ok_print(void)
{
    printf("\t\033[32m[OK]\033[0m\n");
}

void unknown_print(char *txt)
{
    printf("\t[??] : %s\n", txt);
}

char ft_lstnew_test(void)
{
    t_list *list;
    t_list *temp;printf("%s", ft_strnstr("", "", 0))

    printf("Testing ft_lstnew:\n");
    if (!(list = ft_lstnew("AyyLmaooo")))
        ko_print("Function return NULL.");
    else
        ok_print();
    free(list);

    if ((list = ft_lstnew(NULL))->content)
        ko_print("Function return content.");
    else
        ok_print();
    free(list);

    if (!(list = ft_lstnew("ez")))
        ko_print("Function return NULL.");
    else if (list->next)
        ko_print("Next isn't null.");
    else
        ok_print();

    if (!(temp = ft_lstnew("ezzzzz")))
        ko_print("Function return NULL.");
    else
        if (list == temp)
            ko_print("Function must allocate a new memory space.");
        else
            ok_print();
    free(temp);
    free(list);
	return (function_ko);
}

char ft_lstadd_front_test(void)
{
    t_list *temp;
    t_list *list;
    t_list *elem;

    printf("Testing ft_lstadd_front:\n");
	
    list = ft_lstnew("Coucou");
    temp = list;
    elem = ft_lstnew("hi");
    ft_lstadd_front(&list, elem);
    if (list != elem)
        ko_print("Function didn't changed the original list adress.");
    else if (list->next != temp)
        ko_print("Function didn't add the elem to the beginning.");
    else
        ok_print();
    free(temp);
    free(elem);
	return (function_ko);
}

void ft_lstadd_front_protected(void)
{
	t_list	*list;
    t_list	*elem;
	
	list = ft_lstnew("Coucou");
	elem = ft_lstnew("hi");
	
    ft_lstadd_front(NULL, NULL);
    ft_lstadd_front(&list, NULL);
    ft_lstadd_front(NULL, elem);
    free(list);
    free(elem);
    printf("\tft_lstadd_front: \033[32mprotected\033[0m\n");
}

char ft_lstsize_test(void)
{
	t_list	*list[4];
	
    printf("Testing ft_lstsize:\n");

	list[0] = ft_lstnew("le strlen des lists kek");
	list[1] = ft_lstnew("22:13");
	list[2] = ft_lstnew("not ok");
	list[3] = ft_lstnew("???????????????????????????????fail");
	
	list[0]->next = list[1];
	list[1]->next = list[2];
	list[2]->next = list[3];
	list[3]->next = NULL;
	
	if (ft_lstsize(list[0]) != 4)
		ko_print("Didn't work with a list of 4 elem.");
	else
		ok_print();
	
	if (ft_lstsize(list[1]) != 3)
		ko_print("Didn't work with a list of 3 elem.");
	else
		ok_print();
	
	if (ft_lstsize(list[2]) != 2)
		ko_print("Didn't work with a list of 2 elem.");
	else
		ok_print();
	
	if (ft_lstsize(list[3]) != 1)
		ko_print("Didn't work with a list of 1 elem.");
	else
		ok_print();
	
	free(list[0]);
	free(list[1]);
	free(list[2]);
	free(list[3]);
	
	return (function_ko);
}

void ft_lstsize_protected(void)
{
	int res;
	
	if ((res = ft_lstsize(NULL)) != 0)
	{
		printf("\tft_lstsize: \033[31mreturn weird result: %i (retesting...).\033[0m\n", res);
		good_game = 0;
		return ;
	}
	
	if ((res = ft_lstsize(NULL)) != 0)
	{
		printf("\tft_lstsize: \033[31mreturn weird result: %i (retesting...).\033[0m\n", res);
		good_game = 0;
		return ;
	}
	
	if ((res = ft_lstsize(NULL)) != 0)
	{
		printf("\tft_lstsize: \033[31mreturn weird result: %i.\033[0m\n", res);
		good_game = 0;
		return ;
	}
	else
		printf("\tft_lstsize: \033[32mprotected\033[0m\n");
}

char ft_lstlast_test(void)
{
	t_list	*list[4];
	
    printf("Testing ft_lstlast:\n");

	list[0] = ft_lstnew("meh");
	list[1] = ft_lstnew("22:44");
	list[2] = ft_lstnew("not ok");
	list[3] = ft_lstnew("???????????????????????????????fail");
	
	list[0]->next = list[1];
	list[1]->next = list[2];
	list[2]->next = list[3];
	list[3]->next = NULL;
	
	if (ft_lstlast(list[0]) != list[3])
		ko_print("Didn't work with a list of 4 elem.");
	else
		ok_print();
	
	if (ft_lstlast(list[1]) != list[3])
		ko_print("Didn't work with a list of 3 elem.");
	else
		ok_print();
	
	if (ft_lstlast(list[2]) != list[3])
		ko_print("Didn't work with a list of 2 elem.");
	else
		ok_print();
	
	if (ft_lstlast(list[3]) != list[3])
		ko_print("Didn't work with a list of 1 elem.");
	else
		ok_print();
	
	free(list[0]);
	free(list[1]);
	free(list[2]);
	free(list[3]);
	
	return (function_ko);
}

void ft_lstlast_protected(void)
{
	if (ft_lstlast(NULL) != NULL)
	{
		printf("\tft_lstlast: \033[31mreturn weird result (retesting...).\033[0m\n");
		good_game = 0;
		return ;
	}
	
	if (ft_lstlast(NULL) != NULL)
	{
		printf("\tft_lstlast: \033[31mreturn weird result (retesting...).\033[0m\n");
		good_game = 0;
		return ;
	}
	
	if (ft_lstlast(NULL) != NULL)
	{
		printf("\tft_lstlast: \033[31mreturn weird result.\033[0m\n");
		good_game = 0;
		return ;
	}
	else
		printf("\tft_lstlast: \033[32mprotected\033[0m\n");
}

char ft_lstadd_back_test(void)
{
	t_list	*list[4];
	t_list	*tmp;
	
    printf("Testing ft_lstadd_back:\n");
	
	list[0] = ft_lstnew("meh");
	list[1] = ft_lstnew("22:44");
	list[2] = ft_lstnew("not ok");
	list[3] = ft_lstnew("???????????????????????????????fail");
	
	list[0]->next = NULL;
	list[1]->next = NULL;
	list[2]->next = NULL;
	list[3]->next = NULL;
	
	tmp = list[0];
	ft_lstadd_back(&tmp, list[1]);
	if (list[0] != tmp)
		ko_print("alst have been modified.");
	else if (tmp->next != list[1])
		ko_print("elem is not at the end of the list.");
	else if (list[1]->next != NULL)
		ko_print("list last element isn't null.");
	else
		ok_print();
	
	tmp = list[0];
	ft_lstadd_back(&tmp, list[2]);
	if (list[0] != tmp)
		ko_print("alst have been modified.");
	else if (tmp->next != list[1] || list[1]->next != list[2])
		ko_print("elem are not in the correct order of the list.");
	else if (list[2]->next != NULL)
		ko_print("list last element isn't null.");
	else
		ok_print();
	
	tmp = list[0];
	ft_lstadd_back(&tmp, list[3]);
	if (list[0] != tmp)
		ko_print("alst have been modified.");
	else if (tmp->next != list[1] || list[1]->next != list[2] || list[2]->next != list[3])
		ko_print("elem are not in the correct order of the list.");
	else if (list[3]->next != NULL)
		ko_print("list last element isn't null.");
	else
		ok_print();
	
	free(list[0]);
	free(list[1]);
	free(list[2]);
	free(list[3]);
	
	return (function_ko);
}

void ft_lstadd_back_protected(void)
{
	t_list	*elem;
	t_list	*saved;
	
	elem = ft_lstnew("topkek");
	saved = elem;
	
	ft_lstadd_back(NULL, NULL);
	ft_lstadd_back(NULL, elem);
	ft_lstadd_back(&elem, NULL);
	
	if (saved != elem)
		printf("\tft_lstadd_back: \033[31mnot protected.\033[0m\n");
	else
		printf("\tft_lstadd_back: \033[32mprotected\033[0m\n");
	free(elem);
}

int ft_lstdelone_freed = 0;

void ft_lstdelone_free(void *content)
{
	free(content);
	ft_lstdelone_freed = 1;
}

char ft_lstdelone_test(void)
{
	t_list	*elem;

	printf("Testing ft_lstdelone:\n");
	
	elem = ft_lstnew(malloc(1337));
	
	ft_lstdelone(elem, ft_lstdelone_free);
	if (!ft_lstdelone_freed)
		ko_print("The content is not deleted.");
	else
		ok_print();
	unknown_print("Can't check if the lst memory is freed.");
	return (function_ko);
}

void ft_lstdelone_protected(void)
{
	t_list	*elem;
	
	elem = ft_lstnew("lol");
	ft_lstdelone(elem, NULL);
	free(elem);

	elem = ft_lstnew(malloc(1337));
	ft_lstdelone(NULL, ft_lstdelone_free);
	free(elem);

	ft_lstdelone(NULL, NULL);
	printf("\tft_lstdelone: \033[32mprotected\033[0m\n");
}

char ft_lstclear_test(void)
{
	t_list	*elem;

	printf("Testing ft_lstclear:\n");
	
	elem = ft_lstnew(malloc(1337));
	ft_lstclear(&elem, ft_lstdelone_free);

	if (!ft_lstdelone_freed)
		ko_print("The content is not deleted.");
	else if (elem)
		ko_print("The list need to be NULL at the end.");
	else
		ok_print();

	unknown_print("Can't check if the lst memory is freed.");
	return (function_ko);
}

void ft_lstclear_protected(void)
{
	t_list	*elem;
	
	elem = ft_lstnew("lol");
	ft_lstclear(&elem, NULL);
	free(elem);

	ft_lstclear(NULL, NULL);
	printf("\tft_lstclear: \033[32mprotected\033[0m\n");
}

int ft_lstiter_iteration_count = 0;

void ft_lstiter_iteration(void *content)
{
	ft_lstiter_iteration_count++;
}

char ft_lstiter_test(void)
{
	t_list	*elem[4];

	printf("Testing ft_lstiter:\n");

	elem[0] = ft_lstnew("a");
	elem[1] = ft_lstnew("b");
	elem[2] = ft_lstnew("c");
	elem[3] = ft_lstnew("d");
	
	elem[0]->next = elem[1];
	elem[1]->next = elem[2];
	elem[2]->next = elem[3];
	elem[3]->next = NULL;

	ft_lstiter(elem[0], ft_lstiter_iteration);

	if (ft_lstiter_iteration_count < 4)
		ko_print("Not all the iteration were made.");
	else if (ft_lstiter_iteration_count > 4)
		ko_print("Too much iteration were made.");
	else
		ok_print();

	free(elem[0]);
	free(elem[1]);
	free(elem[2]);
	free(elem[3]);
	return (function_ko);
}

void ft_lstiter_protected(void)
{
	t_list	*elem;
	
	elem = ft_lstnew("lol");
	ft_lstiter(elem, NULL);
	free(elem);

	ft_lstiter(NULL, NULL);
	printf("\tft_lstiter: \033[32mprotected\033[0m\n");
}

void *ft_lstmap_f(void *content)
{
	return (content);
}

char ft_lstmap_test(void)
{
	t_list	*elem[4];
	t_list	*newelem;

	printf("Testing ft_lstmap:\n");

	elem[0] = ft_lstnew("a");
	elem[1] = ft_lstnew("b");
	elem[2] = ft_lstnew("c");
	elem[3] = ft_lstnew("d");
	
	elem[0]->next = elem[1];
	elem[1]->next = elem[2];
	elem[2]->next = elem[3];
	elem[3]->next = NULL;

	if (!(newelem = ft_lstmap(elem[0], ft_lstmap_f)))
		ko_print("No list sent with a list of 4 elements.");
	else if (newelem->content != elem[0]->content ||
			(newelem->next)->content != elem[1]->content ||
			((newelem->next)->next)->content != elem[2]->content ||
			(((newelem->next)->next)->next)->content != elem[3]->content)
		ko_print("The list content is not the result of f.");
	else if (newelem == elem[0])
		ko_print("The old list was modified.");
	else
		ok_print();

	free(elem[0]);
	free(elem[1]);
	free(elem[2]);
	free(elem[3]);
	free((((newelem->next)->next)->next));
	free((newelem->next)->next);
	free(newelem->next);
	free(newelem);
	return (function_ko);
}

void ft_lstmap_protected(void)
{
	t_list	*elem;

	elem = ft_lstnew("lol");
	if (ft_lstmap(elem, NULL) != NULL)
	{
		printf("\tft_lstmap: \033[31mreturn weird result (retesting...).\033[0m\n");
		good_game = 0;
		return ;
	}
	free(elem);

	if (ft_lstmap(NULL, NULL) != NULL)
	{
		printf("\tft_lstmap: \033[31mreturn weird result (retesting...).\033[0m\n");
		good_game = 0;
		return ;
	}

	if (ft_lstmap(NULL, NULL) != NULL)
	{
		printf("\tft_lstmap: \033[31mreturn weird result (retesting...).\033[0m\n");
		good_game = 0;
		return ;
	}

	if (ft_lstmap(NULL, NULL) != NULL)
	{
		printf("\tft_lstmap: \033[31mreturn weird result.\033[0m\n");
		good_game = 0;
		return ;
	}
	else
	{
		printf("\tft_lstmap: \033[32mprotected\033[0m\n");
	}
	
}
*/
void del(void *content)
{
    (void) content;
}

int main()
{
puts("* ft_lstclear");
t_list *list5256979689 = NULL;
ft_putendl_fd("Test finished 1", 1);
ft_lstadd_back(&list5256979689, ft_lstnew(""));
ft_lstclear(&list5256979689, NULL);
t_list *list678028879 = NULL;
ft_lstadd_back(&list678028879, NULL);
ft_putendl_fd("Test finished 2", 1);
ft_lstclear(&list678028879, &del);
t_list *list294722143 = NULL;
ft_lstadd_back(&list294722143, NULL);
ft_lstadd_back(&list294722143, ft_lstnew(NULL));
ft_lstadd_back(&list294722143, NULL);
ft_putendl_fd("Test finished 3", 1);
ft_lstclear(&list294722143, NULL);
t_list *list8252368809 = NULL;
ft_lstadd_back(&list8252368809, NULL);
ft_putendl_fd("Test finished 4", 1);
ft_lstclear(&list8252368809, NULL);
t_list *list5196596887 = ft_lstnew("GZjFsfEKKn2e0hAFq21i4wingChrNC9OusYzimlt55gwNmSyd3slpMh0He0WISnZl");
ft_lstadd_back(&list5196596887, ft_lstnew(""));
ft_lstadd_back(&list5196596887, ft_lstnew("K9plJ9IfV0WNozhAyM8QrvAxNNhbCWMouy1LnnI5e4Y3heNfMT6RLkE4cTVfB4nlTVIN9cSXxx8Ar"));
ft_putendl_fd("Test finished 5", 1);
ft_lstclear(&list5196596887, &del);
t_list *list7425809589 = NULL;
ft_lstadd_back(&list7425809589, NULL);
ft_lstadd_back(&list7425809589, NULL);
ft_lstadd_back(&list7425809589, ft_lstnew("MnwKeJF6VihyM06ZtayNTbGg9e2N9PDe3Op9v582DWzx8vNAnI6J37eUxxxV71ANA9g4m9WdV"));
ft_putendl_fd("Test finished 6", 1);
ft_lstclear(&list7425809589, NULL);
t_list *list9223582971 = NULL;
ft_putendl_fd("Test finished 7", 1);
ft_lstclear(&list9223582971, &del);
t_list *list10459082 = ft_lstnew("");
ft_lstadd_back(&list10459082, NULL);
ft_lstadd_back(&list10459082, ft_lstnew("nDPgBR8vNIO3r0pOvDGNRy6alGPpA"));
ft_lstadd_back(&list10459082, NULL);
ft_putendl_fd("Test finished 8", 1);
ft_lstclear(&list10459082, &del);
t_list *list8747047513 = NULL;
ft_lstadd_back(&list8747047513, NULL);
ft_putendl_fd("Test finished 9", 1);
ft_lstclear(&list8747047513, &del);
t_list *list1355938316 = NULL;
ft_lstadd_back(&list1355938316, ft_lstnew("UCzMwIMWqvwKKG19OtTrczhNxg67GQA"));
ft_lstadd_back(&list1355938316, NULL);
ft_lstadd_back(&list1355938316, NULL);
ft_putendl_fd("Test finished 10", 1);
ft_lstclear(&list1355938316, &del);
t_list *list2271954110 = NULL;
ft_lstadd_back(&list2271954110, ft_lstnew(""));
ft_putendl_fd("Test finished 11", 1);
ft_lstclear(&list2271954110, &del);
t_list *list6952049515 = NULL;
ft_lstadd_back(&list6952049515, ft_lstnew(NULL));
ft_putendl_fd("Test finished 12", 1);
ft_lstclear(&list6952049515, NULL);
t_list *list5667260527 = NULL;
ft_lstadd_back(&list5667260527, NULL);
ft_lstadd_back(&list5667260527, ft_lstnew("qKDJ3G4n4VllP"));
ft_putendl_fd("Test finished 13", 1);
ft_lstclear(&list5667260527, &del);
t_list *list176588463 = NULL;
ft_lstadd_back(&list176588463, ft_lstnew(NULL));
ft_putendl_fd("Test finished 14", 1);
ft_lstclear(&list176588463, NULL);
t_list *list3978854246 = ft_lstnew("iEkIGOyOxb1lJ0pyzE9yAiroAXGalbkVfcdGRjpDQGQjBxYEIe2fIoc7KL");
ft_lstadd_back(&list3978854246, ft_lstnew(NULL));
ft_putendl_fd("Test finished 15", 1);
ft_lstclear(&list3978854246, NULL);
t_list *list3042094199 = ft_lstnew(NULL);
ft_putendl_fd("Test finished 16", 1);
ft_lstclear(&list3042094199, NULL);
t_list *list8795699010 = ft_lstnew("B7fTjJg65WHLn3H0R0pPxyIarMJi6k9tBS6nNilu0jCICZmqMn2a4uDO12GUPhEl1eLz0");
ft_lstadd_back(&list8795699010, ft_lstnew("wysk1lqkIDXbsq2zJrZ1tIGo840ajJqf5x5ENHJ9q6fHsRJlritWsFsJUj3yYwOYcXon5jk4hwHFuVTans"));
ft_putendl_fd("Test finished 17", 1);
ft_lstclear(&list8795699010, &del);
t_list *list9755361466 = NULL;
ft_lstadd_back(&list9755361466, ft_lstnew("65NiRiJ6Vu9adW7FBTlyae21ZXgQMD2H48rMBHDxYNlvVRv7NIWYUo"));
ft_lstadd_back(&list9755361466, NULL);
ft_putendl_fd("Test finished 18", 1);
ft_lstclear(&list9755361466, NULL);
t_list *list8138235925 = NULL;
ft_lstadd_back(&list8138235925, NULL);
ft_lstadd_back(&list8138235925, NULL);
ft_lstadd_back(&list8138235925, ft_lstnew(NULL));
ft_putendl_fd("Test finished 19", 1);
ft_lstclear(&list8138235925, &del);
t_list *list809324176 = NULL;
ft_lstadd_back(&list809324176, NULL);
ft_putendl_fd("Test finished 20", 1);
ft_lstclear(&list809324176, &del);
t_list *list9432899880 = ft_lstnew("N1QU7dikwJoy3LQm1f0JNDFG51d4B7rW4");
ft_lstadd_back(&list9432899880, ft_lstnew(""));
ft_putendl_fd("Test finished 21", 1);
ft_lstclear(&list9432899880, &del);
t_list *list1149441511 = ft_lstnew(NULL);
ft_lstadd_back(&list1149441511, NULL);
ft_putendl_fd("Test finished 22", 1);
ft_lstclear(&list1149441511, NULL);
t_list *list1396928975 = NULL;
ft_lstadd_back(&list1396928975, NULL);
ft_putendl_fd("Test finished 23", 1);
ft_lstclear(&list1396928975, &del);
t_list *list9775622464 = ft_lstnew("");
ft_lstadd_back(&list9775622464, ft_lstnew("EU8Gnnq9682sb4dl9O6RILGRdEdkw63fg4kVqOPaCfaRUqJQaNHgw84cd"));
ft_lstadd_back(&list9775622464, NULL);
ft_lstadd_back(&list9775622464, NULL);
ft_putendl_fd("Test finished 24", 1);
ft_lstclear(&list9775622464, NULL);
t_list *list7078168528 = NULL;
ft_lstadd_back(&list7078168528, ft_lstnew(NULL));
ft_putendl_fd("Test finished 25", 1);
ft_lstclear(&list7078168528, NULL);
t_list *list5248055815 = ft_lstnew("kVXFYYbb3o0M6vGhMpymFEpFAmyvVIGJY6oA1acds0GCY4");
ft_putendl_fd("Test finished 26", 1);
ft_lstclear(&list5248055815, &del);
t_list *list7939025150 = ft_lstnew("mc5DT4");
ft_lstadd_back(&list7939025150, ft_lstnew(""));
ft_lstadd_back(&list7939025150, ft_lstnew("VWGHohLBBcMkYVF1uH8jILJAv1GZT0MNdzOpw8lfVxw7RX1vcfhvS4ZBLJKMElvxurGy8K0NSFOm5L6iHl8yYEyFFkyVHT0"));
ft_lstadd_back(&list7939025150, ft_lstnew(NULL));
ft_putendl_fd("Test finished 27", 1);
ft_lstclear(&list7939025150, NULL);
t_list *list1219474575 = ft_lstnew("H8rlZHSC");
ft_lstadd_back(&list1219474575, NULL);
ft_lstadd_back(&list1219474575, ft_lstnew(NULL));
ft_putendl_fd("Test finished 28", 1);
ft_lstclear(&list1219474575, &del);
t_list *list4479993997 = NULL;
ft_lstadd_back(&list4479993997, ft_lstnew(NULL));
ft_lstadd_back(&list4479993997, ft_lstnew("psrjt1Hrbsj0DV380jHOKdNTmH8VnMzoH6IImmUUEiBxPCqLeV7qj4NKQ8NU"));
ft_putendl_fd("Test finished 29", 1);
ft_lstclear(&list4479993997, &del);
t_list *list357352689 = ft_lstnew("2t2FppobUgQv3ForbEcyGSmrHbtb2wHAdI4mEdKKkb0LlC4yspDA");
ft_lstadd_back(&list357352689, ft_lstnew(""));
ft_lstadd_back(&list357352689, NULL);
ft_lstadd_back(&list357352689, NULL);
ft_putendl_fd("Test finished 30", 1);
ft_lstclear(&list357352689, &del);

}
