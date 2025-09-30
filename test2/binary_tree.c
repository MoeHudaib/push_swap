#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_btree
{
	void	*data;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

t_btree	*create_node(void *data)
{
	if (!data)
		return (NULL);
	t_btree	*node;
	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_btree	*add_left(t_btree **root, void *data)
{
	if (!head || !*head || data)
		return (NULL);
	t_btree *node;
	node = create_node(data);
	(*root)->left = node;
	return (*head);
}

t_btree *add_right(t_btree **root, void *data)
{       
        if (!head || !*head || data)
                return (NULL);
        t_btree *node;
        node = create_node(data);
        (*root)->right = node;
	return (*head);
}

int	str_cmp(void *data1, void *data2)
{
	if (strcmp((char *)data1, (char *)data2) >= 0)
		return (1);
	return (-1);
}

int     int_cmp(void *data1, void *data2)
{
        if (*data1 >= *data2)
                return (1);
        return (-1);
}


t_btree *add(t_btree **root, void *data, int (*cmp)(void*, void*))
{
	t_btree	*current = *root;
	int	right = 0;
	int	left = 0;
	while (current)
	{
		if (current->left == NULL)
		{
			current = add_left(&current, data);
			left = 1;
			break ;
		}
		else if (current->right == NULL)
                {
                        current = add_right(&current, data);
                        right = 1;
                        break ;
                }
		current = current->left;
	}
}
