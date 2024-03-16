/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:59:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Locates the last occurence of 'c' in the string 's'. The terminating null 
character is considered to be part of the string. 
Return a pointer to the located character, or NULL if there is no occurence
*/
char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*occ;

	i = 0;
	occ = (void *)0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			occ = ((char *)(str + i));
		i++;
	}
	if ((unsigned char) str[i] == (unsigned char) c)
		occ = ((char *)(str + i));
	return (occ);
}
