/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:45:55 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/03 23:54:22 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting/algorithm.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*b_head;
	t_node	*a_head;

	if (ac == 1)
		return (1);
	i = 1;
	if (!valid(av[i]) || is_dup(av))
		return (ft_printf("Error"));
	a_head = create_node(ft_atoi(av[i++]));
	b_head = NULL;
	while (av[i])
	{
		if (!valid(av[i]))
		{
			ft_printf("Invalid Input.");
			delete_list(&a_head);
			return (1);
		}
		add_back(&a_head, create_node(ft_atoi(av[i++])));
	}
	push_swap(&a_head, &b_head);
	delete_list(&a_head);
	if (b_head)
		delete_list(&b_head);
}
