/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:21:25 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Convert a pointer into a long unsigned int and convert it in hexadecimal format
Only flag '-' and width are accepted.
*/
int	ft_print_ptr(void *p, t_printf_lst *lst)
{
	uintptr_t	ptr;
	char		*hex_nbr;

	ptr = (uintptr_t)p;
	if (!p)
		hex_nbr = ft_strdup("0");
	else
		hex_nbr = ft_itoa_hex(ptr);
	ft_set_ptr_lst(lst);
	return (ft_print_hex_format(hex_nbr, lst));
}
