/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:11:27 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_needle_occ(const char *s1, const char *needle);

/*
Locates the first occurence of 'needle' in the string 'haystack'.
If 'needle' is an empty string, 'haystack' is returned.
Return a pointer to first char of the first occurene.
NULL is returned if there is no occurence.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (!needle_len)
		return ((char *)haystack);
	while (*haystack && len && (len >= needle_len))
	{
		if (check_needle_occ(haystack, needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return ((void *)0);
}

static int	check_needle_occ(const char *s1, const char *needle)
{
	int	i;

	i = 0;
	while (s1[i] && needle[i])
	{
		if (s1[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}
