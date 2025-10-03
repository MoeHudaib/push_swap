/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:35:49 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:20:48 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	sort_four(t_node **a, t_node **b)
{
	t_node	*node;
	int		len;

	if (!a || !*a || is_sorted(*a))
		return ;
	node = *a;
	len = 0;
	while (node && node->index != 0)
	{
		node = node->next;
		len++;
	}
	if (len <= list_counter(*a) / 2)
		while ((*a)->index != 0)
			r(a, "ra");
	else
		while ((*a)->index != 0)
			rr(a, "rra");
	p(b, a, "pb");
	sort_three(a);
	p(a, b, "pa");
}

static void	push_index(t_node **a, t_node **b, int target_index)
{
	int		len;
	t_node	*node;

	len = 0;
	node = *a;
	while (node && node->index != target_index)
	{
		node = node->next;
		len++;
	}
	if (len <= list_counter(*a) / 2)
		while ((*a)->index != target_index)
			r(a, "ra");
	else
		while ((*a)->index != target_index)
			rr(a, "rra");
	p(b, a, "pb");
}

void	sort_five(t_node **a, t_node **b)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	push_index(a, b, 0);
	push_index(a, b, 1);
	sort_three(a);
	p(a, b, "pa");
	p(a, b, "pa");
}
