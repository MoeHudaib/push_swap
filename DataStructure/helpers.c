/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:03:26 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 17:14:57 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*last(t_node *head)
{
	t_node	*current;

	if (!head)
		return (NULL);
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	add_back(t_node **head, t_node *new)
{
	t_node	*last_node;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last_node = last(*head);
	last_node->next = new;
}

void	print_list(t_node *head)
{
	t_node	*current;

	if (!head)
	{
		ft_printf("Error: Cannot print an empty list.\n");
		return ;
	}
	current = head;
	while (current)
	{
		ft_printf("%d", current->data, current->index);
		// if (current->cost)
		// 	ft_printf("UP cost: %d Down cost %d",
				//current->cost->up, current->cost->down);
		if (current->next)
			ft_printf(" -> ");
		current = current->next;
	}
	ft_printf("\n");
}

t_node	*push(t_node **head, t_node *new_node)
{
	if (!new_node)
	{
		ft_printf("Error: Cannot push.\n");
		return (NULL);
	}
	new_node->next = *head;
	*head = new_node;
	return (*head);
}

int	list_counter(t_node *head)
{
	int		counter;
	t_node	*current;

	if (!head)
		return (0);
	current = head;
	counter = 0;
	while (current)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}
