/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/05 14:24:39 by bebrandt         ###   ########.fr       */
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
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
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
	t_data			*shared;
	pthread_t		*th;
	pthread_t		monitor;
	int				exit_code;

	exit_code = 0;
	shared = new_data(argc, argv);
	if (!shared)
		return (1);
	th = (pthread_t *)malloc(sizeof(pthread_t) * shared->n_philo);
	if (!th)
	{
		clean(NULL, shared);
		return (1);
	}
	if (pthread_create(&monitor, NULL, &control_simulation, shared) != 0)
	{
		printf("Error: Failed to create monitor\n");
		clean(th, shared);
		return (1);
	}
	if (start_routine(shared, th))
		*(shared->run_simulation) = 0;
	exit_code = wait_thread_end(th, monitor, shared);
	clean(th, shared);
	return (exit_code);
}

int	start_routine(t_data *shared, pthread_t *th)
{
	t_philo			**philosophers;
	int				i;

	philosophers = (t_philo **)malloc(sizeof(t_philo *) * shared->n_philo);
	if (!philosophers)
		return (1);
	if (init_philo(philosophers, shared))
		return (1);
	i = 0;
	gettimeofday(&(shared->start), NULL);
	set_last_meal(shared);
	while (i < shared->n_philo)
	{
		if (pthread_create(th + i, NULL, &routine, philosophers[i]) != 0)
		{
			printf("Error: Failed to create philosopher number %d\n", i);
			return (1);
		}
		i++;
	}
	free(philosophers);
	return (0);
}
