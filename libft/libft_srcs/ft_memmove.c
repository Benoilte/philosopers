/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:46:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Copies 'len' bytes from string src to string dst. The two strings may overlap; 
the copy is always done in a non-destructive manner. Return dst
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char					*str_dst;
	unsigned char					*str_src;
	long unsigned int				i;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			str_dst[len - 1] = str_src[len - 1];
			len--;
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
