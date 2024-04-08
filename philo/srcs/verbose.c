/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 01:11:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	select_log_msg(t_philo *philo)
{
	if (philo->state == TAKE_FORKS)
		print_log_state(philo, "has taken a fork");
	else if (philo->state == EATING)
		print_log_state(philo, "is eating");
	else if (philo->state == SLEEPING)
		print_log_state(philo, "is sleeping");
	else if (philo->state == THINKING)
		print_log_state(philo, "is thinking");
	else if (philo->state == DEAD)
		print_log_state(philo, "died");
}

void	print_log_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->table->locker->write));
	if (dinner_is_not_finished(philo))
		printf("%10zu ms %d %s\n", timestamp(philo->time->start_time), philo->id, msg);
	if (philo->state == DEAD)
		modify_dead_flag(philo->table);
	pthread_mutex_unlock(&(philo->table->locker->write));
}
