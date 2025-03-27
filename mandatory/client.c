/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:44:47 by mel-moud          #+#    #+#             */
/*   Updated: 2025/03/11 21:43:45 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack;

int	parsing_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("\n\tTry runing: %s <server's PID> <message>\n\n", av[0]);
		return (1);
	}
	if (av[1][i] == '+')
		i++;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > 2147483647)
			return (-1);
		i++;
	}
	return ((int)nbr);
}

void	signal_handler(int signal)
{
	(void)signal;
	g_ack = 1;
}

void	send_bit_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		g_ack = 0;
		if (((c >> (7 - j)) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack)
			;
		j++;
	}
}

int	main(int ac, char **av)
{
	int					i;
	pid_t				pid;
	struct sigaction	hdl;

	if (parsing_args(ac, av))
		return (1);
	i = 0;
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Invalid PID\n"), 1);
	hdl.sa_handler = signal_handler;
	hdl.sa_flags = SA_RESTART;
	signal(SIGUSR1, signal_handler);
	while (av[2][i])
	{
		send_bit_signal(pid, av[2][i]);
		i++;
	}
	send_bit_signal(pid, '\0');
}
