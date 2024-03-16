/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:47:49 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:06:26 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Locates the first occurence of c in 'str' and return its address
return NULL if no occurence found
*/
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char			*char_str;
	long unsigned int		i;

	char_str = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		if (char_str[i] == (unsigned char) c)
			return ((void *)(str + i));
		i++;
	}
	return ((void *)0);
}
