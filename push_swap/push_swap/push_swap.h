/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhykim <junhykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:32:51 by junhykim          #+#    #+#             */
/*   Updated: 2025/07/25 17:42:59 by junhykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "./libft/libft.h"

# define ERROR 1
# define SUCCESS 0

typedef struct s_stack
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		main(int argc, char *argv[]);
void	stack_init(t_stack **a, char **argv, bool flag);
void	ft_freetwodim(char **arr);
void	mexit(char *msg, int flag);
int		right_in(char *str);
void	left_free(t_stack **a, char **argv, bool flag);
void	free_stack(t_stack **stack);
int		dup_in(t_stack *a, int nbr);
int		list_add_back(t_stack **a, int nbr);
t_stack	*find_last_node(t_stack *a);
long	ft_atol(const char *str);
bool	stack_sorted(t_stack *a);
int		list_size(t_stack *a);
void	swap(t_stack **a);
void	sa(t_stack **a, int flag);
void	sb(t_stack **a, bool flag);
void	ss(t_stack **a, t_stack **b, bool flag);
void	rotate(t_stack **a);
void	ra(t_stack **a, bool flag);
void	rb(t_stack **b, bool flag);
void	rr(t_stack **a, t_stack **b, bool flag);
void	three_sort(t_stack **a);
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool flag);
void	pb(t_stack **b, t_stack **a, bool flag);
void	push_swap(t_stack **a, t_stack **b);
void	five_sort(t_stack **a, t_stack **b);
void	init_node(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
t_stack	*find_smallest(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	move_nodes(t_stack **a, t_stack **b);

#endif