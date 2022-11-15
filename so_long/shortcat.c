/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:05:08 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/10 15:31:42 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*f(int i)
{
	if (i == 0)
		return ("at/wall.xpm");
	if (i == 1)
		return ("at/wallin.xpm");
	if (i == 2)
		return ("at/wallout.xpm");
	if (i == 6)
		return ("at/weapon_2.xpm");
	if (i == 5)
		return ("at/exit.xpm");
	if (i == 4)
		return ("at/collect.xpm");
	if (i == 3)
		return ("at/weapon.xpm");
	return (0);
}

void	loadat(t_data *data)
{
	data->at = malloc(TOTAL * sizeof(void *));
	data->at[WALL] = mlx_xpm_file_to_image(data->mlx, f(0), &data->w, &data->w);
	data->at[WAIN] = mlx_xpm_file_to_image(data->mlx, f(1), &data->w, &data->w);
	data->at[WOUT] = mlx_xpm_file_to_image(data->mlx, f(2), &data->w, &data->w);
	data->at[WPLY] = mlx_xpm_file_to_image(data->mlx, f(3), &data->w, &data->w);
	data->at[LWPY] = mlx_xpm_file_to_image(data->mlx, f(6), &data->w, &data->w);
	data->at[EXIT] = mlx_xpm_file_to_image(data->mlx, f(5), &data->w, &data->w);
	data->at[COLL] = mlx_xpm_file_to_image(data->mlx, f(4), &data->w, &data->w);
}

int	chartoasset(char c)
{
	if (c == '1')
		return (WALL);
	else if (c == '0')
		return (WOUT);
	else if (c == 'C')
		return (COLL);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'P')
		return (LWPY);
	return (0);
}
