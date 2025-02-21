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

void sig_handler(int sig, siginfo_t *info, void *p)
{
    static int i;
    static char c;
    static int o_pid;
    int arr[8] = {1, 2, 4, 8, 16, 32, 64, 128};

    if (o_pid != 0 && info->si_pid != o_pid)
    {
        i = 0;
        c = 0;
    }
    o_pid = info->si_pid;
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
    struct sigaction data;
    data.sa_flags = SA_SIGINFO;
    data.sa_sigaction = sig_handler;
    if (sigaction(SIGUSR2, &data, NULL) == -1)
        return (1);    
    if (sigaction(SIGUSR1, &data, NULL) == -1)
        return (1);
    pid = getpid();
    ft_putnbr(pid);
    write(1, "\n", 1);
    while (1)
    { 
        pause();
    }

}
