/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 19:49:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "struct_philo.h"

/**
 * @brief       get current time
 * 
 * @return int  current time in milliseconds, -1 if error occured
 */
int    ft_get_time(t_philo *philo)
{	
	philo->time_curr = -1;
	if (gettimeofday(&philo->timeval, NULL) != 0)
		return (-2);
	philo->time_curr = (philo->timeval.tv_sec * 1000) + (philo->timeval.tv_usec / 1000);
	return (0);
}

int    ft_start_schedule(t_philo *philo)
{
	if (ft_get_time(philo) != 0)
	{
		philo->exit_code = -2;
		return (-1);
	}
	philo->time_skip = (philo->time_eat - philo->time_curr) * 1000;
	if (philo->num % 2 == 0)
		philo->time_skip += philo->rules->time_sleep * 1000;
	if (philo->rules->num_philo % 2 == 1)
		if (philo->num == philo->rules->num_philo)
			philo->time_skip += 1000;
	usleep(philo->time_skip);
	return (0);
}
