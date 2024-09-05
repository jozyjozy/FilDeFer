/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:51:51 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 13:07:40 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_line_clear(t_data *data)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (i < data->dim[0] - 2)
	{
		while (j < data->dim[1])
		{
			if (j < data->dim[1] - 1 && !(data->coor[i][j + 1].fin != 1))
				ft_bresenham_clear(data, data->coor[i][j],
					data->coor[i][j + 1]);
			if (i < data->dim[0] - 3)
				ft_bresenham_clear(data, data->coor[i][j],
					data->coor[i + 1][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	drawing_line_rand_c(t_data *data)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (i < data->dim[0] - 2)
	{
		while (j < data->dim[1])
		{
			if (j < data->dim[1] - 1 && !(data->coor[i][j + 1].fin != 1))
				ft_bresenham_rand(data, data->coor[i][j],
					data->coor[i][j + 1]);
			if (i < data->dim[0] - 3)
				ft_bresenham_rand(data, data->coor[i][j],
					data->coor[i + 1][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
