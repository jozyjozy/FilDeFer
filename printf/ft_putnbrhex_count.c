/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:50 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/23 15:08:07 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbhex_small(unsigned long n)
{
	if (n / 16)
		return (ft_putnbhex_small(n / 16) + ft_putnbhex_small(n % 16));
	if (n < 10)
		ft_putchar_fd((n) + '0', 1);
	if (n >= 10 && n < 16)
		ft_putchar_fd((n % 10) + 'a', 1);
	return (1);
}

int	ft_putnbhex_capital(unsigned long n)
{
	if (n / 16)
		return (ft_putnbhex_capital(n / 16) + ft_putnbhex_capital(n % 16));
	if (n < 10)
		ft_putchar_fd((n) + '0', 1);
	if (n >= 10 && n < 16)
		ft_putchar_fd((n % 10) + 'A', 1);
	return (1);
}
