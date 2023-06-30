/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:28:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:27:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/time.h"
#include "struct_philo.h"
#include <unistd.h>
#include <pthread.h>

void	ft_handle_one_philo(t_philo *philo)
{
	usleep(philo->rules->time_die * 1000 + 1000);
}

#include <stdio.h>

int	ft_start_schedule(t_philo *philo)
{
	if (ft_update_time(philo) != 0)
	{
		philo->exit_code = -2;
		return (-1);
	}
	printf("%d", (philo->time_eat - philo->time_curr) * 1000);
	usleep((philo->time_eat - philo->time_curr) * 1000);
	if (philo->num % 2 == 0)
		usleep(philo->rules->time_sleep * 1000);
	if (philo->rules->num_philo % 2 == 1)
		if (philo->num == philo->rules->num_philo)
			usleep(1000);
	return (0);
}

void	ft_set_end_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->exit);
	philo->exit_code = -4;
	pthread_mutex_unlock(&philo->exit);
}
