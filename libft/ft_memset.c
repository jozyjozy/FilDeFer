/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:59:11 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/21 14:09:53 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*begin;
	size_t			i;

	i = 0;
	begin = s;
	while (n > i)
	{
		begin[i] = c;
		i++;
	}
	return (s);
}
