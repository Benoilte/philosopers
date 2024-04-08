/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 14:48:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (arg_is_not_valid(argc, argv))
		return (ERROR);
	return (prep_philosophers_dinner(argc, argv));
}

int	prep_philosophers_dinner(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philosophers;

	table = init_table(argc, argv);
	if (!table)
		return (ERROR);
	philosophers = init_all_philosophers(table);
	if (!philosophers)
	{
		clean_table(table);
		return (ERROR);
	}
	table->first_philo = philosophers;
	print_data_structure(table);
	clean_table(table);
	return (OK);
}
