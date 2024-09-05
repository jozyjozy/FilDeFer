/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:45:15 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/21 14:14:52 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!big && !len)
		return (NULL);
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	pos = 0;
	while (big[pos] != '\0' && (size_t)pos < len)
	{
		if (big[pos] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[pos + i] == little[i]
				&& (size_t)(pos + i) < len)
				++i;
			if (little[i] == '\0')
				return ((char *)&big[pos]);
		}
		++pos;
	}
	return (0);
}
