/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:29:56 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/15 15:53:16 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void	itoa_convert(char *str, long nb_long, unsigned int size, int sign)
{
	str[size] = '\0';
	if (nb_long == 0)
		str[0] = '0';
	while (nb_long > 0)
	{
		str[--size] = nb_long % 10 + '0';
		nb_long /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		size;
	int		sign;
	long	nb_long;

	sign = 1;
	nb_long = (long)nb;
	size = ft_size(nb_long);
	if (nb < 0)
	{
		sign = -1;
		nb_long = (long)nb * -1;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	itoa_convert(str, nb_long, size, sign);
	return (str);
}
