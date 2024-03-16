/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:14:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Convert unsigned integer 'uint' in its representative string NUL-terminated
ft_itoa_uint(42) => "42" | ft_itoa_uint(-10) = "4294967286"
*/
char	*ft_itoa_uint(unsigned int uint)
{
	char			*str_num;
	unsigned int	uint_cpy;
	int				str_len;

	str_len = 0;
	uint_cpy = uint;
	if (uint == 0)
		return (ft_strdup("0"));
	while (uint_cpy)
	{
		uint_cpy /= 10;
		str_len++;
	}
	str_num = ft_calloc((str_len + 1), sizeof(char));
	if (!str_num)
		return ((void *)0);
	str_num[str_len] = '\0';
	while (uint)
	{
		str_num[--str_len] = (uint % 10) + 48;
		uint /= 10;
	}
	return (str_num);
}
