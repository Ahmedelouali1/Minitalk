/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:43:15 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/02/27 15:10:06 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	d;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	d = (nb % 10) + '0';
	write(1, &d, 1);
}

int	*assign_value(void)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * 8);
	if (!arr)
		return (NULL);
	while (i < 8)
	{
		arr[i] = 1 << i;
		i++;
	}
	return (arr);
}

void	ft_reset(int *i, char *c)
{
	*i = 0;
	*c = 0;
}

void	sig_handler(int sig, siginfo_t *info, void *p)
{
	static int	i;
	static char	c;
	static int	o_pid;
	int			*arr;

	arr = assign_value();
	if (!arr)
		return ;
	if (p)
		p = NULL;
	if (o_pid != 0 && info->si_pid != o_pid)
		ft_reset(&i, &c);
	o_pid = info->si_pid;
	if (sig == SIGUSR1)
		c += arr[i];
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		ft_reset(&i, &c);
	}
	free(arr);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	data;

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
		pause();
}
