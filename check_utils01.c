/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:05:46 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 16:08:09 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_exists(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Not the good amount of arguments\n", 34);
		return (0);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'f' || argv[1][i - 2] != 'd'
		|| argv[1][i - 3] != 'f'
		|| argv[1][i - 4] != '.')
	{
		write (1, "Bad Extension\n", 14);
		return (0);
	}
	return (check_values(argv[1]));
}

int	check_values(char *str)
{
	int		i;
	char	*str1;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = open(str, O_RDONLY);
	str1 = get_next_line(i);
	if (!str1)
	{
		write(1, "Map is Empty\n", 13);
		close(i);
		return (0);
	}
	free(str1);
	close(i);
	return (1);
}

int	random_c(int i, t_data *data, t_coor px)
{
	if (i == 16777215)
		return (i / 5 + px.x * px.y * 50 + data->dim[0] * data->dim[1]);
	else
		return (i);
}
