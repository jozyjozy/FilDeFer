/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tabtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:07 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 14:16:08 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	**messyloc(int *dim, t_coor **coor)
{
	int	i;
	int	j;

	coor = malloc(sizeof(t_coor *) * dim[0]);
	if (!coor)
		return (NULL);
	i = 0;
	while (i < dim[0])
	{
		coor[i] = malloc(sizeof(t_coor) * (dim[1] + 1));
		if (!coor[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < dim[0])
	{
		j = -1;
		while (++j < dim[1])
			coor[i][j] = messyloc2(coor[i][j]);
		coor[i][j] = messylocfin(coor[i][j]);
		i++;
	}
	return (coor);
}

t_coor	messyloc2(t_coor coor)
{
	coor.x = 0;
	coor.y = 0;
	coor.nb = 0;
	coor.color = 16777215;
	coor.fin = 0;
	return (coor);
}

t_coor	messylocfin(t_coor coor)
{
	coor.x = 0;
	coor.y = 0;
	coor.nb = 0;
	coor.color = 0;
	coor.fin = 0;
	return (coor);
}

void	messyfree(t_coor **coor, int *dim)
{
	int	i;

	i = 0;
	while (i < dim[0])
	{
		free(coor[i]);
		i++;
	}
	free(coor);
}
