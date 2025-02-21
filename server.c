#include "minitalk.h"
#include <stdio.h>

void ft_putnbr(int nb)
{
	char d;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	d = (nb % 10) + '0';
	write(1, &d, 1);
}

void sig_handler(int sig)
{
    static int i;
    static char c;
    int arr[8] = {1, 2, 4, 8, 16, 32, 64, 128};

    if (sig == SIGUSR1)
    {
        c += arr[i];
        i++;
    }
    if (sig == SIGUSR2)
    {
        i++;
    }
    if (i == 8)
    {
        write(1, &c, 1);
        c = 0;
        i = 0;
    }
}

int main()
{
    pid_t pid;
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    pid = getpid();
    ft_putnbr(pid);
    write(1, "\n", 1);
    while (1)
    { 
        pause();
    }

}
