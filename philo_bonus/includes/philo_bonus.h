/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/19 18:30:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

// philo_bonus.c

int	args_are_wrong(int argc, char **argv);

// ft_atoi.c

int	ft_atoi(const char *str);

// ft_isdigit.c

int	ft_isdigit(int c);

#endif
