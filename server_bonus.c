/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:32:10 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/18 08:13:23 by sohykim          ###   ########.fr       */
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
			usleep(200);
		}
		str++;
	}
}

void	callback(pid_t pid)
{
	send_string(pid, "\nMessage Completed\n");
}

void	ready_to_signal(void)
{
	g_response.ch = 0;
	g_response.buf[g_response.len] = 0;
	g_response.bit = 0;
}

void	sig_handler_with_pid(int sig, siginfo_t *info, void *data)
{
	data = NULL;
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
			callback(info->si_pid);
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

	g_response.ch = 0;
	g_response.bit = 0;
	g_response.len = 0;
	g_response.buf[0] = 0;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&(sig.sa_mask));
	sig.sa_sigaction = sig_handler_with_pid;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	ft_printf("server pid is %d\n", pid);
	while (1)
		pause();
	return (0);
}
