/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/27 20:01:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_eat.h"
#include <unistd.h>

int ft_eat(t_philo *philo)
{
	if (ft_get_time(philo) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	printf("[%7dms] %d is eating\n", philo->time_curr - philo->rules->time_start, philo->num);
	philo->num_meal++;
	pthread_mutex_lock(&philo->meal);
	philo->time_eat = philo->time_curr;
	pthread_mutex_unlock(&philo->meal);
	philo->time_skip = philo->rules->time_eat * 1000;
	if (usleep(philo->time_skip) != 0)
		return (-1);
	if (ft_check_status(philo) != 0)
		return (-1);
	return (0);
}
