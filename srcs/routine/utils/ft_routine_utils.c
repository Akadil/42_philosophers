/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:28:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/26 23:44:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include "libft.h"
#include "../includes/ft_time.h"
#include "ft_error.h"
#include <stdio.h>

void	ft_set_all_statuses(t_philo *philo);

void    ft_handle_error(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->exit);
	if (philo->exit_global == -1)
	{
		pthread_mutex_unlock(&philo->rules->exit);
		return ;
	}
	if (philo->exit_code == -1)
	{
		if (ft_get_time(philo) != 0)
		{
			ft_perror_d(philo->num);
			pthread_mutex_unlock(&philo->rules->exit);
			return ;
		}
		printf("[%7dms] %d died\n", philo->time_curr - philo->rules->time_start, philo->num);
	}
	else
	{
		ft_set_all_statuses(philo);
		ft_perror_d(philo->num);
	}
	pthread_mutex_unlock(&philo->rules->exit);
}

void	ft_set_all_statuses(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_lock(&philo->exit);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		philo->exit_global = -1;
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < philo->rules->num_philo)
	{
		pthread_mutex_unlock(&philo->exit);
		philo = philo->next;
		i++;
	}
}
