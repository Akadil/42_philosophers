/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 00:48:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fork.h"

void    ft_unlock_forks2(t_philo *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
    pthread_mutex_unlock(&philo->fork);
}

int ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	if (ft_get_time(philo) != 0)
		return (ft_unlock_forks2(philo), -1);
	if (philo->rules->time_die - (philo->time_curr - philo->time_eat) <= 0)
	{
		philo->exit_code = -1;
		return (ft_unlock_forks2(philo), -1);
	}
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %d has taken fork!\n", philo->time_curr - philo->rules->time_start, philo->num);
	return (0);
}
