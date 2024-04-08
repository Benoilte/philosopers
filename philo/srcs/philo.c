/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 18:50:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (arg_is_not_valid(argc, argv))
		return (EXIT_FAILURE);
	return (prep_philosophers_dinner(argc, argv));
}

int	prep_philosophers_dinner(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philosophers;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	philosophers = init_all_philosophers(table);
	if (!philosophers)
	{
		clean_table(table, &exit_status);
		return (EXIT_FAILURE);
	}
	table->first_philo = philosophers;
	run_philosophers_dinner(table, &exit_status);
	return (exit_status);
}

void	run_philosophers_dinner(t_table *table, int *status)
{
	if (table->nbr_philo == 1)
		start_routine_alone(table, status);
	else
		start_routine_together(table, status);
	start_supervisor(table, status);
	wait_the_end_of_philosophers_dinner(table, status);
	wait_the_end_of_supervisor(table, status);
	clean_table(table, status);
}

void	wait_the_end_of_philosophers_dinner(t_table *table, int *status)
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = table->first_philo;
	while (i <= table->nbr_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error: Failed to join philosopher %d thread\n", philo->id);
			*status = EXIT_FAILURE;
		}
		philo = philo->next;
		i++;
	}
}
