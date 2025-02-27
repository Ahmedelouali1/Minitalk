/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:43:31 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/02/27 13:48:35 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	check_pid(char *s)
{
	int	i;

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
	int	i;

	i = 0;
	while (i != 8)
	{
		if (c % 2 == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				return (0);
			}
			usleep(4000);
		}
		if (c % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				return (0);
			}
			usleep(4000);
		}
		c /= 2;
		i++;
	}
	return (1);
}

int	send_msg(char *str, int pid)
{
	int	i;

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

int	main(int argc, char *argv[])
{
	int pid;

	if (argc != 3)
		return (1);
	if (check_pid(argv[1]) == 0)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (1);
    send_msg(argv[2], pid);
}