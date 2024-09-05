/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:11:58 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/23 15:45:05 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list arguments, char c)
{
	size_t	size_of_argument;

	size_of_argument = 0;
	if (c == 'd' || c == 'i')
		size_of_argument = ft_putnbr_count(va_arg(arguments, int));
	if (c == 's')
		size_of_argument = ft_putstr_count(va_arg(arguments, char *));
	if (c == 'c')
		size_of_argument = ft_putchar_count(va_arg(arguments, int));
	if (c == 'p')
		size_of_argument = ft_putadress_hex_count(va_arg(arguments, void *));
	if (c == 'x')
		size_of_argument = ft_putnbhex_small(va_arg(arguments, unsigned int));
	if (c == 'X')
		size_of_argument = ft_putnbhex_capital(va_arg(arguments, unsigned int));
	if (c == 'u')
		size_of_argument = ft_putunsnbr_count(va_arg(arguments, unsigned int));
	if (c == '%')
		size_of_argument = ft_putchar_count('%');
	return (size_of_argument);
}

int	ft_checkinput(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else if (c != '\0')
		return (2);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		return_value;
	int		i;
	va_list	arguments;

	i = -1;
	return_value = 0;
	if (!str)
		return (-1);
	va_start(arguments, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_checkinput(str[i + 1]) == 1)
			return_value += ft_convert(arguments, str[++i]);
		else if (str[i] == '%' && ft_checkinput(str[i + 1]) == 2)
			return_value += ft_convert(arguments, str[i]);
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else if (str[i] != '%')
				return_value += ft_putchar_count(str[i]);
	}
	va_end(arguments);
	return (return_value);
}
