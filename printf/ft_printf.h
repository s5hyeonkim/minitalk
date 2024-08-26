/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:06:55 by sohykim           #+#    #+#             */
/*   Updated: 2023/12/01 17:39:07 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef int	(*t_char)(int, int);
typedef int	(*t_line)(unsigned int, int);

int		ft_putlargehex_fd(unsigned int num, int fd);
int		ft_putsmallhex_fd(unsigned int num, int fd);
int		ft_putaddr_fd(void *addr, int fd);
int		ft_putunum_fd(unsigned int num, int fd);
int		ft_putnumber_fd(int num, int fd);
int		ft_putcharacter_fd(int c, int fd);
int		ft_putstring_fd(char *s, int fd);
int		ft_printf(const char *format, ...);
#endif
