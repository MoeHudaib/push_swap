/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:56:51 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 12:54:33 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_node	*find_min_unindexed(t_node *head)
{
	t_node	*min;

	min = NULL;
	while (head)
	{
		if (head->index == -1)
		{
			if (!min || head->data < min->data)
				min = head;
		}
		head = head->next;
	}
	return (min);
}

void	sort_indices(t_node **head)
{
	t_node	*min;
	int		i;
	int		size;

	if (!head || !*head)
		return ;
	size = list_counter(*head);
	i = 0;
	while (i < size)
	{
		min = find_min_unindexed(*head);
		if (!min)
			break ;
		min->index = i++;
	}
}
