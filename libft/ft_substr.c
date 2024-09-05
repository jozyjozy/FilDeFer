/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:33:31 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/15 12:48:18 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb;
	unsigned int	j;
	size_t			string_len;

	j = 0;
	string_len = ft_strlen((char *)s);
	if (string_len < start + len)
		len = string_len - start;
	if (start > string_len)
		return (ft_strdup(""));
	sb = malloc(sizeof(char) * (len + 1));
	if (!sb)
		return (NULL);
	if (start < string_len)
	{
		while ((start + j) < (start + (unsigned int)len) && s[start + j])
		{
			sb[j] = s[start + j];
			j++;
		}
	}
	sb[j] = '\0';
	return (sb);
}
