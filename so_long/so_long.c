/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:12 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/10 15:31:55 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpy_line_in_array(t_data *data, int i, int j, char **arr)
{
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P' || arr[i][j] == 'E')
				data->exit_player++;
			if (arr[i][j] == 'C')
				data->collect++;
			if (arr[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			putimage(data, j, i, chartoasset(arr[i][j]));
			j++;
		}
		i++;
	}
}

void	part1_show_to_win(t_data *data, int i, int j, char **arr)
{
	char	**arr_cpy;
	int		f;

	f = 0;
	arr_cpy = ft_calloc(1024, 1024);
	while (arr[f])
	{
		arr_cpy[f] = ft_copy_str(arr[f]);
		f++;
	}
	data->map_cpy = arr_cpy;
	data->mlx = mlx_init();
	x_y(data);
	loadat(data);
	cpy_line_in_array(data, i, j, arr);
	check_check_func(data);
	mlx_hook(data->win, 2, 0, &key_hook, data);
	mlx_loop(data->mlx);
}

void	show_to_window(int x, int y, char *filename)
{
	int		fd;
	char	**arr;
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data.size_y = y;
	data.size_x = x;
	data.score = 0;
	data.w = 10;
	arr = ft_calloc(1024, 5);
	fd = open(filename, O_RDONLY);
	arr[i] = get_next_line(fd);
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
		arr[i] = get_next_line(fd);
	}
	data.array = arr;
	i = 0;
	part1_show_to_win(&data, i, j, arr);
}

void	len_long_larg(char *filename)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	fd = open(filename, O_RDONLY);
	x = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
		x = len_size(line);
	}
	show_to_window(x, y, filename);
}

int	main(int arc, char **arv)
{
	if (arc > 2)
		return (0);
	if (ft_ft_strnstr(arv[1], ".ber") != 1)
		ft_printf("/****** ERROR NAME FILE ******/ ");
	else
		len_long_larg(arv[1]);
	return (0);
}
