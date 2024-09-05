/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:56:12 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/16 16:14:12 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*dst;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	dst = (void *)malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, nmemb * size);
	return (dst);
}
