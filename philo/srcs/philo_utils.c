/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:01:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/03 10:43:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	if (!((((t_philo *)philo)->id) % 2))
		((t_philo *)philo)->state = SLEEP;
	while (*(((t_philo *)philo)->shared->run_simulation))
	{
		ft_eat((t_philo *)philo);
		ft_sleep((t_philo *)philo);
		ft_think((t_philo *)philo);
	}
	free(philo);
	return (NULL);
}

void	print_log(int id, t_data *shared, char *msg, int msg_is_died)
{
	pthread_mutex_lock(&(shared->m_write));
	if (*(shared->run_simulation))
		printf("%zu %d %s\n", timestamp(&(shared->start)), id + 1, msg);
	if (msg_is_died)
		*(shared->run_simulation) = 0;
	pthread_mutex_unlock(&(shared->m_write));
}

void	clean(pthread_t *th, t_data *shared)
{
	int	i;

	i = 0;
	if (th)
		free(th);
	if (shared)
	{
		free(shared->run_simulation);
		free(shared->meals);
		free(shared->last_meal);
		pthread_mutex_destroy(&(shared->m_write));
		pthread_mutex_destroy(&(shared->m_meal));
		while (i < shared->n_philo)
		{
			pthread_mutex_destroy(shared->m_forks + i);
			i++;
		}
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
