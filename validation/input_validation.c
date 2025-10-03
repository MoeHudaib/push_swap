/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:11:48 by mhdeeb            #+#    #+#             */
/*   Updated: 2025/10/03 23:28:52 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_digit(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
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
	int	zero;

	i = 1;
	zero = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "0") == 0
			|| ft_strcmp(av[i], "+0") == 0
			|| ft_strcmp(av[i], "-0") == 0)
			zero++;
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	if (zero > 1)
		return (1);
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
