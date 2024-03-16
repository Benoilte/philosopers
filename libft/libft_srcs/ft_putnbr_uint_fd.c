/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:04:55 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Writes the unsigned int 'uint' on the file descriptor 'fd'
*/

void	ft_putnbr_uint_fd(unsigned int uint, int fd)
{
	if (uint == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (uint > 9)
		ft_putnbr_uint_fd(uint / 10, fd);
	ft_putchar_fd(((uint % 10) + 48), fd);
}
