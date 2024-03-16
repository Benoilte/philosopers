/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:19:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:16 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Print char with its corresponding flag, width.
only flag '-' and width are accepted.
*/
int	ft_print_char(char c, t_printf_lst *lst)
{
	if (lst->flag_minus && lst->width > 1)
	{
		ft_putchar_fd(c, 1);
		ft_print_width_fd(lst->width - 1, 1, 0);
		return (lst->width);
	}
	else if (lst->width > 1)
	{
		ft_print_width_fd(lst->width - 1, 1, 0);
		ft_putchar_fd(c, 1);
		return (lst->width);
	}
	else
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
}
