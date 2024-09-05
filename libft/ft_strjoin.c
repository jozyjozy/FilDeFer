/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:55:00 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/15 12:53:33 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = ft_strlen((char *)s1);
	i = ft_strlen((char *)s2);
	newstr = malloc(sizeof(char) * (i + j + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		newstr[i + j] = s2[j];
	newstr[i + j] = '\0';
	return (newstr);
}
