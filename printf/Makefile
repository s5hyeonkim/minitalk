CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = .
SRCL = ./libft/*.c
SRCS = ./ft_printf.c ./ft_printf_utils.c ./ft_printf_utils2.c
OBJS = $(SRCS:.c=.o)
OBJL = $(SRCL:.c=.o)
IFLAGS = -Ift_printf.h
NAME = libftprintf.a
LIBFT = libft

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	ar -rcs $@ $^ $(OBJL)

%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $^

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
	make fclean -C $(LIBFT)
	make -C $(LIBFT)

.PHONY: all clean fclean re
