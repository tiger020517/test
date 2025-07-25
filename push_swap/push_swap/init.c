/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:31:52 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 20:33:17 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!ft_isdigit(*str))
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
