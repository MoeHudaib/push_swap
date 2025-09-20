/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:52:52 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/20 22:52:52 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_list(t_node *head)
{
	t_node	*current;

	if (!head)
	{
		ft_printf("Error: Cannot print an empty list.\n");
		return ;
	}
	current = head;
	while (current)
	{
		ft_printf("%d", current->data);
		if (current->next)
			ft_printf(" -> ");
		current = current->next;
	}
	ft_printf("\n");
}
