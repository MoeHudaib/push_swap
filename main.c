/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:12:56 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/20 23:12:57 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DataStructure/stack.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Invalid Usage.\n");
		return (1);
	}
	t_node	*head;
	int	i;
	i = 1;
	head = create_node(ft_atoi(argv[i++]));
	print_list(head);
	while (i < argc)
	{
		push(&head, ft_atoi(argv[i]));
		print_list(head);
		i++;
	}
	delete_list(&head);
}
