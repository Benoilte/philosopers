/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:45:54 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:34 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
copies n bytes from memory area src to memory area dst. Return dst
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char					*str_dst;
	unsigned char					*str_src;
	long unsigned int				i;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
