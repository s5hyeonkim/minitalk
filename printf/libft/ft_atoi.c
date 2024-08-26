/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:44:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/15 07:16:44 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char ch)
{
	if (ch >= 9 && ch <= 13)
		return (1);
	if (ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;
	size_t	pre;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		pre = result;
		result = result * 10 + *str - '0';
		if ((result - (*str - '0')) / 10 != pre)
			return (-1);
		str++;
	}
	return (result * sign);
}
