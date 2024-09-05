/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:56:12 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/15 11:12:14 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *)s) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	while ((char)s[i])
	{
		dst[i] = (char)s[i];
		i++;
	}
	dst[i] = (char)s[i];
	return (dst);
}
