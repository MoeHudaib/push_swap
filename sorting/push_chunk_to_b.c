/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 02:05:32 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:01:47 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	get_pos(t_node *head, int index)
{
	int		pos;
	t_node	*cur;

	cur = head;
	pos = 0;
	while (cur)
	{
		if (cur->index == index)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

static int	decide_rotation(t_node *head, int index)
{
	int	pos;
	int	size;

	pos = get_pos(head, index);
	size = list_counter(head);
	if (pos <= size / 2)
		return (1);
	return (0);
}

static void	rotate_both(t_node **a, t_node **b, int rot_a, int rot_b)
{
	while (rot_a && rot_b)
	{
		r(a, NULL);
		r(b, "rr");
		rot_a--;
		rot_b--;
	}
	while (rot_a--)
		r(a, "ra");
	while (rot_b--)
		r(b, "rb");
}

void	push_chunk_to_b(t_node **a, t_node **b, t_node **chunk)
{
	int		i;
	int		rot_a;
	int		rot_b;
	t_node	*top;

	i = 0;
	while (chunk[i])
	{
		rot_a = 0;
		rot_b = 0;
		if (!*a)
			break ;
		if (decide_rotation(*a, chunk[i]->index))
			rot_a = get_pos(*a, chunk[i]->index);
		else
			rot_a = list_counter(*a) - get_pos(*a, chunk[i]->index);
		if (*b && (*b)->index > chunk[0]->index + i / 2)
			rot_b = 1;
		rotate_both(a, b, rot_a, rot_b);
		top = *a;
		p(b, a, "pb");
		if (top->index > chunk[0]->index + i / 2)
			r(b, "rb");
		i++;
	}
}
