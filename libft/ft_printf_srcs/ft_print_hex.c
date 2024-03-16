/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:25:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Convert n in hexadecimal number string and print it.
Flag '+' and ' ' are NOT supported.
*/
int	ft_print_hex(unsigned int n, t_printf_lst *lst)
{
	char	*hex_nbr;

	if (lst->precision == 0 && n == 0)
		return (ft_print_zero_precision_fd(lst, 1));
	hex_nbr = ft_itoa_hex((long unsigned int)n);
	return (ft_print_hex_format(hex_nbr, lst));
}
