/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:36:53 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/03 23:37:09 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

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
