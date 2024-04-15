/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:35:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:34:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_philosopher_routine(t_table *table, t_parent *parent,
			t_philo *philo, int *status)
{
	if (table->nbr_philo == 1)
		start_routine_alone(philo);
	else
		start_routine(philo, status);
	clean_all(table, parent, philo, status);
	exit (EXIT_SUCCESS);
}

void	start_routine_alone(t_philo *philo)
{
	philo->state = TAKE_FORKS;
	print_philo_status(philo);
	ms_sleep(philo->time->time_to_die);
	philo_die(philo);
}

void	start_routine(t_philo *philo, int *status)
{
	if (create_philo_supervisor(philo, status))
		return ;
	while (dinner_is_not_finished(philo))
	{
		if (philo->state == WANT_TO_EAT)
			take_forks(philo);
		if (philo->state == READY_TO_EAT)
			philo_eat(philo);
		if (philo->state == WANT_TO_SLEEP)
			philo_sleep(philo);
		if (philo->state == WANT_TO_THINK)
			philo_think(philo);
	}
	wait_end_of_philo_supervisor(philo, status);
}

int	create_philo_supervisor(t_philo *philo, int *status)
{
	if (pthread_create(&(philo->philosopher_supervisor), NULL,
			&philosopher_monitoring, philo))
	{
		printf("Error: Failed to create philosopher_supervisor thread ");
		printf("for philo %d process\n", philo->id);
		set_philosopher_dead(philo);
		*status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	if (pthread_create(&(philo->stop_dinner_supervisor), NULL,
			&stop_dinner_monitoring, philo))
	{
		printf("Error: Failed to create stop_dinner_supervisor thread ");
		printf("for philo %d process\n", philo->id);
		set_philosopher_dead(philo);
		sem_post(philo->table->shared_locker->death);
		wait_end_of_philo_supervisor(philo, status);
		*status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	wait_end_of_philo_supervisor(t_philo *philo, int *status)
{
	if (pthread_join(philo->philosopher_supervisor, NULL))
	{
		printf("Error: Failed to join death_supervisor thread\n");
		if (status)
			*status = EXIT_FAILURE;
	}
	if (pthread_join(philo->stop_dinner_supervisor, NULL))
	{
		printf("Error: Failed to join meals_eaten_supervisor thread\n");
		if (status)
			*status = EXIT_FAILURE;
	}
}
