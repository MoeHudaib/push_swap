/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:04:52 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 15:29:37 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*search_index(t_node *head, int index)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->index = index)
			return (current);
	}
    return (NULL);
}

void	sort(t_node **a, t_node **b)
{
	int		len;
    t_node	*node;

	len = list_counter(*a);
	sort_indices(a);
	calc_cost(*a);
    node = search_index(*a, len - 1);
}

// 5 4 6 8 9
// 0 1 2