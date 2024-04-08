/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:00:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 20:30:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_routine_alone(t_table *table, int *status)
{
	t_philo	*philo;

	philo = table->first_philo;
	init_philosophers_dinner_start(table);
	if (pthread_create(&(philo->thread), NULL, &routine_for_one, philo) != 0)
	{
		printf("Error: Failed to create philosopher %d thread\n", philo->id);
		table->dead_flag = 1;
		*status = EXIT_FAILURE;
		return ;
	}
}

void	start_routine_together(t_table *table, int *status)
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = table->first_philo;
	init_philosophers_dinner_start(table);
	while (i <= table->nbr_philo)
	{
		if (pthread_create(&(philo->thread), NULL, &routine, philo) != 0)
		{
			printf("Error: Failed to create philosopher %d thread\n", philo->id);
			table->dead_flag = 1;
			*status = EXIT_FAILURE;
			return ;
		}
		philo = philo->next;
		i++;
	}
}

void	*routine_for_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->left_fork));
	philo->state = TAKE_FORKS;
	select_log_msg(philo);
	pthread_mutex_unlock(&(philo->left_fork));
	ft_usleep(philo->time->time_to_die);
	philo->state = DEAD;
	modify_dead_flag(philo);
	select_log_msg(philo);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->table->locker->write));
	print_philo(philo);
	pthread_mutex_unlock(&(philo->table->locker->write));
	return (NULL);
}
