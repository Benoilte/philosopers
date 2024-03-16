/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:36:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_isspace(char c);

/*
Return the string in params in a corresponding long
*/
long	ft_atoli(const char *str)
{
	long	num;
	int		sign;

	while (ft_check_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = (10 * num) + (*str - 48);
		str++;
	}
	return (num *= sign);
}

static int	ft_check_isspace(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "\t\n\v\f\r ";
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
