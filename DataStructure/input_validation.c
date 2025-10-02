/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhdeeb <mhdeeb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:11:48 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/02 10:13:36 by mhdeeb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_digit(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	is_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid(char *str)
{
	int	flag1;
	int	flag2;
	int	flag3;

	flag1 = is_digit(str);
	flag2 = ft_strcmp(str, "-1");
	flag3 = (ft_atoi(str) == -1);
	if (!flag1)
		return (0);
	if (flag2 == 0)
		return (1);
	if (flag3)
		return (0);
	return (1);
}
