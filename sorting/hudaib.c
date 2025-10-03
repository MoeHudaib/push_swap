/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hudaib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:34:40 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:21:14 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	init(t_node **current, t_node **max, t_node *b)
{
	*current = b;
	*max = b;
	while (*current)
	{
		if ((*current)->index > (*max)->index)
			*max = *current;
		*current = (*current)->next;
	}
}

static void	init1(t_node **current, t_node *b, int *pos, int *size)
{
	*current = b;
	*pos = 0;
	*size = list_counter(b);
}

void	bring_max_top(t_node **b)
{
	t_node	*current;
	t_node	*max;
	int		pos;
	int		size;

	if (!b || !*b)
		return ;
	max = NULL;
	current = NULL;
	init(&current, &max, *b);
	init1(&current, *b, &pos, &size);
	while (current && current->data != max->data)
	{
		current = current->next;
		pos++;
	}
	if (pos <= size / 2)
		while ((*b)->data != max->data)
			r(b, "rb");
	else
		while ((*b)->data != max->data)
			rr(b, "rrb");
}

static void	reinsert_b_to_a(t_node **a, t_node **b)
{
	if (!b || !*b)
		return ;
	while (*b)
	{
		bring_max_top(b);
		p(a, b, "pa");
	}
}

void	hudaib(t_node **a, t_node **b)
{
	t_node	***spl;
	int		i;

	if (!a || !*a || is_sorted(*a))
		return ;
	spl = split(*a);
	if (!spl)
		return ;
	i = 0;
	while (spl[i])
	{
		push_chunk_to_b(a, b, spl[i]);
		i++;
	}
	reinsert_b_to_a(a, b);
	free_split(spl);
	print_list(*a);
}
