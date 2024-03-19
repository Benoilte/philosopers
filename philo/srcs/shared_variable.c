/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 00:34:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_shared_var	*new_shared_variable(int argc, char **argv)
{
	t_shared_var	*shared;

	shared = (t_shared_var *)malloc(sizeof(t_shared_var));
	if (!shared)
		return (NULL);
	if (!malloc_shared_variable(shared, ft_atoi(argv[1])))
	{
		free(shared);
		return (NULL);
	}
	gettimeofday(&(shared->start), NULL);
	shared->argc = argc;
	shared->argv = argv;
	pthread_mutex_init(&(shared->mutex), NULL);
	return (shared);
}

int	malloc_shared_variable(t_shared_var *shared, int n_philo)
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
	shared->all_alive = (int *)malloc(sizeof(int));
	if (!shared->all_alive)
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
	*(shared->all_alive) = 1;
	return (1);
}
