/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:26:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Print a percent sign with its corresponding flag and width.
only flag '-' and width are accepted.
*/
int	ft_print_percent(t_printf_lst *lst)
{
	(void)lst;
	ft_putchar_fd(lst->specifier, 1);
	return (1);
}
