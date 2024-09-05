/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:25:51 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/14 11:40:35 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	match;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	match = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == match)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
