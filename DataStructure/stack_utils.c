/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:52:52 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/02 17:01:40 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*pop_last(t_node **head)
{
	t_node	*current;
	t_node	*prev;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
	{
		current = *head;
		*head = NULL;
		return (current);
	}
	prev = *head;
	current = (*head)->next;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	return (current);
}

void	s(t_node **head, char *msg)
{
	t_node	*second;
	t_node	*first;

	if (!head || !*head || list_counter(*head) == 1)
		return ;
	first = pop(head);
	second = pop(head);
	*head = push(head, first);
	*head = push(head, second);
	if (msg)
		ft_printf("%s\n", msg);
}

void	p(t_node **a_head, t_node **b_head, char *msg)
{
	t_node	*node;

	if (!a_head || !*a_head || !msg)
		return ;
	if (ft_strcmp(msg, "pa") == 0)
	{
		node = pop(b_head);
		*a_head = push(a_head, node);
		ft_printf("%s\n", msg);
	}
	else if (ft_strcmp(msg, "pb") == 0)
	{
		node = pop(a_head);
		if (!b_head || !*b_head)
			*b_head = node;
		else
			*b_head = push(b_head, node);
		ft_printf("%s\n", msg);
	}
	else
		ft_printf("Invalid call: %s", msg);
}

void	r(t_node **head, char *msg)
{
	t_node	*first;

	if (!head || !*head || list_counter(*head) == 1)
		return ;
	first = pop(head);
	add_back(head, first);
	if (msg)
		ft_printf("%s\n", msg);
}

void	rr(t_node **head, char *msg)
{
	t_node	*node;

	if (!head || !*head || list_counter(*head) == 1)
		return ;
	node = pop_last(head);
	*head = push(head, node);
	if (msg)
		ft_printf("%s\n", msg);
}
