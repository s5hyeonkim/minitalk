/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:08:41 by sohykim           #+#    #+#             */
/*   Updated: 2024/03/18 07:52:52 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <sys/signal.h>
# include "./printf/ft_printf.h"

typedef struct sigaction	t_sigact;
struct s_data
{
	char	ch;
	int		bit;
	char	buf[3050];
	int		len;
};

#endif
