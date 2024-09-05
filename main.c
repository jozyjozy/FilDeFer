/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:17:51 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/06 11:58:53 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx-linux/mlx.h"

int	loop(void *data)
{
	(void) *data;
	return (0);
}

int	escape_key(int keysystem, t_data *data)
{
	if (keysystem == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	if ((keysystem >= 65361 && keysystem <= 65364)
		|| (keysystem == 65451 || keysystem == 65453)
		|| (keysystem == 97 || keysystem == 119
			|| keysystem == 100 || keysystem == 115
			|| keysystem == 109 || keysystem == 110)
		|| keysystem == 104 || keysystem == 114)
	{
		ft_move(data, keysystem);
		ft_move2(data, keysystem);
		ft_move3(data, keysystem);
	}
	return (0);
}

void	ft_move(t_data *data, int keysystem)
{
	if (keysystem == 65361)
		data->movey -= 25;
	if (keysystem == 65362)
		data->movex -= 25;
	if (keysystem == 65363)
		data->movey += 25;
	if (keysystem == 65364)
		data->movex += 25;
	if (keysystem == 65451)
	{
		if (data->dz > 1)
			data->dz -= 1;
		else
			data->z += 1;
	}
	if (keysystem == 104)
		data->ty = 0;
	drawing_line_clear(data);
	fill_coor(data);
	drawing_line(data);
	mlx_put_image_to_window(data->mlx, data->win, data->px->img, 0, 0);
}

int	cross_kill(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->px->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	messyfree(data->coor, data->dim);
	free(data->mlx);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->px);
	free(data->dim);
	free(data->map[i]);
	free(data->map);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.coor = NULL;
	if (check_map_exists(argc, argv) == 0)
		return (0);
	data.mlx = mlx_init();
	data.px = malloc(sizeof(t_px));
	if (!data.px)
		return (free(data.mlx), 0);
	data.movex = 0;
	data.movey = 0;
	data.z = 1;
	data.dz = 1;
	data.ty = 1;
	data.tx = 1;
	data.alt_multi = 1;
	data.px->img = mlx_new_image(data.mlx, 1920, 1080);
	data.px->addr = mlx_get_data_addr(data.px->img,
			&data.px->bits_per_pixel, &data.px->line_length,
			&data.px->endian);
	data.dim = check_map_size(argv[1]);
	data.dist = ft_adjusting_coefs(&data);
	data.coor = messyloc(data.dim, data.coor);
	main_ph_finish(data, argv[1]);
}
