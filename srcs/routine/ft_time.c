/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:47:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include "struct_philo.h"

/**
 * @brief       get current time
 * 
 * @return int  current time in milliseconds, -1 if error occured
 */
int    ft_get_time(t_philo *philo)
{
    struct timeval  timeval;
    
    pthread_mutex_lock(&philo->rules->time_of_day);
    philo->time_curr = -1;
    if (gettimeofday(&timeval, NULL) != 0)
        return (pthread_mutex_unlock(&philo->rules->time_of_day), -2);
    philo->time_curr = (timeval.tv_sec * 1000 % 100000000) + (timeval.tv_usec / 1000);
    pthread_mutex_unlock(&philo->rules->time_of_day);
    return (0);
}

int    ft_get_time_beginning(t_philo *philo)
{
    struct timeval  timeval;
    
    pthread_mutex_lock(&philo->rules->time_of_day);
    philo->time_eat = -1;
    if (gettimeofday(&timeval, NULL) != 0)
        return (pthread_mutex_unlock(&philo->rules->time_of_day), -2);
    philo->time_eat = (timeval.tv_sec * 1000 % 100000000) + (timeval.tv_usec / 1000);
    pthread_mutex_unlock(&philo->rules->time_of_day);
    return (0);
}

int ft_time_available(t_philo *philo)
{
    int time_passed;

    pthread_mutex_lock(&philo->rules->time_available);
    philo->time_live = -1;
    philo->exit_code = ft_get_time(philo);
    if (philo->exit_code == -1)
        return (pthread_mutex_unlock(&philo->rules->time_available), -2);
    time_passed = philo->time_eat - philo->time_curr;
    philo->time_live = philo->rules->time_die - time_passed;
    pthread_mutex_unlock(&philo->rules->time_available);
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
