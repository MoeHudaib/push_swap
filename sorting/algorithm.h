/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:31:22 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:22:14 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../stack/stack.h"
# include "../validation/validation.h"

/*		Sorting Algorithm	*/
void	sort_indices(t_node **head);
int		is_sorted(t_node *a);
void	push_swap(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_four(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_two(t_node **a);
t_node	***split(t_node *head);
void	free_split(t_node ***spl);
void	hudaib(t_node **a, t_node **b);
void	push_chunk_to_b(t_node **a, t_node **b, t_node **chunk);
void	bring_max_top(t_node **b);

#endif
