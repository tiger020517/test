/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:31:36 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/26 02:39:39 by junhykim         ###   ########.fr       */
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
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 2)
		stack_init(&a, argv, argc == 2);
	else
		stack_init(&a, argv + 1, argc == 2);
	if (stack_sorted(a))
	{
		if (list_size(a) == 2)
			sa(&a, false);
		else if (list_size(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
