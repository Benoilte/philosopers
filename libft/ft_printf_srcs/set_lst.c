/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:51:24 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/31 18:25:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_lst	*set_new_lst(t_printf_lst *lst)
{
	lst = (t_printf_lst *)malloc(sizeof(t_printf_lst));
	if (!lst)
		return ((void *)0);
	lst->flag_zero = 0;
	lst->flag_plus = 0;
	lst->flag_minus = 0;
	lst->flag_space = 0;
	lst->flag_hash = 0;
	lst->width = 0;
	lst->precision = -1;
	lst->specifier = 0;
	lst->next = (void *)0;
	return (lst);
}

void	ft_set_ptr_lst(t_printf_lst *lst)
{
	lst->flag_zero = 0;
	lst->precision = -1;
}
