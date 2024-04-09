/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 16:38:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int	exit_code;

	exit_code = 0;
	sem_unlink(LOCK_FORKS);
	sem_unlink(LOCK_WRITE);
	if (argc == 5 || argc == 6)
	{
		if (arg_format_is_wrong(argc, argv))
			return (EXIT_FAILURE);
		exit_code = start_simulation(argc, argv);
	}
	else
	{
		exit_code = EXIT_FAILURE;
		printf("Error: wrong number of argument.\n");
	}
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
				return (FORMAT_FAILURE);
			}
			j++;
		}
		if (ft_atoi(argv[i]) == 0)
		{
			printf("Error: (%s) Format. Arg must be bigger than 0\n", argv[i]);
			return (FORMAT_FAILURE);
		}
		i++;
	}
	return (FORMAT_SUCCESS);
}

int	start_simulation(int argc, char **argv)
{
	t_philo			*philo;
	pid_t			*pid;

	philo = init_philo(argc, argv);
	if (!philo)
		return (EXIT_FAILURE);
	pid = (pid_t *)malloc(sizeof(pid_t) * philo->count);
	if (!pid)
	{
		clean(philo);
		return (EXIT_FAILURE);
	}
	init_pid_tab(pid, philo->count);
	create_philosopher(philo, pid);
	clean(philo);
	free(pid);
	return (EXIT_SUCCESS);
}

int	create_philosopher(t_philo *philo, pid_t *pid)
{
	sem_t			*sem_forks;
	sem_t			*sem_write;
	int				i;

	sem_forks = NULL;
	sem_write = NULL;
	if (init_semaphore(philo, sem_forks, sem_write) == SEMAPHORES_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < philo->count)
	{
		pid[i] = fork();
		if (pid[i] && i != (philo->count - 1))
			philo->id += 1;
		else
			break ;
		i++;
	}
	if (pid[philo->id] == 0)
		start_routine(philo);
	i = 0;
	while (i < philo->count)
		waitpid(pid[i++], NULL, 0);
	sem_close(sem_forks);
	sem_close(sem_write);
	return (EXIT_SUCCESS);
}
