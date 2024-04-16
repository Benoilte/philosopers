/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:00:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 09:35:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_routine_alone(t_table *table, int *status)
{
	t_philo	*philo;

	philo = table->first_philo;
	set_philosophers_dinner_start(table);
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
	set_philosophers_dinner_start(table);
	while (i <= table->nbr_philo)
	{
		if (pthread_create(&(philo->thread), NULL, &routine, philo) != 0)
		{
			printf("Error: Failed to create philosopher %d thread\n",
				philo->id);
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
	modify_philo_state(philo, TAKE_FORKS);
	print_philo_status(philo);
	ms_sleep(philo->time->time_to_die);
	philo_die(philo);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (dinner_is_not_finished(philo))
	{
		if (read_state(philo) == WANT_TO_EAT)
			take_forks(philo);
		if (read_state(philo) == READY_TO_EAT)
			philo_eat(philo);
		if (read_state(philo) == WANT_TO_SLEEP)
			philo_sleep(philo);
		if (read_state(philo) == WANT_TO_THINK)
			philo_think(philo);
	}
	return (NULL);
}

int	dinner_is_not_finished(t_philo *philo)
{
	if (read_dead_flag(philo->table))
		return (DINNER_IS_FINISHED);
	if (read_meals_limit_reached(philo->table))
		return (DINNER_IS_FINISHED);
	return (DINNER_CONTINUE);
}
