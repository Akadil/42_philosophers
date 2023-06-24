/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/24 18:03:11 by akalimol         ###   ########.fr       */
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
	// printf("%d started taking left fork!\n", philo->num);
	philo->exit_code = ft_fork_left(philo);
	if (philo->exit_code != 0)
		return (philo->exit_code);
	// printf("%d started taking right fork!\n", philo->num);
	philo->exit_code = ft_fork_right(philo);
	if (philo->exit_code != 0)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (philo->exit_code);
	}
	// printf("%d finished taking!\n", philo->num);
	philo->exit_code = ft_get_time(philo);
	if (philo->exit_code != 0)
	{
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		return (philo->exit_code);
	}
	printf("[%7dms] %d has taken fork!\n", philo->time_curr - philo->rules->time_start, philo->num);
	return (0);
}

int ft_fork_left(t_philo *philo)
{
	while (philo->prev->status == 1)
	{
		if (usleep(10) == -1)
			return (-2);
		if (philo->rules->status_code != 0)
			return (-3);
		philo->exit_code = ft_time_available(philo); 
		if (philo->exit_code != 0)
			return (philo->exit_code);
		if (philo->time_live <= 0)
			return (-1);
	}
	// philo->exit_code = ft_time_available(philo); 
	// if (philo->exit_code != 0)
	// 	return (philo->exit_code);
	// printf("%d was here1, [%7dms] \n", philo->num, philo->time_curr - philo->time_eat);
	// if (philo->time_live <= 0)
	// 	return (-1);
	pthread_mutex_lock(&philo->mutex);
	philo->status = 3;
	return (0);
}

int ft_fork_right(t_philo *philo)
{
	while (philo->next->status == 1 || philo->next->status == 3)
	{
		if (usleep(100) == -1)
			return (-2);
		if (philo->rules->status_code != 0)
			return (-3);
		philo->exit_code = ft_time_available(philo); 
		if (philo->exit_code != 0)
			return (philo->exit_code);
		if (philo->time_live <= 0)
			return (-1);
	}
	// philo->exit_code = ft_time_available(philo); 
	// if (philo->exit_code != 0)
	// 	return (philo->exit_code);
	// printf("%d was here2, [%7dms]\n", philo->num, philo->time_curr - philo->time_eat);
	// if (philo->time_live <= 0)
	// 	return (-1);
	pthread_mutex_lock(&philo->next->mutex);
	return (0);
}

int ft_is_my_turn(t_philo *philo)
{
	if (philo->rules->num_philo == 1)
		return (1);
	philo->iter = philo->rules->num_philo / 2;
	philo->host = philo->round % philo->rules->num_philo;
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