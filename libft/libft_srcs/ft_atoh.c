/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:51:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/24 15:34:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_sign(char *hex, int *i)
{
	if (hex[*i] == '+' || hex[*i] == '-')
	{
		if (hex[*i] == '-')
		{
			*i += 1;
			return (-1);
		}
		*i += 1;
	}
	return (1);
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

int	ft_atoh(char *hex)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	while (ft_check_isspace(hex[i]))
		i++;
	sign = check_sign(hex, &i);
	while (hex[i] == '0' || hex[i] == 'x')
		i++;
	while ((hex[i]))
	{
		if (ft_isdigit(hex[i]))
			num = (16 * num) + hex[i++] - 48;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			num = (16 * num) + (hex[i++] - 65) + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			num = (16 * num) + (hex[i++] - 97) + 10;
		else
			return (0);
	}
	return (num *= sign);
}
