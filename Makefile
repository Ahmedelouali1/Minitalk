NAME= client server

all : $(NAME)

client : minitalk.h client.c
	cc -Wall -Wextra -Werror utils.c client.c -o client 

server : minitalk.h server.c
	cc -Wall -Wextra -Werror server.c -o server

clean : 
	rm -f client server 

fclean : clean

re : clean all
