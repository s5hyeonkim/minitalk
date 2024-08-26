/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:53:26 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/18 08:13:15 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

volatile struct s_data	g_response;

void	send_string(pid_t pid, char *str)
{
	int		mask;
	size_t	index;
	size_t	len;
	char	c;

	index = 0;
	len = ft_strlen(str);
	while (index++ <= len)
	{
		c = *str;
		mask = 1 << 7;
		while (mask > 0)
		{
			if (mask & c)
				kill(pid, 30);
			else
				kill(pid, 31);
			mask >>= 1;
			usleep(100);
		}
		str++;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_response.ch += 1;
	g_response.bit += 1;
	if (g_response.bit == 8)
	{
		g_response.bit = 0;
		if (g_response.ch == 0)
			exit(0);
		else
			ft_printf("%c", g_response.ch);
		g_response.ch = 0;
		return ;
	}
	g_response.ch <<= 1;
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	t_sigact	sig;

	g_response.ch = 0;
	g_response.bit = 0;
	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
