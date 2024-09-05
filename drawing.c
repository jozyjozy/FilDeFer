/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:54:04 by jlarue            #+#    #+#             */
/*   Updated: 2023/01/30 11:56:56 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_line(t_data *data)
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
				ft_bresenham(data, data->coor[i][j], data->coor[i][j + 1]);
			if (i < data->dim[0] - 3 && data->map[data->dim[0] - 2])
				ft_bresenham(data, data->coor[i][j], data->coor[i + 1][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
