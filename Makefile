NAME= client server

BONUS= client_bonus server_bonus

all : $(NAME)

bonus : $(BONUS)

client : minitalk.h client.c
	cc -Wall -Wextra -Werror client.c -o client

server : minitalk.h server.c
	cc -Wall -Wextra -Werror server.c -o server

client_bonus : ./bonus/minitalk_bonus.h ./bonus/client_bonus.c
	cc -Wall -Wextra -Werror ./bonus/client_bonus.c -o client_bonus

server_bonus : ./bonus/minitalk_bonus.h ./bonus/server_bonus.c
	cc -Wall -Wextra -Werror ./bonus/server_bonus.c -o server_bonus

clean : 
	rm -f client server client_bonus server_bonus

fclean : clean

re : clean all