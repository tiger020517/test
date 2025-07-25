/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 02:39:26 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/26 02:39:36 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a,
			t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack **a,
		t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}
