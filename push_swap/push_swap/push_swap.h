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

void	stack_init(t_stack **a, char **argv, bool flag);
int		right_in(char *str);
void	left_free(t_stack **a, char **argv, bool flag);
void	free_stack(t_stack **stack);


#endif