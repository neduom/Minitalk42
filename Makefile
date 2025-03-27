SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CFLAGS = -Wall -Wextra -Werror
CC = cc

PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c\
				ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_strlen.c 
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

C_SRC = mandatory/client.c
S_SRC = mandatory/server.c
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

C_BONUS_SRC = bonus/client_bonus.c
S_BONUS_SRC = bonus/server_bonus.c
C_BONUS_OBJ = $(C_BONUS_SRC:.c=.o)
S_BONUS_OBJ = $(S_BONUS_SRC:.c=.o)

all : $(SERVER) $(CLIENT) $(PRINTF_OBJ)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(PRINTF_OBJ)

$(CLIENT): $(C_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(S_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_BONUS): $(C_BONUS_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_BONUS): $(S_BONUS_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

mandatory/%.o : mandatory/%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.o : ft_printf/%.c ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
$(C_OBJ) $(S_OBJ): mandatory/minitalk.h
$(C_BONUS_OBJ) $(S_BONUS_OBJ): bonus/minitalk_bonus.h

clean:
	rm -rf $(C_OBJ) $(S_OBJ) $(PRINTF_OBJ) $(C_BONUS_OBJ) $(S_BONUS_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all