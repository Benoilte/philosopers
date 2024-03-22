/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:01:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 12:39:56 by bebrandt         ###   ########.fr       */
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

void	print_log(t_philo *philo, char *msg)
{
	struct timeval	start;
	struct timeval	end;

	pthread_mutex_lock(&(philo->shared->m_write));
	start = philo->shared->start;
	end = philo->state_change;
	printf("%zu %d %s\n", time_diff(&start, &end), philo->id + 1, msg);
	pthread_mutex_unlock(&(philo->shared->m_write));
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
		pthread_mutex_destroy(&(shared->m_write));
		pthread_mutex_destroy(&(shared->m_forks));
		pthread_mutex_destroy(&(shared->m_meal));
		free(shared);
	}
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
