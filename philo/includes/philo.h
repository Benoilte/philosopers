/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/19 18:14:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_philosopher
{
	pthread_t	*philos;
	int			size;
}	t_philosophers;

// philo.c

int		args_are_wrong(int argc, char **argv);
void	*routine(void *num);

// ft_atoi.c

int		ft_atoi(const char *str);

// ft_isdigit.c

int		ft_isdigit(int c);

#endif
