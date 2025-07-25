/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:31:36 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 17:43:53 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ERROR);
	else if (argc == 1)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (stack_sorted(a))
	{
		if (list_size(a) == 2)
			sa(&a, false);
		else if (list_size(a) == 3)
			three_sort(&a);
		//else if (list_size(a) == 4)
		//	four_sort(&a);
		else if (list_size(a) == 5)
			five_sort(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}

void	stack_init(t_stack **a, char **argv, bool flag)
{
	long	nbr;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (right_in(argv[i]))
			left_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			left_free(a, argv, flag);
		if (dup_in(*a, (int)nbr))
			left_free(a, argv, flag);
		list_add_back(a, (int)nbr);
	}
	if (flag)
		ft_freetwodim(argv);
}

void	ft_freetwodim(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	mexit(char *msg, int flag)
{
	if (flag)
		write(flag + 1, "Error\n", 6);
	write(flag + 1, msg, ft_strlen(msg));
	exit(flag);
}

int	right_in(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (ERROR);
	if ((*str == '+' || *str == '-') && !(ft_isdigit(str[1])))
		return (ERROR);
	if (ft_strlen(str) >= 12)
		return (ERROR);
	while (*(++str))
	{
		if (ft_isdigit(*str))
			return (ERROR);
	}
	return (SUCCESS);
}

void	left_free(t_stack **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		ft_freetwodim(argv);
	mexit("Error\n", ERROR);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	dup_in(t_stack *a, int nbr)
{
	if (!a)
		return (SUCCESS);
	while (a)
	{
		if (a->value == nbr)
			return (ERROR);
		a = a->next;
	}
	return (SUCCESS);
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

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (SUCCESS);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (ERROR);
		a = a->next;
	}
	return (SUCCESS);
}

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

void	three_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

t_stack	*find_highest(t_stack *stack)
{
	int				highest;
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

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = list_size(*stack);
if (!stack || !*stack || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool flag)
{
	push(a, b);
	if (!flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool flag)
{
	push(b, a);
	if (!flag)
		write(1, "pb\n", 3);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len;

	len = list_size(*a);
	if (len == 5)
		five_sort(a, b);
	else
	{
		while (len-- > 3)
			pb(b, a, false);
	}
	three_sort(a);
	while (*b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

void	five_sort(t_stack **a, t_stack **b)
{
	while (list_size(*a) > 3)
	{
		init_node(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

void	init_node(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = list_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack			*current_a;
	t_stack			*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	long			smallest;
	t_stack	*smallest_node;

	if (NULL == stack)
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

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = list_size(a);
	len_b = list_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target->above_median)
			b->push_price += b->target->current_position;
		else
			b->push_price += len_a - (b->target->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	t_stack	*best_match_node;
	long	best_match_value;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	finish_rotation(t_stack **stack,
		t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b, false);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

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
