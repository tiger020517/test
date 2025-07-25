/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:34:13 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 21:40:46 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack *a)
{
	int	count;

	if (!a)
		return (SUCCESS);
	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	list_add_back(t_stack **a, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return (SUCCESS);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (ERROR);
	node->next = NULL;
	node->value = nbr;
	if (!*a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*a);
		last->next = node;
		node->prev = last;
	}
	return (SUCCESS);
}

t_stack	*find_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
