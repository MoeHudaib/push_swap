/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:54:16 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/20 22:54:17 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*create_node(int data);
t_node	*pop(t_node **head);
t_node	*push(t_node **head, int data);
void	print_list(t_node *head);
void	delete_list(t_node **head);

#endif
