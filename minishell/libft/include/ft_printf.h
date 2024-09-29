/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:49:08 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putuint(unsigned int i);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex_low(unsigned int nbr);
int		ft_puthex_up(unsigned int nbr);
int		ft_putpointer(unsigned long nbr);

#endif
