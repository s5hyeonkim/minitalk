CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = .
IFLAGS = -Iminitalk.h
IBONUS = -Iminitalk_bonus.h
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : ./client.c
	make -C printf
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -Lprintf -lftprintf -Lprintf/libft -lft

$(SERVER) : ./server.c
	make -C printf
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -Lprintf -lftprintf -Lprintf/libft -lft

$(CLIENT_BONUS) : ./client_bonus.c
	make -C printf
	$(CC) $(CFLAGS) $(IBONUS) $^ -o $@ -Lprintf -lftprintf -Lprintf/libft -lft

$(SERVER_BONUS) : ./server_bonus.c
	make -C printf
	$(CC) $(CFLAGS) $(IBONUS) $^ -o $@ -Lprintf -lftprintf -Lprintf/libft -lft

clean:
	rm -f ./server.o
	rm -f ./client.o
	rm -f ./server_bonus.o
	rm -f ./client_bonus.o
	make clean -C printf

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(CLIENT_BONUS)
	rm -f $(SERVER_BONUS)
	make fclean -C printf

re : fclean all

.PHONY: all clean fclean re
