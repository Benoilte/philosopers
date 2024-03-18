/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/18 17:35:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_isspace(char c);

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
