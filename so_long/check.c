/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:36:14 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/10 15:37:09 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	from_check_wall_map(t_data *data, int i, int j)
{
	while (data->array[i])
	{
		if (data->array[i][0] != '1')
			return (1);
		if (data->array[i][data->size_x - 1] != '1')
			return (1);
		while (data->array[0][j] && j < data->size_x - 1)
		{
			if (data->array[0][j] != '1')
				return (1);
			j++;
		}
		j = 0;
		while (data->array[data->size_y - 1][j])
		{
			if (data->array[data->size_y - 1][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->size_x < data->size_y + 1)
	{
		printf("map not rect\n");
		free(data->array);
		exit(1);
	}
	return (from_check_wall_map(data, i, j));
}

void	check_map(t_data *data, int i, int j)
{
	if (data->array[i][j] == 'C' || data->array[i][j] == 'E')
		data->score++;
	if (data->map_cpy[i - 1][j] != '1')
	{
		data->map_cpy[i - 1][j] = '1';
		check_map(data, i - 1, j);
	}
	if (data->map_cpy[i + 1][j] != '1')
	{
		data->map_cpy[i + 1][j] = '1';
		check_map(data, i + 1, j);
	}
	if (data->map_cpy[i][j + 1] != '1')
	{
		data->map_cpy[i][j + 1] = '1';
		check_map(data, i, j + 1);
	}
	if (data->map_cpy[i][j - 1] != '1')
	{
		data->map_cpy[i][j - 1] = '1';
		check_map(data, i, j - 1);
	}
}

void	check_check_func(t_data *data)
{
	if (check_wall_map(data) == 1)
	{
		ft_printf("/********** ERROR MAP **********/");
		exit(1);
	}
	check_map(data, data->p_i, data->p_j);
	if (data->exit_player > 2)
	{
		ft_printf("/******** 2PLAYER or 2EXIT ********/");
		exit(1);
	}
	if (data->score != (data->collect + 1))
	{
		printf("%d %d \n", data->score, data->collect);
		ft_printf("/******* NOT FOUND SOULUTION MAP *******/");
		exit(1);
	}
}
