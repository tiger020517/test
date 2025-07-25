/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:37:09 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 20:37:15 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*last_node;
	int		len;

	len = list_size(*a);
	if (!a || !*a || len == 1)
		return ;
	last_node = find_last_node(*a);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool flag)
{
	rotate(a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool flag)
{
	rotate(b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool flag)
{
	rotate(a);
	rotate(b);
	if (!flag)
		write(1, "rr\n", 3);
}
