/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:50:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 13:42:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

// void	print_data_structure(t_table *table)
// {
// 	printf("\nDISPLAY DATA STRUCTURE\n");
// 	print_table(table);
// 	print_time(table->time);
// 	print_philosophers(table->first_philo);
// }

// void	print_table(t_table *table)
// {
// 	printf("\nDISPLAY TABLE SRUCTURE\n");
// 	printf("Number of philosopher: %d\n", table->nbr_philo);
// 	printf("dead_flag: %d\n", table->dead_flag);
// 	printf("meals_limit: %d\n", table->meals_limit);
// 	printf("meals_limit_reached: %d\n", table->meals_limit_reached);
// }

// void	print_time(t_time *time)
// {
// 	printf("\nDISPLAY TIME STRUCTURE\n");
// 	printf("Time to die: %d\n", time->time_to_die);
// 	printf("Time to eat: %d\n", time->time_to_eat);
// 	printf("Time to sleep: %d\n", time->time_to_sleep);
// 	printf("Start time: %zu\n", time->start_time);
// }

// void	print_philosophers(t_philo *philosophers)
// {
// 	t_philo	*philo;

// 	philo = philosophers;
// 	printf("\nDISPLAY PHILOSOPHER STRUCTURE\n");
// 	while (philo)
// 	{
// 		print_philo(philo);
// 		if (philo->id == philo->table->nbr_philo)
// 			break ;
// 		philo = philo->next;
// 	}
// }

// void	print_philo(t_philo *philo)
// {
// 	printf("\n\nDISPLAY PHILO\n");
// 	printf("philo id: %d\n", philo->id);
// 	printf("philo state: %d\n", philo->state);
// 	printf("philo meals eaten: %d\n", philo->meals_eaten);
// 	printf("philo last meals eaten: %zu\n", timestamp(philo->last_meal_eaten));
// 	printf("philo left fork address: %p\n", &(philo->left_fork));
// 	printf("philo right fork address: %p\n", philo->right_fork);
// }
