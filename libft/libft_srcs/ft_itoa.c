/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:48:40 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_fill_num_str(int n, int is_neg);

/*
Convert integer 'n' in its representative string NUL-terminated
ft_itoa(42) => "42" | ft_itoa(-42) => "-42"
*/
char	*ft_itoa(int n)
{
	char	*str_num;
	int		is_neg;

	is_neg = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	else if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else
	{
		if (n < 0)
		{
			is_neg = 1;
			n *= -1;
		}
		str_num = ft_fill_num_str(n, is_neg);
	}
	return (str_num);
}

/*
Fill a string representing the int 'n' - allocate properly the memory
n is always positive, is_neg == 0 if n was positive or 1 if n was negative
ft_fill_num_str(42, 0) => "42" | ft_fill_num_str(42, 1) => "-42"
*/
static char	*ft_fill_num_str(int n, int is_neg)
{
	char	*str;
	int		str_len;
	int		n2;

	n2 = n;
	str_len = is_neg;
	while (n)
	{
		n /= 10;
		str_len++;
	}
	str = ft_calloc((str_len + 1), sizeof(char));
	if (!str)
		return ((void *)0);
	str[str_len] = '\0';
	while (n2)
	{
		str[--str_len] = (n2 % 10) + 48;
		n2 /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
