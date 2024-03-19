/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/19 18:30:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 5)
	{
		if (args_are_wrong(argc, argv))
			return (1);
		printf("argument without limitation of eating\n");
	}
	else if (argc == 6)
	{
		if (args_are_wrong(argc, argv))
			return (1);
		printf("argument eating limitation\n");
	}
	else
		printf("Error: wrong number of argument.\n");
}

int	args_are_wrong(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error: (%s) Wrong format.", argv[i]);
				printf(" Argument has to be numbers\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
