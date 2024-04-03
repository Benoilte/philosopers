/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/03 10:47:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*new_data(int argc, char **argv)
{
	t_data	*shared;

	shared = (t_data *)malloc(sizeof(t_data));
	if (!shared)
		return (NULL);
	shared->n_philo = ft_atoi(argv[1]);
	shared->time_to_die = ft_atoi(argv[2]);
	shared->time_to_eat = ft_atoi(argv[3]);
	shared->time_to_sleep = ft_atoi(argv[4]);
	gettimeofday(&(shared->start), NULL);
	if (argc == 6)
		shared->meals_limit = ft_atoi(argv[5]);
	else
		shared->meals_limit = 0;
	if (!init_data(shared, shared->n_philo))
	{
		free(shared);
		return (NULL);
	}
	fill_data_ptr(shared);
	pthread_mutex_init(&(shared->m_write), NULL);
	pthread_mutex_init(&(shared->m_meal), NULL);
	return (shared);
}

int	init_data(t_data *shared, int size)
{
	shared->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	if (!shared->m_forks)
		return (0);
	shared->meals = (int *)malloc(sizeof(int) * size);
	if (!shared->meals)
	{
		free(shared->m_forks);
		return (0);
	}
	shared->last_meal = (size_t *)malloc(sizeof(size_t) * size);
	if (!shared->last_meal)
	{
		free(shared->m_forks);
		free(shared->meals);
		return (0);
	}
	shared->run_simulation = (int *)malloc(sizeof(int));
	if (!shared->run_simulation)
	{
		free(shared->m_forks);
		free(shared->meals);
		free(shared->last_meal);
		return (0);
	}
	return (1);
}

void	fill_data_ptr(t_data *shared)
{
	int	i;

	i = 0;
	while (i < shared->n_philo)
	{
		pthread_mutex_init(shared->m_forks + i, NULL);
		shared->meals[i] = 0;
		shared->last_meal[i] = ft_time(&(shared->start));
		i++;
	}
	*(shared->run_simulation) = 1;
}

void	init_philo(t_philo *philo, t_data *shared, int i)
{
	philo->id = i;
	philo->left_fork_id = i;
	if (i == shared->n_philo - 1)
		philo->right_fork_id = 0;
	else
		philo->right_fork_id = i + 1;
	philo->state = EAT;
	gettimeofday(&(philo->last_meal), NULL);
	philo->shared = shared;
}
