#include "minitalk.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	result;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	signe = 1;
	result = 0;
	if (*nptr == '-')
		signe *= -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * signe);
}

int check_pid(char *s)
{
    int i;

    i = 0;
    if (s[i] == '+')
        i++;
    if (s[i] == '\0')
        return (0);
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}
int send_char(char c, int pid)
{
    int i;

    i = 0;
    while (i != 8)
    {
        if (c % 2 == 1)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                return(0);
            }
            usleep(3000);
        }
        if (c % 2 == 0)
        {
            if (kill (pid, SIGUSR2) == -1)
            {
                return (0);
            }
            usleep(3000);
        }
        c /= 2;
        i++;
    }
    return (1);
}
int send_msg(char *str, int pid)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (send_char(str[i], pid) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    int pid;

    if (argc != 3)
        return(1);
    if (check_pid(argv[1]) == 0)
        return (1);
    pid = ft_atoi(argv[1]);
    send_msg(argv[2], pid);

}