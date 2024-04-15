/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:50:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:42:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_structure(t_table *table, t_parent *parent, t_philo *philo)
{
	printf("\nDISPLAY DATA STRUCTURE\n");
	print_table(table);
	print_time(table->time);
	print_parent(table, parent);
	print_philosophers(philo);
}

void	print_table(t_table *table)
{
	printf("\nDISPLAY TABLE SRUCTURE\n");
	printf("Number of philosopher: %d\n", table->nbr_philo);
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

void	print_parent(t_table *table, t_parent *parent)
{
	int	i;

	printf("\n\nDISPLAY PARENT\n");
	printf("parent nbr philosophers full: %d\n", parent->nbr_philosophers_full);
	printf("parent is one philosopher die: %d\n",
		parent->is_one_philosopher_die);
	i = 0;
	while (i < table->nbr_philo)
	{
		printf("philo_pid[%d]: %u ", i, parent->philosopher_pid[i]);
		i++;
	}
	printf("\n");
}

void	print_philosophers(t_philo *philo)
{
	printf("\n\nDISPLAY PHILO\n");
	printf("philo id: %d\n", philo->id);
	printf("philo state: %d\n", philo->state);
	printf("philo meals eaten: %d\n", philo->meals_eaten);
	printf("philo last meals eaten: %zu\n",
		ms_timestamp(philo->last_meal_eaten));
	printf("philo is dead: %d\n", philo->is_dead);
	printf("philo is full: %d\n", philo->is_full);
}
