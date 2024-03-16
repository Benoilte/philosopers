/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:01:30 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:07:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
check if 'c' char is in 'set' string. if yes return 1 - if no return 0
check_set('a', "dsa") ==> 1
check_set('h', "dsa") ==> 0
*/
static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
Remove chars specified in 'set' string,
from the start AND the end of 's1' string
without removing the chars from the 'set' that are in the middle of 's1'
ft_strim("abbabaHello Worldabbbeeea", "abe") ==> "Hello World"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (check_set(s1[start], set))
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (check_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
