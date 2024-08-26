/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:53:26 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/18 07:59:05 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

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

int	main(int argc, char *argv[])
{
	pid_t		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
