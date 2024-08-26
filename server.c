/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:32:10 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/18 08:09:57 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

volatile struct s_data	g_response;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_response.ch += 1;
	g_response.bit += 1;
	if (g_response.bit == 8)
	{
		if (g_response.len == 3000)
		{
			ft_printf("%s", g_response.buf);
			g_response.len = 0;
		}
		if (g_response.ch == 0)
		{
			ft_printf("%s\n", g_response.buf);
			g_response.len = 0;
		}
		else
			g_response.buf[g_response.len++] = g_response.ch;
		g_response.buf[g_response.len] = 0;
		g_response.bit = 0;
		g_response.ch = 0;
		return ;
	}
	g_response.ch <<= 1;
}

int	main(void)
{
	pid_t		pid;
	t_sigact	sig;

	g_response.buf[0] = 0;
	g_response.len = 0;
	g_response.bit = 0;
	g_response.ch = 0;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&(sig.sa_mask));
	sig.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	ft_printf("server pid is %d\n", pid);
	while (1)
		pause();
	return (0);
}
