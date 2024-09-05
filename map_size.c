/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:28:45 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 12:02:03 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rmv_space(int j, char *str1)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str1[i])
	{
		if (str1[i] == ' ' && str1[j] != ' ')
			k++;
		i++;
	}
	return (k);
}

int	*check_map_size(char *str)
{
	int		i;
	int		*inter;
	char	*str1;
	int		j;

	inter = malloc(sizeof(int) * 2);
	if (!inter)
		return (NULL);
	j = 0;
	i = open(str, O_RDONLY);
	str1 = get_next_line(i);
	while (str1[j])
		j++;
	inter[1] = rmv_space(j, str1);
	free(str1);
	j = 1;
	while (str1)
	{
		str1 = get_next_line(i);
		free(str1);
		j++;
	}
	inter[0] = j;
	close(i);
	return (inter);
}

char	**getmap_char(char *str, int nbL)
{
	int		i;
	char	**str1;
	int		j;

	j = 0;
	i = open(str, O_RDONLY);
	str1 = malloc(sizeof(char *) * nbL);
	if (!str1)
		return (NULL);
	while (j < nbL)
	{
		str1[j] = get_next_line(i);
		j++;
	}
	close(i);
	return (str1);
}

void	fill_coor(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	while (data->map[i][0])
	{
		j = 0;
		k = 0;
		while (data->map[i][j])
		{
			while (data->map[i][j] == ' ')
				j++;
			tmp = ft_atoi(&data->map[i][j]);
			calcul_x(data, i, k, tmp);
			calcul_y(data, i, k, j);
			while (data->map[i][j] != ' ' && data->map[i][j])
				j++;
			k++;
		}
		i++;
	}
}
