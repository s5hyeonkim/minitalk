/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:10:14 by sohykim           #+#    #+#             */
/*   Updated: 2023/12/06 12:55:05 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_char	get_cfunc(char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnumber_fd);
	else if (format == 'c')
		return (ft_putcharacter_fd);
	else
		return (NULL);
}

static t_line	get_lfunc(char format)
{
	if (format == 'x')
		return (ft_putsmallhex_fd);
	else if (format == 'X')
		return (ft_putlargehex_fd);
	else if (format == 'u')
		return (ft_putunum_fd);
	else
		return (NULL);
}

static int	bridge(const char format, va_list ap, int *flag)
{
	int		index;
	t_char	print_char;
	t_line	print_line;

	print_char = get_cfunc(format);
	print_line = get_lfunc(format);
	index = 0;
	if (print_char)
		*flag = print_char(va_arg(ap, int), 1);
	else if (print_line)
		*flag = print_line(va_arg(ap, unsigned int), 1);
	else if (format == 'p')
		*flag = ft_putaddr_fd(va_arg(ap, void *), 1);
	else if (format == 's')
		*flag = ft_putstring_fd(va_arg(ap, char *), 1);
	else if (format == '%')
		*flag = ft_putcharacter_fd((int)format, 1);
	else
		*flag = -1;
	index += 2;
	return (index);
}

static int	ft_print_lines(const char	*format, va_list ap)
{
	int	flag;
	int	len;

	flag = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
			format += bridge(*(format + 1), ap, &flag);
		else
			flag = ft_putcharacter_fd((int)*format++, 1);
		if (flag >= 0)
			len += flag;
		else
			break ;
	}
	if (flag < 0)
		return (flag);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_print_lines(format, ap);
	va_end(ap);
	return (len);
}
