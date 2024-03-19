/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:12:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/19 18:31:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
Return non-zero value if 'c' is in 0-9
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
