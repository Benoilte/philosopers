/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 15:47:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_argument_definition(int arg)
{
	if (arg == NUMBER_OF_PHILOSOPHER)
		printf("Number of philosopher");
	else if (arg == TIME_TO_DIE)
		printf("Time to die");
	else if (arg == TIME_TO_EAT)
		printf("Time to eat");
	else if (arg == TIME_TO_SLEEP)
		printf("Time to sleep");
	else if (arg == MEALS_LIMIT)
		printf("Number of times each philosopher must eat");
}

void	print_philo_status(t_philo *philo)
{
	if (philo->state == TAKE_FORKS)
		print_log(philo, "has taken a fork");
	else if (philo->state == EATING)
		print_log(philo, "is eating");
	else if (philo->state == SLEEPING)
		print_log(philo, "is sleeping");
	else if (philo->state == THINKING)
		print_log(philo, "is thinking");
	else if (philo->state == DEAD)
		print_dead_log(philo, "died");
	else
		print_log(philo, "Hello, let's start the simulation");
}

void	print_log(t_philo *philo, char *msg)
{
	if (dinner_is_not_finished(philo))
	{
		sem_wait(philo->table->shared_locker->print);
		if (dinner_is_not_finished(philo))
			printf("%8zu ms %d %s\n", ms_timestamp(philo->time->start_time),
				philo->id, msg);
		sem_post(philo->table->shared_locker->print);
	}
}

void	print_dead_log(t_philo *philo, char *msg)
{
	sem_wait(philo->table->shared_locker->print);
	printf("%8zu ms %d %s\n", ms_timestamp(philo->time->start_time),
		philo->id, msg);
	sem_post(philo->table->shared_locker->print);
}
