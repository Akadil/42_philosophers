/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/22 00:53:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fork.h"

int ft_fork(t_philo *philo)
{
    while(ft_is_my_turn(philo) == 0)
    {
        philo->exit_code = ft_think(philo);
        if (philo->exit_code != 0)
            return (philo->exit_code);
        philo->round++;
    }
    
    philo->exit_code = ft_fork_left(philo);
    if (philo->exit_code != 0)
        return (philo->exit_code);
    // printf("I was here %d\n", philo->num);
    philo->exit_code = ft_fork_right(philo);
    if (philo->exit_code != 0)
    {
        pthread_mutex_unlock(&philo->mutex);
        return (philo->exit_code);
    }
    // printf("I was here2 %d\n", philo->num);
    philo->exit_code = ft_get_time(philo);
    if (philo->exit_code == -1)
    {
        pthread_mutex_unlock(&philo->mutex);
        pthread_mutex_unlock(&philo->next->mutex);
        return (-2);
    }
    printf("[%7dms] %d has taken fork!\n", philo->time_curr - philo->rules->time_start, philo->num);
    return (0);
}

int ft_fork_left(t_philo *philo)
{
    while (philo->prev->status == 1)
    {
        if (usleep(10000) == -1)
            return (-2);
        if (philo->rules->status_code != 0)
            return (-3);
        philo->exit_code = ft_time_available(philo); 
        if (philo->exit_code == -1)
            return (-2);
        if (philo->time_live <= 0)
            return (-1);
    }
    pthread_mutex_lock(&philo->mutex);
    return (0);
}

int ft_fork_right(t_philo *philo)
{
    while (philo->next->status == 1)
    {
        if (usleep(10000) == -1)
            return (-2);
        if (philo->rules->status_code != 0)
            return (-3);
        philo->exit_code = ft_time_available(philo); 
        if (philo->exit_code == -1)
            return (-2);
        if (philo->time_live <= 0)
            return (-1);
    }
    pthread_mutex_lock(&philo->next->mutex);
    return (0);
}

int ft_is_my_turn(t_philo *philo)
{
    int host;
    int num_iterations;
    int i;

    pthread_mutex_lock(&philo->rules->my_turn);
    num_iterations = philo->rules->num_philo / 2;
    host = philo->round % philo->rules->num_philo;
    i = 0;
    while(i < num_iterations)
    {
        if (philo->num % philo->rules->num_philo == host)
            return (pthread_mutex_unlock(&philo->rules->my_turn), 1);
        host = host + 2;
        if (host > philo->rules->num_philo)
            host = host % philo->rules->num_philo;
        i++;
    }
    pthread_mutex_unlock(&philo->rules->my_turn);
    return (0);
}