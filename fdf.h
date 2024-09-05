/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:18:52 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 15:56:39 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WH
#  define WH 0xFFFFFFF
# endif

# include <stdio.h>
# include <unistd.h>
# include <assert.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <X11/keysymdef.h>

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"

typedef struct s_px
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_px;

typedef struct s_coor
{
	int	x;
	int	y;
	int	nb;
	int	color;
	int	fin;
}	t_coor;

typedef struct s_brseam
{
	int	dx;
	int	dy;
	int	incx;
	int	incy;
	int	e;
	int	e2;
}	t_brseam;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	struct s_coor	**coor;
	t_px			*px;
	char			**map;
	int				*dim;
	int				z;
	int				dz;
	int				tx;
	int				ty;
	int				alt_multi;
	int				movex;
	int				movey;
	int				dist;
}	t_data;

void	drawing_line_rand_c(t_data *data);
int		random_c(int i, t_data *data, t_coor px1);
void	ft_bresenham_rand(t_data *data, t_coor pixel1, t_coor pixel2);
int		check_values(char *str);
int		ft_adjusting_coefs(t_data *data);
void	calcul_x(t_data *data, int i, int k, int tmp);
void	calcul_y(t_data *data, int i, int k, int j);
t_coor	messylocfin(t_coor coor);
t_coor	messyloc2(t_coor coor);
void	ft_move2(t_data *data, int keysystem);
int		center_v(void);
int		center_h(void);
int		loop(void *data);
int		escape_key(int keysystem, t_data *data);
int		cross_kill(t_data *data);
void	main_ph_finish(t_data data, char *argv);
int		ft_atoihx(const char *nptr);
void	drawing_line_clear(t_data *data);
void	ft_bresenham_clear(t_data *data, t_coor pixel1, t_coor pixel2);
void	ft_bresenham(t_data *data, t_coor pixel1, t_coor pixel2);
int		ft_abs(int i);
int		ft_inc(int i);
int		rmv_space(int j, char *str1);
t_coor	**messyloc(int *dim, t_coor **coor);
void	fill_coor(t_data *data);
void	drawing_line(t_data *data);
char	**getmap_char(char *str, int nbL);
int		*check_map_size(char *argv1);
int		main(int argc, char **argv);
int		check_map_exists(int argc, char **argv);
void	messyfree(t_coor **coor, int *dim);
void	ft_move(t_data *data, int keysystem);
void	ft_move3(t_data *data, int keysystem);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
