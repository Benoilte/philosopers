/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:29:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
copies up to dstsize - 1 characters from the string src to dst.
return the total length of the strings it tried to create.
If the return value is >= dstsize, the output string has been truncated.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	len;

	i = 0;
	if (size)
	{
		while (src[i] && (size - 1) != i)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}
