// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
    struct s_list   *next;
    void *data;
}   t_list;

t_list  *create_node(void *data)
{
    t_list *head;

    head = malloc(sizeof(t_list));
    if (!head)
        return (NULL);
    head->data = strdup((char *)data);
    head->next = NULL;
    return (head);
}

void    add_front(t_list **head, void *data)
{
    t_list *new_ = create_node(data);
    if (!new_)
        return ;
    new_->next = *head;
    *head = new_;
    return ;
}

void    add_back(t_list **head, void *data)
{
    t_list  *current;
    if (!head || !data || !*head)
        return ;
    t_list  *new_ = create_node(data);
    if (!new_)
        return ;

    current = *head;
    while (current->next)
        current = current->next;
    current->next = new_;
    return ;
}

void    del(void *data)
{
    free(data);
}

int     cmp(void *data1, void *data2)
{
    if (strcmp((char *)data1, (char *)data2) == 0)
        return (0);
    return (1);
}

void    del_node(t_list **head, void *data, void (*del)(void*), int (*cmp)(void*, void*))
{
    if (!head || !*head || !data)
        return ;
    t_list  *current;
    t_list  *prev;

    current = *head;
    prev = NULL;
    while (current)
    {
        if (cmp(current->data, data) == 0)
        {
            if (prev)
                prev ->next = current->next;
            else
                *head = current->next;
            del(current->data);
            free(current);
            return ;
        }
        prev = current;
        current = current->next;
    }
}
// 1 -> 3
// p    c
void    print_list(t_list *head)
{
    t_list  *current;
    current = head;
    while (current)
    {
        printf("%s ", (char *)current->data);
        current = current->next;
    }
    printf("\n");
}

void	del_list(t_list **head, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		del(tmp->data);
		free(tmp);
		tmp = NULL;
	}
}

int main() 
{
    t_list *head = create_node("Mohammad");
    add_front(&head, "Hudaib");
    add_back(&head, "Yaser");
    print_list(head);
    del_node(&head, "Hudaib", del, cmp);
    print_list(head);
    add_back(&head, "Hudaib");
    print_list(head);
    del_list(&head, del);
    return 0;
}
