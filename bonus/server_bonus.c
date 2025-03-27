/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:18 by mel-moud          #+#    #+#             */
/*   Updated: 2025/03/11 16:20:33 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	get_unicode_byte_count(unsigned char c)
{
	if (c < 128)
		return (1);
	else if (c >= 192 && c < 224)
		return (2);
	else if (c >= 224 && c < 240)
		return (3);
	else if (c >= 240 && c < 248)
		return (4);
	return (0);
}

int	process(int *bit_counter, char *received_char, int *unicode_idx)
{
	static unsigned char	unicode_bytes[8];
	static int				byte_count;

	if (++(*bit_counter) == 8)
	{
		if (*unicode_idx == 0)
			byte_count = get_unicode_byte_count(*received_char);
		unicode_bytes[(*unicode_idx)++] = *received_char;
		if (--byte_count == 0)
		{
			unicode_bytes[*unicode_idx] = '\0';
			ft_printf("%s", unicode_bytes);
			*unicode_idx = 0;
		}
		*bit_counter = 0;
		*received_char = 0;
	}
	return (0);
}

void	handlers(int signal, siginfo_t *info, void *context)
{
	static int		bit;
	static char		received_bit;
	static pid_t	pid;
	static int		i;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		bit = 0;
		received_bit = 0;
		i = 0;
	}
	if (signal == SIGUSR2)
		received_bit |= (0b10000000 >> bit);
	process(&bit, &received_bit, &i);
	kill(info->si_pid, SIGUSR1);
}

void	print_banner(pid_t pid)
{
	ft_printf("\n\n%s%s%s", LINE1, LINE2, LINE3);
	ft_printf("\t\t PID: %d\t\x1b[36;4mby: mel-moud\x1b[0m\n\n", pid);
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
