/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:02:03 by sohykim           #+#    #+#             */
/*   Updated: 2023/12/01 17:39:50 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr_fd(void	*addr, int fd)
{
	unsigned long	num;
	const char		hex[16] = "0123456789abcdef";
	char			buffer[32];
	int				index;
	int				len;

	index = 0;
	num = (unsigned long) addr;
	len = write(fd, "0x", 2);
	if (len < 0)
		return (-1);
	while (!index || num)
	{
		buffer[index++] = hex[num % 16];
		num /= 16;
	}
	buffer[index] = 0;
	while (index--)
	{
		if (ft_putcharacter_fd(buffer[index], fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putnumber_fd(int n, int fd)
{
	char	rest;
	long	num;
	int		len;

	len = 0;
	num = (long) n;
	if (num < 0)
	{
		len += write(fd, "-", 1);
		if (len < 0)
			return (-1);
		num *= -1;
	}
	if (num / 10)
		len += ft_putnumber_fd(num / 10, fd);
	rest = num % 10 + '0';
	if (len < 0 || write(fd, &rest, 1) < 0)
		return (-1);
	return (++len);
}

int	ft_putcharacter_fd(int c, int fd)
{
	char	ch;

	ch = c;
	return (write(fd, &ch, 1));
}

int	ft_putstring_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, &"(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
