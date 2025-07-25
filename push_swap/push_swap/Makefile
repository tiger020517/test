OUT						= push_swap

SRCS					= ./greedy_etc.c \
							./greedy_set.c \
							./init.c \
							./inst_etc.c \
							./inst_push.c \
							./inst_reverse_rotate.c \
							./inst_rotate.c \
							./inst_swap.c \
							./list.c \
							./push_swap.c \
							./sorting.c \
							./utils.c


OBJS					= $(SRCS:%.c=%.o)

CC						= cc
CFLAGS					= -Wall -Wextra -Werror -g

AR						= ar
ARFLAGS					= rcs

RM						= rm -f

LIBFTORIGIN				= ./libft/libft.a


$(OUT)		: $(OBJS) $(LIBFTORIGIN) $(MLXORIGIN)
			$(CC) $(CFLAGS) -o $(OUT) $(OBJS) -L./libft -lft
%.o			: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all			: $(OUT)

clean		: killsub
			$(RM) $(OBJS) 

fclean		: clean
			$(RM) $(OUT)

re			: fclean all

killsub		:
			make -C ./libft fclean -silence

$(LIBFTORIGIN)	:
			make -C ./libft -silence
			
.PHONY: all clean fclean re killsub