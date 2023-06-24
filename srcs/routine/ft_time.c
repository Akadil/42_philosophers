/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 17:34:09 by akalimol         ###   ########.fr       */
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
	philo->time_curr = (philo->timeval.tv_sec * 1000 % 100000000) + (philo->timeval.tv_usec / 1000);
	return (0);
}

int    ft_get_time_beginning(t_philo *philo)
{
	/*	find time to sleep and sleep till that time	*/
	philo->time_eat = -1;
	if (gettimeofday(&philo->timeval, NULL) != 0)
		return (-2);
	philo->time_eat = (philo->timeval.tv_sec * 1000 % 100000000) + (philo->timeval.tv_usec / 1000);
	usleep((philo->rules->time_start - philo->time_eat) * 1000);
	philo->time_eat = philo->rules->time_start;
	// gettimeofday(&philo->timeval, NULL);
	// printf("Philo %d: Start time - %ld\n", philo->num, philo->timeval.tv_sec * 1000 % 100000000 + philo->timeval.tv_usec / 1000);
	return (0);
}

int ft_time_available(t_philo *philo)
{
	philo->time_live = -1;
	philo->exit_code = ft_get_time(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	philo->time_skip = philo->time_curr - philo->time_eat;
	philo->time_live = philo->rules->time_die - philo->time_skip;
	return (0);
}

int    ft_update_philo_time(t_philo *philo)
{
	philo->exit_code = ft_get_time(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	philo->time_eat = philo->time_curr;
	return (0);
}
