/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:36:29 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 20:36:39 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	int	len;

	len = list_size(*a);
	if (!a || !*a || len == 1)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

void	sa(t_stack **a, int flag)
{
	swap(a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **a, bool flag)
{
	swap(a);
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool flag)
{
	swap(a);
	swap(b);
	if (!flag)
		write(1, "ss\n", 3);
}
