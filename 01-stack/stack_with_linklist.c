# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}



void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// push
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// ACTION COMMAND 
void	push(t_list **stack, t_list *new)
{
	ft_lstadd_front(stack,new);
}

// void	pb(t_list **STACK_A, t_list **STACK_B)
// {
// 	if (*STACK_B == NULL)
// 		*STACK_B = STACK_A[0];
// 	else 
// 		ft_lstadd_front(STACK_B, STACK_A[0]);
// }

void sa(t_list **STACK_A)
{
	
}
void print_content(void *content) {
    printf("%s\n", (char*)content);
}
int main ()
{
	char *arr[4] = {"10","20","30","40"};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	t_list **STACK_A = (t_list **)malloc(sizeof(t_list));
	t_list **STACK_B = (t_list **)malloc(sizeof(t_list));

	
	for(i = 0; i < n; i++) {
		t_list *new = ft_lstnew(arr[i]);
		ft_lstadd_back(STACK_A,new);
	}

	// pb(STACK_A,STACK_B);
	ft_lstiter(*STACK_A, print_content);	
	// ft_lstiter(*STACK_B, print_content);	
}