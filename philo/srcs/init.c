/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/21 15:06:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_shared_var	*new_shared_variable(int argc, char **argv)
{
	t_shared_var	*shared;

	shared = (t_shared_var *)malloc(sizeof(t_shared_var));
	if (!shared)
		return (NULL);
	if (!init_shared_variable(shared, ft_atoi(argv[1])))
	{
		free(shared);
		return (NULL);
	}
	gettimeofday(&(shared->start), NULL);
	shared->argc = argc;
	shared->argv = argv;
	pthread_mutex_init(&(shared->m_write), NULL);
	pthread_mutex_init(&(shared->m_forks), NULL);
	pthread_mutex_init(&(shared->m_meal), NULL);
	return (shared);
}

int	init_shared_variable(t_shared_var *shared, int n_philo)
{
	shared->forks = (int *)malloc(sizeof(int) * n_philo);
	if (!shared->forks)
		return (0);
	shared->meals = (int *)malloc(sizeof(int) * n_philo);
	if (!shared->meals)
	{
		free(shared->forks);
		return (0);
	}
	shared->run_simulation = (int *)malloc(sizeof(int));
	if (!shared->run_simulation)
	{
		free(shared->forks);
		free(shared->meals);
		return (0);
	}
	while (--n_philo >= 0)
	{
		shared->forks[n_philo] = 1;
		shared->meals[n_philo] = 0;
	}
	*(shared->run_simulation) = 1;
	return (1);
}

void	init_philo(t_philo *philo, t_shared_var *shared, int i)
{
	philo->id = i;
	philo->n_philo = ft_atoi((shared->argv)[1]);
	philo->time_to_die = ft_atoi((shared->argv)[2]);
	philo->time_to_eat = ft_atoi((shared->argv)[3]);
	philo->time_to_sleep = ft_atoi((shared->argv)[4]);
	if (shared->argc == 6)
		philo->time_to_sleep = ft_atoi((shared->argv)[5]);
	else
		philo->time_to_sleep = 0;
	philo->state = WANT_TO_EAT;
	philo->still_alive = 1;
	gettimeofday(&(philo->state_change), NULL);
	gettimeofday(&(philo->last_meal), NULL);
	philo->shared = shared;
}
