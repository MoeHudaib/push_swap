/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_hard_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:49:07 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 17:18:54 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_four(t_node **a, t_node **b)
{
	int		len;
	t_node	*node;

	if (is_sorted(*a))
		return ;
	len = list_counter(*a);
	sort_indices(a);
	calc_cost(*a);
	node = search_index(*a, 3);
    len = -1;
	if (decide_which(node) == R)
	{
		while (++len < node->cost->up)
			r(a, "ra");
	}
	else
	{
		while (++len < node->cost->down)
			rr(a, "rr");
	}
    //p(a, b, "pb");
    print_list(*a);
    print_list(*b);
    //sort_three(a);
    //p(a, b, "pa");
    //r(a, "ra");
    print_list(*a);

}
