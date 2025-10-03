/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:52:52 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:34:35 by mohammad         ###   ########.fr       */
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
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = pop(head);
	second = pop(head);
	*head = push(head, first);
	*head = push(head, second);
	if (msg)
		ft_printf("%s\n", msg);
}

void	p(t_node **to, t_node **from, char *msg)
{
	t_node	*node;

	if (!to || !from || !*from)
		return ;
	node = pop(from);
	*to = push(to, node);
	if (msg)
		ft_printf("%s\n", msg);
}

void	r(t_node **head, char *msg)
{
	t_node	*first;

	if (!head || !*head || !(*head)->next)
		return ;
	first = pop(head);
	add_back(head, first);
	if (msg)
		ft_printf("%s\n", msg);
}

void	rr(t_node **head, char *msg)
{
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = pop_last(head);
	*head = push(head, last);
	if (msg)
		ft_printf("%s\n", msg);
}
