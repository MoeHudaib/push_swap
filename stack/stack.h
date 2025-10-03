/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:54:16 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 00:03:35 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*		list Methods	*/
t_node	*create_node(int data);
t_node	*pop(t_node **head);
t_node	*push_new(t_node **head, int data);
t_node	*push(t_node **head, t_node *new_node);
t_node	*last(t_node *head);
t_node	*pop_last(t_node **head);

/*		main Methods	*/
void	s(t_node **head, char *msg);
void	p(t_node **a_head, t_node **b_head, char *msg);
void	r(t_node **head, char *msg);
void	rr(t_node **head, char *msg);

/*		helper Methods	*/
void	print_list(t_node *head);
void	delete_list(t_node **head);
void	add_back(t_node **head, t_node *new);
int		list_counter(t_node *head);

#endif
