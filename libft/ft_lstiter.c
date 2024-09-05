/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:44:16 by jlarue            #+#    #+#             */
/*   Updated: 2022/11/16 15:47:08 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tampon;

	if (!lst)
		return ;
	else
	{
		while (lst)
		{
			tampon = lst->next;
			f(lst->content);
			lst = tampon;
		}
	}
	return ;
}
