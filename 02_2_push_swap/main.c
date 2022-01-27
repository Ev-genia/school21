#include "push_swap.h"

#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->val = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return ((t_list *)0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (*lst)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}

int	main()
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(5);
	ft_lstadd_back(&a, ft_lstnew(10));
	ft_lstadd_back(&a, ft_lstnew(15));
	printf("---------------------\n");
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
	/*swap(&a);
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
	printf("---------------------\n");
	b = ft_lstnew(1);
	ft_lstadd_back(&b, ft_lstnew(3));
	ft_lstadd_back(&b, ft_lstnew(9));
	printf("%d, %d, %d\n", b->val, b->next->val, b->next->next->val);
	push(&a, &b);
	printf("%d, %d\n", a->val, a->next->val);
	printf("%d, %d, %d, %d\n", b->val, b->next->val, b->next->next->val, b->next->next->next->val);
	printf("---------------------\n");
	rotate(&a);
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
	printf("---------------------\n");*/
	reverse(&a);
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
	printf("---------------------\n");
}