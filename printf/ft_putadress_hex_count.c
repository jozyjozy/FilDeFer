/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_hex_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:31:32 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/23 16:32:09 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_addresshex(unsigned long n)
{
	int	size;

	size = 0;
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_putbase_hex_adress(unsigned long str)
{
	char			*result;
	char			*base;
	int				i;

	base = "0123456789abcdef";
	if (str == 0)
	{
		result = malloc(sizeof(char) * (2));
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	i = ft_count_addresshex(str);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	while (i >= 0)
	{
		result[i] = base[str % 16];
		str = str / 16;
		i--;
	}
	return (result);
}

int	ft_putadress_hex_count(void	*str)
{
	char			*newstr;
	unsigned int	i;

	i = ft_count_addresshex((unsigned long)str);
	newstr = ft_putbase_hex_adress((unsigned long)str);
	if (!newstr)
		return (-1);
	if (!str)
	{
		write(1, "(nil)", 5);
		i = 5;
	}
	else
	{
		i += write(1, "0x", 2);
		write(1, newstr, i - 2);
	}
	if (newstr)
		free(newstr);
	return (i);
}
