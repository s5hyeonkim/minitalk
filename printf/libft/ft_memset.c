/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:26 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/05 16:48:37 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ctoch;
	size_t			index;

	index = 0;
	ctoch = (unsigned char *)b;
	while (index < len)
	{
		ctoch[index] = c;
		index++;
	}
	return (ctoch);
}
