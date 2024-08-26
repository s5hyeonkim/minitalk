/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:02:03 by sohykim           #+#    #+#             */
/*   Updated: 2023/11/21 18:33:42 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunum_fd(unsigned int num, int fd)
{
	char	rest;
	int		len;

	len = 0;
	if (num / 10)
		len += ft_putunum_fd(num / 10, fd);
	rest = num % 10 + '0';
	if (len < 0 || write(1, &rest, 1) < 0)
		return (-1);
	return (++len);
}

int	ft_putsmallhex_fd(unsigned int num, int fd)
{
	int	len;

	len = 0;
	if (num / 16)
		len += ft_putsmallhex_fd(num / 16, fd);
	if (len < 0 || write(fd, &"0123456789abcdef"[num % 16], 1) < 0)
		return (-1);
	return (++len);
}

int	ft_putlargehex_fd(unsigned int num, int fd)
{
	int	len;

	len = 0;
	if (num / 16)
		len += ft_putlargehex_fd(num / 16, fd);
	if (len < 0 || write(fd, &"0123456789ABCDEF"[num % 16], 1) < 0)
		return (-1);
	return (++len);
}
