/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:01:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Return the pointer of last element of the linked list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*el_lst;

	if (!lst)
		return ((void *)0);
	el_lst = lst;
	while (el_lst->next)
		el_lst = el_lst->next;
	return (el_lst);
}
