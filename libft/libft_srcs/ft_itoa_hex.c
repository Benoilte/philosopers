/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:11:47 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Convert long unsigned integer 'luint' in its hexadecimal value
and return in its representative string NUL-terminated
ft_itoa_uint(42) => "2a" | ft_itoa_uint(-10) = "fffffff6"
*/
char	*ft_itoa_hex(long unsigned int luint)
{
	char				*str_num;
	char				*str_hex;
	long unsigned int	luint_cpy;
	int					str_len;

	str_len = 0;
	luint_cpy = luint;
	str_hex = "0123456789abcdef";
	if (luint == 0)
		return (ft_strdup("0"));
	while (luint_cpy)
	{
		luint_cpy /= 16;
		str_len++;
	}
	str_num = ft_calloc((str_len + 1), sizeof(char));
	if (!str_num)
		return ((void *)0);
	str_num[str_len] = '\0';
	while (luint)
	{
		str_num[--str_len] = str_hex[luint % 16];
		luint /= 16;
	}
	return (str_num);
}
