/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:25:38 by asekkak           #+#    #+#             */
/*   Updated: 2022/10/21 16:14:34 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putnbr(int nb);
int		ft_len(long n);
int		ft_putstr(char *s);
void	ft_putchar(int c);
int		ft_len_base16(unsigned long n);
int		ft_putnbr_base16_lower(unsigned long nb);
int		ft_putnbr_base16_upper(unsigned long nb);
int		ft_len_unsigned(unsigned int n);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_printf(const char *s, ...);

#endif