CC = cc
CFLAGS= -Wall -Wextra -Werror
NAME= libftprintf.a

SRCS= ft_putaddress.c ft_puthex.c ft_putstr.c ft_putupperhex.c ft_putchar.c ft_putnbr.c ft_putun.c ft_strlen.c ft_printf.c ft_printf_utils.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
