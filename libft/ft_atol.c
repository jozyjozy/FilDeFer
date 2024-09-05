/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:46:21 by jlarue            #+#    #+#             */
/*   Updated: 2023/01/09 12:09:27 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atol(char *nptr)
{
	int		i;
	int		s;
	long	result;

	i = 0;
	result = 0;
	s = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] > '9' || nptr[i] < '0')
			return (0);
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (s * result);
}
