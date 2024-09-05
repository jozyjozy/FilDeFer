/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:49:14 by jlarue            #+#    #+#             */
/*   Updated: 2023/01/31 14:59:17 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || y > 1080 || x < 0 || y < 0)
	{
		return ;
	}
	dst = data->px->addr + (y * data->px->line_length + x
			* (data->px->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_atoihx(const char *nptr)
{
	int		i;
	int		k;
	char	*baseref;
	int		result;

	i = 0;
	result = 0;
	baseref = "0123456789abcdef";
	while (nptr[i] != ',' && nptr[i] != '\n' && nptr[i] != ' ' && nptr[i])
		i++;
	if (nptr[i] == ',')
		i = i + 3;
	else
		return (16777215);
	while ((nptr[i] >= '0' && nptr[i] <= '9')
		|| (ft_tolower((int)nptr[i]) >= 'a' && ft_tolower((int)nptr[i]) <= 'f'))
	{
		k = 0;
		while (ft_tolower((int)nptr[i]) != baseref[k])
			k++;
		result = result * 16 + k;
		i++;
	}
	return (result);
}

void	calcul_x(t_data *data, int i, int k, int tmp)
{
	data->coor[i][k].x
		= center_v()
		+ ((i * 20 * data->ty / data->dist)
			- (tmp * 10 * data->alt_multi / data->dist)
			+ data->movex)
		* data->z / data->dz;
	data->coor[i][k].nb = tmp;
}

void	calcul_y(t_data *data, int i, int k, int j)
{
	data->coor[i][k].y
		= center_h() + ((k * 20 / data->dist
				- (i * 10 * data->tx / data->dist) + data->movey)
			* data->z) / data->dz;
	data->coor[i][k].fin = 1;
	data->coor[i][k].color = ft_atoihx(&data->map[i][j]);
}

int	ft_adjusting_coefs(t_data *data)
{
	if (data->dim[0] * data->dim[1] < 500)
		return (1);
	if (data->dim[0] * data->dim[1] < 1000)
		return (2);
	if (data->dim[0] * data->dim[1] < 2000)
		return (3);
	if (data->dim[0] * data->dim[1] < 10000)
		return (4);
	if (data->dim[0] * data->dim[1] < 20000)
		return (5);
	if (data->dim[0] * data->dim[1] >= 20000)
		return (10);
	return (1);
}
