/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:39:49 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/10 15:31:30 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//*********************** key hook ******************//
void	take(t_data *data, int i, int j, int asset)
{
	int	x;

	if (data->array[data->p_i + i][data->p_j + j] != '1')
	{
		if (data->array[data->p_i + i][data->p_j + j] == 'C')
			data->eat_collect++;
		x = chartoasset(data->array[data->p_i][data->p_j]);
		putimage(data, data->p_j, data->p_i, x);
		if (j == 1)
			data->p_j++;
		else if (j == -1)
			data->p_j--;
		if (i == 1)
			data->p_i++;
		else if (i == -1)
			data->p_i--;
		putimage(data, data->p_j, data->p_i, asset);
		data->move++;
	}
}
//left 0 // bottom 1 //right  2// top 13// esc 53

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 0)
		take(data, 0, -1, LWPY);
	else if (keycode == 1)
		take(data, 1, 0, WPLY);
	else if (keycode == 2)
		take(data, 0, 1, WPLY);
	else if (keycode == 13)
		take(data, -1, 0, WPLY);
	else if (keycode == 53)
	{
		ft_printf("\n/************* EXIT GAME *************/");
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	ft_printf("\33[2K\rCOLLECT:(%d) MOVEING:(%d)", data->eat_collect, data->move);
	if (data->array[data->p_i][data->p_j] == 'E'
		&& data->eat_collect == data->collect)
	{
		ft_printf("\n/************** YOU WIN **************/");
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}

void	putimage(t_data *data, int j, int i, int asset)
{
	int	x;
	int	y;

	x = (63 * i);
	y = (63 * j);
	if (data->array[i][j] == 'C' && (asset == WPLY || asset == LWPY))
	{
		data->array[i][j] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->at[WOUT], y, x);
	}
	else if (asset == COLL || asset == EXIT)
		mlx_put_image_to_window(data->mlx, data->win, data->at[WOUT], y, x);
	if (data->array[i][j] == 'P')
	{
		data->array[i][j] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->at[WOUT], y, x);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->at[asset], y, x);
}
