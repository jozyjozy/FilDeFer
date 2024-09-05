/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:39:04 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/15 15:11:45 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		length;
	char		*result;

	i = 0;
	length = ft_strlen((char *)s);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	ft_bzero(result, length);
	while (i < length)
	{
		result[i] += f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
