/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/02 16:34:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Add new elem. at the end of the list.
set new elem. as first elem. of the list if *lst is null.
Set new->next as null and new->str = str
*/
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str)
{
	t_gnl_lst	*last;
	t_gnl_lst	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
	{
		return ;
	}
	ft_strlcpy(new->str, str, ft_strlen(str) + 1);
	new->next = (void *)0;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	*ft_gnl_lstclear(t_gnl_lst **lst)
{
	t_gnl_lst	*next_el;

	if (!lst)
		return ((void *)0);
	while (*lst)
	{
		next_el = (*lst)->next;
		free(*lst);
		*lst = next_el;
	}
	free(*lst);
	*lst = (void *)0;
	return ((void *)0);
}

/*
Return the sum of all str member length.
*/
int	ft_count_line_chars(t_gnl_lst *lst)
{
	int			len;
	t_gnl_lst	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	len = 0;
	while (tmp)
	{
		len += ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (len);
}
