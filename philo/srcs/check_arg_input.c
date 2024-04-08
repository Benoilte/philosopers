/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:54:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 09:13:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	arg_is_not_valid(int argc, char **argv)
{
	if (arg_number_is_wrong(argc))
		return (ERROR);
	if (arg_format_is_not_digit(argc, argv))
		return (ERROR);
	if (arg_format_is_not_greater_than_zero(argc, argv))
		return (ERROR);
	if (arg_format_is_bigger_than_int_max(argc, argv))
		return (ERROR);
	return (OK);
}

int	arg_number_is_wrong(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of argument.\n");
		return (ERROR);
	}
	return (OK);
}

int	arg_format_is_not_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("Error: (%s) Format.", argv[i]);
				printf(" Argument has to be positive numbers");
				printf(" whitout a sign\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (OK);
}

int	arg_format_is_not_greater_than_zero(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi_long(argv[i]) <= 0)
		{
			printf("Error: (%s) Format. ", argv[i]);
			print_argument_definition(i);
			printf(" argument must be greater than 0\n");
			return (ERROR);
		}
		i++;
	}
	return (OK);
}

int	arg_format_is_bigger_than_int_max(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi_long(argv[i]) > INT_MAX)
		{
			printf("Error: (%s) Format. ", argv[i]);
			print_argument_definition(i);
			printf(" argument must be lower or equal");
			printf(" than int max (%d)\n", INT_MAX);
			return (ERROR);
		}
		i++;
	}
	return (OK);
}
