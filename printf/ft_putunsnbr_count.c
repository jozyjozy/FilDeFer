/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:48:28 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/22 13:25:25 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsnbr(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int	ft_putunsnbr_count(unsigned int n)
{
	char	rec;
	int		size;

	size = ft_count_unsnbr(n);
	if (n > 9)
	{
		rec = n % 10 + 48;
		n = n / 10;
		ft_putunsnbr_count(n);
		write(1, &rec, 1);
	}
	else
	{
		rec = n + 48;
		write(1, &rec, 1);
	}
	return (size);
}
