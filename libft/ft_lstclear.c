/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:17:15 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/16 15:41:57 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*tampon;

	if (!lst)
		return ;
	else
	{
		while (*lst)
		{
			tampon = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tampon;
		}
	}
	return ;
}
