/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:20:20 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/16 15:11:55 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		index_start;
	int		index_end;

	index_end = ft_strlen((char *)s1) - 1;
	index_start = 0;
	while (is_trim(s1[index_start], set) == 1 && s1[index_start])
		index_start++;
	while (is_trim(s1[index_end], set) == 1)
		index_end--;
	if (index_end - index_start + 1 > 0)
	{
		dest = malloc(sizeof(char) * (index_end - index_start + 2));
		if (!dest)
			return (NULL);
	}
	else
		return (ft_strdup(""));
	ft_strlcpy(dest, (char *)&s1[index_start], index_end - index_start + 2);
	return (dest);
}
