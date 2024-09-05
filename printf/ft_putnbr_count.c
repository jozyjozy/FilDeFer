/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:13:30 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/22 13:06:58 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_nb(int n)
{
	int	result;

	result = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		result = 2;
	while (n / 10)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

int	ft_putnbr_count(int n)
{
	char	rec;
	int		size;

	size = ft_count_nb(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		ft_putnbr_count(n);
	}
	else if (n > 9)
	{
		rec = n % 10 + 48;
		n = n / 10;
		ft_putnbr_count(n);
		write(1, &rec, 1);
	}
	else
	{
		rec = n + 48;
		write(1, &rec, 1);
	}
	return (size);
}
