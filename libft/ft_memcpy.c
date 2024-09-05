/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:22 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/21 13:55:14 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
