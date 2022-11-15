/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:26:31 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/08 15:25:35 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*getarg(va_list arg, const char *s, int i)
{
	if (s[i + 1] == 's' || s[i + 1] == 'd'
		|| s[i + 1] == 'i' || s[i + 1] == 'c' || s[i + 1] == 'p'
		|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X')
	{
		return (va_arg(arg, void *));
	}
	return (0);
}

int	function3(const char *s, int i, void *gra)
{
	int	j;

	j = 0;
	if (s[i + 1] == 'p')
	{
		ft_putstr("0x");
		j += ft_putnbr_base16_lower((unsigned long)gra) + 2;
	}
	else if (s[i + 1] == 'u')
		j += ft_putnbr_unsigned((unsigned int)gra);
	else if (s[i + 1] == 'x')
		j += ft_putnbr_base16_lower((unsigned int)gra);
	else if (s[i + 1] == 'X')
		j += ft_putnbr_base16_upper((unsigned int)gra);
	return (j);
}

int	function2(const char *s, int i, void *gra)
{
	int	j;

	j = 0;
	if (s[i + 1] == 's')
		j += ft_putstr((char *)gra);
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		j += ft_putnbr((int)gra);
	else if (s[i + 1] == 'c')
	{
		ft_putchar((int)gra);
		j += 1;
	}
	else if (s[i + 1] == '%')
	{
		ft_putchar('%');
		j += 1;
	}
	else
		j += function3(s, i, gra);
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	void	*gra;
	int		total;
	int		i;

	total = 0;
	i = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			gra = getarg(arg, s, i);
			total += function2(s, i, gra);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			total++;
		}
		i++;
	}
	va_end(arg);
	return (total);
}

// int main()
// {
// 	printf("%d",ft_printf("%p",""));
// }