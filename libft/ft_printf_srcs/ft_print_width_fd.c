/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:36:39 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Print width filled with char '0' or ' '
*/
void	ft_print_width_fd(int width, int fd, int flag_zero)
{
	while (width)
	{
		if (flag_zero)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		width--;
	}
}
