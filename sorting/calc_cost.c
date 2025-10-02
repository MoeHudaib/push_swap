/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:49:59 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 15:20:41 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	search_up(t_node *head, int data)
{
	t_node	*current;
	int		up_steps;

	if (!head)
		return (0);
	current = head;
	up_steps = 0;
	while (current)
	{
		++up_steps;
		if (current->data == data)
			return (up_steps);
		current = current->next;
	}
	return (NOT_FOUND);
}

int	search_down(t_node *head, int data)
{
	t_node	*current;
	int		index;
	int		size;

	if (!head)
		return (0);
	size = list_counter(head);
	index = 0;
	current = head;
	while (current)
	{
		if (current->data == data)
			break ;
		current = current->next;
		index++;
	}
	if (!current)
		return (0);
	return (size - index);
}

static void	calc_cost_single(t_node *head, t_node *current)
{
	if (!head || !current)
		return ;
	if (!current->cost)
		current->cost = malloc(sizeof(t_cost));
	current->cost->up = search_up(head, current->data);
	current->cost->down = search_down(head, current->data);
}

void	calc_cost(t_node *head)
{
	t_node	*current;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		calc_cost_single(head, current);
		current = current->next;
	}
}
