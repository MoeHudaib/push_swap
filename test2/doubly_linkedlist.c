#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum e_datatype
{
	INT = 1,
	CHAR,
	STRING
}	t_type;

typedef struct s_doubly_linkedlist
{
        struct s_doubly_linkedlist *next;
        struct s_doubly_linkedlist *prev;
        void    *data;
}       t_doubly_linkedlist;

typedef t_doubly_linkedlist t_dlist;

t_dlist	*create_node(void *data)
{
	t_dlist	*node;

	if (!data)
		return (NULL);
	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = data; // it must be heap allocated !
	return (node);
}

t_dlist	*add_back(t_dlist **head, void *data)
{
	t_dlist	*node = create_node(data);
	if (!node)
		return (NULL);
	t_dlist	*current = *head;
	while (current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
	return (*head);
}

t_dlist	*add_front(t_dlist **head, void *data)
{
	if (!head || !*head || !data)
		return (NULL);
	t_dlist	*node = create_node(data);
	if (!node)
		return (NULL);
	node->next = *head;
	(*head)->prev = node;
	*head = node;
	return (*head);
}
// new -> <-0-> <-1-> <-2-> <-3-> <-4
// node     h

int	dlist_counter(t_dlist *head)
{
	int	counter = 0;
	if (!head)
		return (counter);
	t_dlist *current = head;
	while (current)
	{
		++counter;
		current = current->next;
	}
	return (counter);
}
// 0-> <-1-> <-new-> <-2-> <-3-> <-4
// 	 p    node     c
t_dlist *insert_at(t_dlist **head, void *data, int pose)
{
	if (!head || !*head || !data)
		return (NULL);
	if (pose < 0 || pose >= dlist_counter(*head))
		return (NULL);
	int	i = 0;
	t_dlist	*node = create_node(data);
	if (!node)
		return (NULL);
	t_dlist	*current = *head;
	t_dlist *prev = NULL;
	while (current && i < pose)
	{
		prev = current;
		current = current->next;
		i++;
	}
	prev->next = node;
	node->prev = prev;
	current->prev = node;
	node->next = current;
	return (*head);
}

// 0-> <-1-> <-2-> <-3-> <-4
//       p    node   c

int	cmp(void *data1, void *data2)
{
	if (strcmp((char *)data1, (char *)data2) == 0)
		return (0);
	return (1);
}

void	del(void *data)
{
	free(data);
}

void	del_node(t_dlist **head, void *data, void (*del)(void*), int (*cmp)(void*, void*))
{
	if (!head || !*head || !data || !del)
		return ;
	t_dlist	*current;
	t_dlist *tmp;
	t_dlist	*prev;
	
	current = *head;
	prev = NULL;
	tmp = NULL;
	while (current)
	{
		if (cmp(current->data, data) == 0)
		{
			if (prev && current->next)
			{
				tmp = current;
				current = current->next;
				prev->next = current;
				current->prev = prev;
				tmp->next =NULL;
				tmp->prev = NULL;
				del(tmp->data);
				free(tmp);
				return ;	
			}
			else if (!prev)
			{
				*head = current->next;
				tmp = current;
				(*head)->prev = NULL;
				tmp->next = NULL;
				del(tmp->data);
				free(tmp);
				return;
			}
			else if (current->next == NULL)
			{
				tmp = current;
				prev->next = NULL;
				tmp->prev = NULL;
				del(tmp->data);
				free(tmp);
				return ;
			}
				
		}
		prev = current;
		current = current->next;
	}
}

void	print_dlist(t_dlist *head)
{
	if (!head)
		return ;
	t_dlist	*current;
	current = head;
	t_dlist	*prev = NULL;
	while (current)
	{
		if (!prev)
			printf("NULL <- %s -> ",(char *)current->data);
		else if (prev || !current->next)
			printf("<- %s -> ", (char *)current->data);
		prev = current;
		current = current->next;
	}
	printf("NULL\n");
}

void	del_dlist(t_dlist **head, void (*del)(void*))
{
	if (!head || !*head || !del)
		return ;
	t_dlist	*current;
	t_dlist	*tmp;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		del(tmp->data);
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
		tmp = NULL;
	}
}

int	main()
{
	char *str = strdup("Mohammad");
	t_dlist	*head = create_node((void *)str);
	print_dlist(head);
	char *str1 = strdup("Yaser");
	head = add_back(&head, str1);
	print_dlist(head);
	char *str2 = strdup("Hudaib");
	head = add_front(&head, str2);
	print_dlist(head);
	del_node(&head, "Hudaib", del, cmp);
	print_dlist(head);
	char *str3 = strdup("Hudaib");
	head = add_back(&head, str3);
	print_dlist(head);
	del_dlist(&head, del);
}
