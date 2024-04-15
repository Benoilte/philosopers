/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_parent_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:35:02 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 15:10:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_parent_monitoring(t_parent *parent, int *status)
{
	if (pthread_create(&(parent->death_supervisor), NULL,
			&death_monitoring, parent))
	{
		printf("Error: Failed to create death_supervisor thread ");
		printf("in the parent process\n");
		set_stop_simulation(parent);
		*status = EXIT_FAILURE;
		return ;
	}
	if (pthread_create(&(parent->meals_eaten_supervisor), NULL,
			&meals_eaten_monitoring, parent))
	{
		printf("Error: Failed to create meals_eaten_supervisor thread ");
		printf("in the parent process\n");
		set_stop_simulation(parent);
		wait_supervisors_end(parent, status);
		*status = EXIT_FAILURE;
		return ;
	}
	wait_supervisors_end(parent, status);
}

void	*death_monitoring(void *arg)
{
	t_parent	*parent;

	parent = (t_parent *)arg;
	sem_wait(parent->table->shared_locker->death);
	set_stop_simulation(parent);
	return (NULL);
}

void	*meals_eaten_monitoring(void *arg)
{
	t_parent	*parent;

	parent = (t_parent *)arg;
	while (parent->nbr_philosophers_full < parent->table->nbr_philo)
	{
		sem_wait(parent->table->shared_locker->full);
		parent->nbr_philosophers_full++;
	}
	set_stop_simulation(parent);
	return (NULL);
}

void	set_stop_simulation(t_parent *parent)
{
	int	i;

	i = 0;
	sem_wait(parent->read_and_update);
	if (parent->is_simulation_stopped == YES)
	{
		sem_post(parent->read_and_update);
		return ;
	}
	else
		parent->is_simulation_stopped = YES;
	sem_post(parent->read_and_update);
	while (i < parent->table->nbr_philo)
	{
		sem_post(parent->table->shared_locker->stop);
		i++;
	}
	i = 0;
	while (i < parent->table->nbr_philo)
	{
		sem_post(parent->table->shared_locker->full);
		i++;
	}
	sem_post(parent->table->shared_locker->death);
}

void	wait_supervisors_end(t_parent *parent, int *status)
{
	if (pthread_join(parent->death_supervisor, NULL))
	{
		printf("Error: Failed to join death_supervisor thread\n");
		if (status)
			*status = EXIT_FAILURE;
	}
	if (pthread_join(parent->meals_eaten_supervisor, NULL))
	{
		printf("Error: Failed to join meals_eaten_supervisor thread\n");
		if (status)
			*status = EXIT_FAILURE;
	}
}
