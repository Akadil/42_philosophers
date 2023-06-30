/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:27:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:03:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_philo.h"
#include <pthread.h>
#include "ft_error.h"

void	ft_set_all_statuses(t_philo *philo);

void	ft_handle_error(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->exit);
	if (philo->exit_code != 0)
	{
		pthread_mutex_unlock(&philo->rules->exit);
		return ;
	}
	ft_set_all_statuses(philo);
	ft_perror_d(philo->num);
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
		philo->exit_code = -3;
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
