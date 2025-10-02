/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:54:16 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/02 17:12:26 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_cost
{
	int	up;
	int	down;
}	t_cost;

typedef struct s_node
{
	int				data;
	int				index;
	t_cost			*cost;
	struct s_node	*next;
}	t_node;

typedef enum e_which
{
	R = 1000,
	RR
}	t_which;

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
void	print_list(t_node *head);
int		list_counter(t_node *head);

/*		validation Methods	*/
int		is_digit(char *str);
int		is_dup(char **av);
int		valid(char *str);

/*		Sorting Algorithm	*/
void	sort_indices(t_node **head);
void	calc_cost(t_node *head);
int		search_up(t_node *head, int data);
int		search_down(t_node *head, int data);
t_node	*search_index(t_node *head, int index);
int		is_sorted(t_node *a);
void	push_swap(t_node **a, t_node **b);
int		decide_which(t_node *node);
void	sort_four(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_two(t_node **a);

#endif
