/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 21:28:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	exit_code;

	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if (args_are_wrong(argc, argv))
			return (1);
		exit_code = simulation(argc, argv);
	}
	else
		printf("Error: wrong number of argument.\n");
	return (exit_code);
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

int	simulation(int argc, char **argv)
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
		philo->id = i;
		philo->n_philo = ft_atoi((shared->argv)[1]);
		philo->state = WANT_TO_EAT;
		philo->still_alive = 1;
		gettimeofday(&(philo->state_change), NULL);
		gettimeofday(&(philo->last_meal), NULL);
		philo->shared = shared;
		if (pthread_create(th + i, NULL, &routine, philo) != 0)
		{
			printf("Error: Failed to create thread number %d\n", i);
		}
	}
	else
		*(shared->all_alive) = 0;
}

int	wait_thread_ending(pthread_t *th, char **argv)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("Error: Failed to join thread number %d\n", i);
			exit_code = 1;
		}
		i++;
	}
	return (exit_code);
}
