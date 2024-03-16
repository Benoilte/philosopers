/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:00:53 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Allocate and return a new string from the string 's'.
This new string starts at index 'start' and has a maximum size of 'len'.
NULL is returned if the memory allocation failed.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*dest;

	i = 0;
	s_len = ft_strlen((char *)s);
	if (!s_len || start > s_len - 1)
		return (ft_strdup(""));
	s += start;
	s_len -= start;
	if (len < s_len)
	{
		dest = (char *)malloc((len + 1) * sizeof(char));
		if (!dest)
			return ((void *)0);
		while (s[i] && i < len)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (ft_strdup(s));
}
