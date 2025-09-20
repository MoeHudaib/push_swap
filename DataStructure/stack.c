/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:52:57 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/20 22:53:53 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->index = 0;
	return (new_node);
}

t_node	*push(t_node **head, int data)
{
	t_node	*new_node;

	if (!head || !*head)
	{
		ft_printf("Error: Cannot push to an empty list.\n");
		return (NULL);
	}
	new_node = create_node(data);
	if (!new_node)
	{
		ft_printf("Error: Memory Allocation Failure.\n");
		return (NULL);
	}
	new_node->next = *head;
	*head = new_node;
	return (*head);
}

t_node	*pop(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

	if (!head || !*head)
	{
		ft_printf("Error: Cannot pop from an empty list.\n");
		return (NULL);
	}
	current = *head;
	tmp = (*head)->next;
	current->next = NULL;
	*head = tmp;
	return (current);
}

void	delete_list(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

	if (!head || !*head)
	{
		ft_printf("Error: Cannot delete an empty list.\n");
		return ;
	}
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = NULL;
	ft_printf("List Cleared Successfully.\n");
}
