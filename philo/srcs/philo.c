/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/21 14:36:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	exit_code;

	exit_code = 0;
	if (argc == 5 || argc == 6)
	{
		if (arg_format_is_wrong(argc, argv))
			return (1);
		exit_code = start_simulation(argc, argv);
	}
	else
		printf("Error: wrong number of argument.\n");
	return (exit_code);
}

int	arg_format_is_wrong(int argc, char **argv)
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
				printf("Error: (%s) Format.", argv[i]);
				printf(" Argument has to be numbers\n");
				return (1);
			}
			j++;
		}
		if (ft_atoi(argv[i]) == 0)
		{
			printf("Error: (%s) Format. Arg must be bigger than 0\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	start_simulation(int argc, char **argv)
{
	t_shared_var	*shared;
	pthread_t		*th;
	int				i;
	int				exit_code;

	exit_code = 0;
	th = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!th)
		return (1);
	shared = new_shared_variable(argc, argv);
	if (!shared)
	{
		free(th);
		return (1);
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		create_thread(shared, th, i);
		i++;
	}
	exit_code = wait_thread_ending(th, argv);
	clean(th, shared);
	return (exit_code);
}

void	create_thread(t_shared_var *shared, pthread_t *th, int i)
{
	t_philo			*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo)
	{
		init_philo(philo, shared, i);
		if (pthread_create(th + i, NULL, &routine, philo) != 0)
		{
			printf("Error: Failed to create thread number %d\n", i);
		}
	}
	else
		*(shared->run_simulation) = 0;
}
