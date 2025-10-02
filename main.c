/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:12:56 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/02 13:43:58 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	t_node	*a_head;
	t_node	*b_head;
	int	i = 1;
	if (!valid(av[i]) || is_dup(av))
	{
		ft_printf("Invalid Input.");
		return (1);
	}
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
	s(&a_head, "sa");
	r(&a_head, "ra");
	sort_indices(&a_head);
	calc_cost(a_head);
	print_list(a_head);
	p(&a_head, &b_head, "pb");
	r(&b_head, "rb");
	calc_cost(b_head);
	calc_cost(a_head);
	print_list(a_head);
	print_list(b_head);
	delete_list(&a_head);
	delete_list(&b_head);	
}
