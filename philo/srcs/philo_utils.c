/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:01:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 14:22:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	while (*(((t_philo *)philo)->shared->run_simulation))
	{
		ft_eat((t_philo *)philo);
		ft_sleep((t_philo *)philo);
		ft_think((t_philo *)philo);
	}
	free(philo);
	return (NULL);
}

void	print_log(int id, t_data *shared, char *msg)
{
	pthread_mutex_lock(&(shared->m_write));
	if (*(shared->run_simulation))
		printf("%zu %d %s\n", timestamp(&(shared->start)), id + 1, msg);
	pthread_mutex_unlock(&(shared->m_write));
}

void	clean(pthread_t *th, t_data *shared)
{
	if (th)
		free(th);
	if (shared)
	{
		free(shared->run_simulation);
		free(shared->forks);
		free(shared->meals);
		free(shared->last_meal);
		pthread_mutex_destroy(&(shared->m_write));
		pthread_mutex_destroy(&(shared->m_forks));
		pthread_mutex_destroy(&(shared->m_meal));
		free(shared);
	}
}

int	wait_thread_end(pthread_t *th, pthread_t monitor, t_data *shared)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	while (i < shared->n_philo)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("Error: Failed to join philosopher number %d\n", i);
			exit_code = 1;
		}
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
	{
		printf("Error: Failed to join monitor \n");
		exit_code = 1;
	}
	return (exit_code);
}
