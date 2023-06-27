/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 20:36:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fork.h"

int	ft_is_my_turn(t_philo *philo)
{
	if(philo->rules->num_philo % 2 == 0)
	{
		if (philo->num % 2 == 0)
			return (1);
		return (0);
	}
	if (philo->rules->num_philo == 1)
		return (1);
	philo->iter = philo->rules->num_philo / 2;
	philo->host = philo->num_meal % philo->rules->num_philo;
	while(philo->iter != 0)
	{
		if (philo->num % philo->rules->num_philo == philo->host)
			return (1);
		philo->host = philo->host + 2;
		if (philo->host > philo->rules->num_philo)
			philo->host = philo->host % philo->rules->num_philo;
		philo->iter--;
	}
	return (0);
}

void    ft_unlock_forks2(t_philo *philo)
{
	if (ft_is_my_turn(philo))
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

int ft_fork(t_philo *philo)
{
	if (ft_is_my_turn(philo))
	{
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->next->fork);
	}
	if (ft_get_time(philo) != 0)
		return (ft_unlock_forks2(philo), -1);
	// pthread_mutex_lock(&philo->meal);
	// if (philo->rules->time_die - (philo->time_curr - philo->time_eat) <= 0)
	// {
	// 	pthread_mutex_unlock(&philo->meal);
	// 	philo->exit_code = -1;
	// 	return (ft_unlock_forks2(philo), -1);
	// }
	// pthread_mutex_unlock(&philo->meal);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %d has taken fork!\n", philo->time_curr - philo->rules->time_start, philo->num);
	return (0);
}
