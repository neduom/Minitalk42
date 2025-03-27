/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:48:29 by mel-moud          #+#    #+#             */
/*   Updated: 2025/03/11 21:32:53 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_counter;

void	handlers(int signal, siginfo_t *info, void *context)
{
	static char		res;
	static pid_t	pid;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = 0;
		g_counter = 0;
		res = 0;
	}
	if (signal == SIGUSR2)
		res |= (0b10000000 >> g_counter);
	if (++g_counter == 8)
	{
		g_counter = 0;
		ft_printf("%c", res);
		res = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	print_banner(pid_t pid)
{
	ft_printf("\n\n%s%s%s", LINE1, LINE2, LINE3);
	ft_printf("\t\t PID: \
	%d\t\x1b[36;4mby: mel-moud\x1b[0m\n\n", pid);
	ft_printf("Printing Area:\n\n");
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	print_banner(pid);
	action.sa_sigaction = handlers;
	action.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
