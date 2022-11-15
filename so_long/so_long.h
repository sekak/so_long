/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:16:11 by asekkak           #+#    #+#             */
/*   Updated: 2022/11/09 18:49:40 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define IMG_W 63
# define IMG_H 63
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define WALL 0
# define WAIN 1
# define WOUT 2
# define WPLY 3
# define LWPY 6
# define COLL 4
# define EXIT 5
# define TOTAL 7

typedef struct s_img
{
	void	*player_p;
	void	*wallin;
	void	*wallout;
	void	*collect;
	void	*wall;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
	int		w;
	int		p_i;
	int		p_j;
	int		size_x;
	int		size_y;
	char	**array;
	void	**at;
	char	**map_cpy;
	int		score;
	int		collect;
	int		eat_collect;
	int		exit_player;
	int		move;
}	t_data;

void	x_y(t_data *data);
void	*ft_calloc(size_t count, size_t size);
char	*get_cur_line(char *str);
char	*get_to_next(char *str);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_copy(char *s1, char *s2, char *ptr);
int		ft_strchr(char *str, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		chartoasset(char c);
char	*ft_copy_str(char *str);
void	check_map(t_data *data, int i, int j);
int		check_wall_map(t_data *data);
int		from_check_wall_map(t_data *data, int i, int j);
void	take(t_data *data, int i, int j, int asset);
int		key_hook(int keycode, t_data *data);
void	putimage(t_data *data, int j, int i, int asset);
int		ft_ft_strnstr(const char *haystack, const char *needle);
int		len_size(char *str);
void	check_check_func(t_data *data);
char	*f(int i);
void	loadat(t_data *data);
int		chartoasset(char c);

#endif