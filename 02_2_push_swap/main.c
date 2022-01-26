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

	a = ft_lstnew(5);
	ft_lstadd_back(&a, ft_lstnew(10));
	ft_lstadd_back(&a, ft_lstnew(15));
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
	swap(&a);
	printf("%d, %d, %d\n", a->val, a->next->val, a->next->next->val);
}