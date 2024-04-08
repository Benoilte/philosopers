/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:54:08 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 16:33:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	arg_is_not_valid(int argc, char **argv)
{
	if (arg_number_is_wrong(argc))
		return (EXIT_FAILURE);
	if (arg_format_is_not_digit(argc, argv))
		return (EXIT_FAILURE);
	if (arg_format_is_greater_than_int_max(argc, argv))
		return (EXIT_FAILURE);
	if (arg_format_is_equal_to_zero(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	arg_number_is_wrong(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of argument.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	arg_format_is_equal_to_zero(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi_long(argv[i]) == 0)
		{
			printf("Error: (%s) Format. ", argv[i]);
			print_argument_definition(i);
			printf(" argument must be greater than 0\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	arg_format_is_greater_than_int_max(int argc, char **argv)
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
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
