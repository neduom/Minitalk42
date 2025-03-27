SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c ft_strlen.c
NAME = libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)


RM = rm -f


all: $(NAME)


$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@


clean:
		$(RM) $(OBJ)


fclean: clean
		$(RM) $(NAME)


re: fclean all