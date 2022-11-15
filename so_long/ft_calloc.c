/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:26:46 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/09 19:02:51 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*be;
	size_t	i;

	be = (char *)b;
	i = 0;
	while (i < len)
	{
		be[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total;

	total = count * size;
	if (size && total / size != count)
		return (0);
	ptr = (void *)malloc((total));
	if (!ptr)
		return (0);
	ft_bzero(ptr, total);
	return (ptr);
}
