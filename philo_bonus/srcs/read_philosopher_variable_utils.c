/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_philosopher_variable_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:08:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 11:20:34 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	get_philo_state(t_philo *philo)
{
	int	state;

	sem_wait(philo->philo_locker->state);
	state = philo->state;
	sem_post(philo->philo_locker->state);
	return (state);
}
