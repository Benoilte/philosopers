/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:50:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 14:54:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_data_structure(t_table *table)
{
	printf("\nDISPLAY DATA STRUCTURE\n");
	print_table(table);
	print_time(table->time);
	print_philosophers(table->first_philo);
}

void	print_table(t_table *table)
{
	printf("\nDISPLAY TABLE SRUCTURE\n");
	printf("Number of philosopher: %d\n", table->nbr_philo);
	printf("dead_philo: %d\n", table->dead_philo);
	printf("meals_limit: %d\n", table->meals_limit);
}

void	print_time(t_time *time)
{
	printf("\nDISPLAY TIME STRUCTURE\n");
	printf("Time to die: %d\n", time->time_to_die);
	printf("Time to eat: %d\n", time->time_to_eat);
	printf("Time to sleep: %d\n", time->time_to_sleep);
	printf("Start time: %zu\n", time->start_time);
}

void	print_philosophers(t_philo *philosophers)
{
	t_philo	*philo;

	philo = philosophers;
	printf("\nDISPLAY PHILOSOPHER STRUCTURE\n");
	while (philo)
	{
		printf("\n\nDISPLAY PHILO\n");
		printf("philo id: %d\n", philo->id);
		printf("philo state: %d\n", philo->state);
		printf("philo meals eaten: %d\n", philo->meals_eaten);
		printf("philo last meals eaten: %zu\n", philo->last_meal_eaten);
		if (philo->id == philo->table->nbr_philo)
			break ;
		philo = philo->next;
	}
}
