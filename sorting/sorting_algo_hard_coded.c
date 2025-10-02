/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_hard_coded.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:12:36 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 17:03:57 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_three(t_node **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->data > (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
		s(a, "sa");
	else if ((*a)->data > (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		s(a, "sa");
		rr(a, "rra");
	}
	else if ((*a)->data > (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
		r(a, "ra");
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
		rr(a, "rra");
	else if ((*a)->data < (*a)->next->data
		&& (*a)->next->data > (*a)->next->next->data)
	{
		s(a, "sa");
		r(a, "ra");
	}
}

void	sort_two(t_node **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->data > (*a)->next->data)
		s(a, "sa");
}

int	is_sorted(t_node *a)
{
	t_node	*current;

	if (!a || !a->next)
		return (1);
	current = a;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_swap(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	sort_indices(a);
	if (list_counter(*a) == 4)
		sort_four(a, b);
	else if (list_counter(*a) == 3)
		sort_three(a);
	else if (list_counter(*a) == 2)
		sort_two(a);
}
