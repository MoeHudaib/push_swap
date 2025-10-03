/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 01:35:36 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 01:35:37 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "../libs/libft/libft.h"

/*		validation Methods	*/
int		is_digit(char *str);
int		is_dup(char **av);
int		valid(char *str);

#endif
