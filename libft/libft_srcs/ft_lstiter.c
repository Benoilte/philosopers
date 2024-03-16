/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:57:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Iterates over the whole list and applies the function f to the content
of each elements.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*el_lst;

	if (!f)
		return ;
	el_lst = lst;
	while (el_lst)
	{
		f(el_lst->content);
		el_lst = el_lst->next;
	}
}
