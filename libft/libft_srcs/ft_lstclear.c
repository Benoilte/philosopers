/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:55:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/17 17:00:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_del;
	t_list	*next;

	to_del = *lst;
	*lst = NULL;
	while (to_del != NULL)
	{
		next = to_del->next;
		(*del)(to_del->content);
		free(to_del);
		to_del = next;
	}
}
