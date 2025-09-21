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

#include "stack.h"
#include "libft.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

static int	loop_through(char **args, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check(args[i]) || ft_atoi(args[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_node	*head;

	if (argc == 1 || !loop_through(argv, argc))
	{
		ft_printf("Invalid Usage.\n, %d", ft_atoi(argv[1]));
		return (1);
	}
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
