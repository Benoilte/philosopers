/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:54:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 13:40:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

/*
Return the string in params in a corresponding int
*/
int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

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

/*
Return the string in params in a corresponding long
*/
long	ft_atoi_long(const char *str)
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

/*
Return non-zero value if 'c' is in 0-9
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
