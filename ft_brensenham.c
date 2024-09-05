/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brensenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:34:12 by jlarue            #+#    #+#             */
/*   Updated: 2023/02/03 15:56:25 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(t_data *data, t_coor pixel1, t_coor pixel2)
{
	t_brseam	bm;

	bm.dx = pixel2.x - pixel1.x;
	bm.dy = pixel2.y - pixel1.y;
	bm.incx = ft_inc(bm.dx);
	bm.incy = ft_inc(bm.dy);
	bm.dx = ft_abs(bm.dx);
	bm.dy = ft_abs(bm.dy);
	bm.e = bm.dx - bm.dy;
	ft_mlx_pixel_put(data, pixel1.y, pixel1.x, pixel1.color);
	while (pixel1.x != pixel2.x || pixel1.y != pixel2.y)
	{
		bm.e2 = bm.e * 2;
		if (bm.e2 > -bm.dy)
		{
			bm.e -= bm.dy;
			pixel1.x += bm.incx;
		}
		if (bm.e2 < bm.dx)
		{
		bm.e += bm.dx;
		pixel1.y += bm.incy;
		}
		ft_mlx_pixel_put(data, pixel1.y, pixel1.x, pixel1.color);
	}
}

void	ft_bresenham_clear(t_data *data, t_coor pixel1, t_coor pixel2)
{
	t_brseam	bm;

	bm.dx = pixel2.x - pixel1.x;
	bm.dy = pixel2.y - pixel1.y;
	bm.incx = ft_inc(bm.dx);
	bm.incy = ft_inc(bm.dy);
	bm.dx = ft_abs(bm.dx);
	bm.dy = ft_abs(bm.dy);
	bm.e = bm.dx - bm.dy;
	ft_mlx_pixel_put(data, pixel1.y, pixel1.x, 0);
	while (pixel1.x != pixel2.x || pixel1.y != pixel2.y)
	{
		bm.e2 = bm.e * 2;
		if (bm.e2 > -bm.dy)
		{
			bm.e -= bm.dy;
			pixel1.x += bm.incx;
		}
		if (bm.e2 < bm.dx)
		{
		bm.e += bm.dx;
		pixel1.y += bm.incy;
		}
		ft_mlx_pixel_put(data, pixel1.y, pixel1.x, 0);
	}
}

void	ft_bresenham_rand(t_data *data, t_coor px1, t_coor px2)
{
	t_brseam	bm;

	bm.dx = px2.x - px1.x;
	bm.dy = px2.y - px1.y;
	bm.incx = ft_inc(bm.dx);
	bm.incy = ft_inc(bm.dy);
	bm.dx = ft_abs(bm.dx);
	bm.dy = ft_abs(bm.dy);
	bm.e = bm.dx - bm.dy;
	ft_mlx_pixel_put(data, px1.y, px1.x, random_c(px1.color, data, px1));
	while (px1.x != px2.x || px1.y != px2.y)
	{
		bm.e2 = bm.e * 2;
		if (bm.e2 > -bm.dy)
		{
			bm.e -= bm.dy;
			px1.x += bm.incx;
		}
		if (bm.e2 < bm.dx)
		{
		bm.e += bm.dx;
		px1.y += bm.incy;
		}
		ft_mlx_pixel_put(data, px1.y, px1.x, random_c(px1.color, data, px1));
	}
}

int	ft_abs(int i)
{
	if (i < 0)
		i = i * -1;
	return (i);
}

int	ft_inc(int i)
{
	if (i < 0)
		return (-1);
	else
		return (1);
}
