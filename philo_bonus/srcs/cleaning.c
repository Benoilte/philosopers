/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/12 17:18:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*clean_table(t_table *table)
{
	if (table->time)
		free(table->time);
	if (table->shared_locker)
		clean_shared_locker(table->shared_locker, 5);
	free(table);
	return (NULL);
}

void	*clean_shared_locker(t_shared_locker *shared_locker, int nbr_locker)
{
	if (nbr_locker >= 1)
		sem_close(shared_locker->print);
	if (nbr_locker >= 2)
		sem_close(shared_locker->forks);
	if (nbr_locker >= 3)
		sem_close(shared_locker->death);
	if (nbr_locker >= 4)
		sem_close(shared_locker->full);
	if (nbr_locker >= 5)
		sem_close(shared_locker->stop);
	sem_unlink(PRINT);
	sem_unlink(FORKS);
	sem_unlink(DEATH);
	sem_unlink(FULL);
	sem_unlink(STOP);
	free(shared_locker);
	return (NULL);
}
