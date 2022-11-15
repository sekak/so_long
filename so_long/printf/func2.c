/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:31:55 by asekkak           #+#    #+#             */
/*   Updated: 2022/10/21 16:33:37 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_base16(unsigned long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_base16_lower(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putnbr_base16_lower(nb / 16);
		ft_putnbr_base16_lower(nb % 16);
	}
	else
		ft_putchar("0123456789abcdef"[nb]);
	return (ft_len_base16(nb));
}

int	ft_putnbr_base16_upper(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putnbr_base16_upper(nb / 16);
		ft_putnbr_base16_upper(nb % 16);
	}
	else
		ft_putchar("0123456789ABCDEF"[nb]);
	return (ft_len_base16(nb));
}

int	ft_len_unsigned(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (ft_len_unsigned(nb));
}
