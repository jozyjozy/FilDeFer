/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:08:57 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 15:41:44 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx-linux/mlx.h"

void	main_ph_finish(t_data data, char *argv)
{
	int	i;

	i = 0;
	data.map = getmap_char(argv, data.dim[0]);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "FDF");
	fill_coor(&data);
	drawing_line(&data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_key_hook(data.win, &escape_key, &data);
	mlx_hook(data.win, 17, (1L << 17), &cross_kill, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.px->img, 0, 0);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.px->img);
	mlx_destroy_display(data.mlx);
	messyfree(data.coor, data.dim);
	free(data.mlx);
	while (data.map[i])
	{
		free(data.map[i]);
		i++;
	}
	free(data.px);
	free(data.dim);
	free(data.map[i]);
	free(data.map);
}

void	ft_move2(t_data *data, int keysystem)
{
	if (keysystem == 65453)
	{
		if (data->z > 1)
			data->z -= 1;
		else
			data->dz += 1;
	}
	if (keysystem == 97)
		data->tx++;
	if (keysystem == 119)
		data->ty--;
	if (keysystem == 100)
		data->tx--;
	if (keysystem == 115)
		data->ty++;
	if (keysystem == 109)
		data->alt_multi++;
	if (keysystem == 110)
		data->alt_multi--;
	drawing_line_clear(data);
	fill_coor(data);
	drawing_line(data);
	mlx_put_image_to_window(data->mlx, data->win, data->px->img, 0, 0);
}

void	ft_move3(t_data *data, int keysystem)
{
	if (keysystem == 114)
	{
		drawing_line_clear(data);
		fill_coor(data);
		drawing_line_rand_c(data);
		mlx_put_image_to_window(data->mlx, data->win, data->px->img, 0, 0);
	}
}
