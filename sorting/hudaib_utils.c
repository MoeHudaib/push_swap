/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hudaib_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:34:05 by mohammad          #+#    #+#             */
/*   Updated: 2025/10/04 00:39:45 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	get_chunk_count(t_node *head, int chunk_size)
{
	int	total;

	total = list_counter(head);
	if (total % chunk_size == 0)
		return (total / chunk_size);
	return (total / chunk_size + 1);
}

static int	count_chunk_nodes(t_node *head, int start, int end)
{
	int		count;
	t_node	*cur;

	count = 0;
	cur = head;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
			count++;
		cur = cur->next;
	}
	return (count);
}

static t_node	**fill_chunk(t_node *head, int start, int end)
{
	t_node	**chunk;
	t_node	*cur;
	int		k;
	int		len;

	len = count_chunk_nodes(head, start, end);
	chunk = malloc(sizeof(t_node *) * (len + 1));
	if (!chunk)
		return (NULL);
	k = 0;
	cur = head;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
			chunk[k++] = cur;
		cur = cur->next;
	}
	chunk[k] = NULL;
	return (chunk);
}

t_node	***split(t_node *head)
{
	t_node	***spl;
	int		chunk_size;
	int		chunks;
	int		i;

	if (!head)
		return (NULL);
	chunk_size = ft_sqrt(list_counter(head)) * 3;
	chunks = get_chunk_count(head, chunk_size);
	spl = malloc(sizeof(t_node **) * (chunks + 1));
	if (!spl)
		return (NULL);
	i = 0;
	while (i < chunks)
	{
		spl[i] = fill_chunk(head, i * chunk_size, (i + 1) * chunk_size - 1);
		if (!spl[i])
		{
			free_split(spl);
			return (NULL);
		}
		i++;
	}
	spl[i] = NULL;
	return (spl);
}

void	free_split(t_node ***spl)
{
	int	i;

	if (!spl)
		return ;
	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}
