SRCS :=	ft_printf.c \
		ft_print_unsign.c \
		ft_print_int.c \
		ft_putnbr_base.c\
		parser_utils.c \
		ft_print_char.c \
		print_string.c \
		ft_putchar.c \
		ft_putstr_fd.c \
		parcer.c \
		parce_data_type.c \
		ft_long_itoa.c \
		ft_print_x.c \
		ft_print_pointer.c \
		ft_len_of_num_base.c \
		ft_print_o.c\
		ft_print_n.c

LIBFT	= ./libft/libft.a

NAME	= libftprintf.a

GCC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

%.o: %.c	ft_printf.h
	$(GCC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(GCC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)


clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re