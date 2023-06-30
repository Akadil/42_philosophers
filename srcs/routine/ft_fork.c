/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 19:20:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fork.h"

int	ft_fork(t_philo *philo)
{
	ft_lock_forks(philo);
	if (ft_update_time(philo) != 0)
	{
		ft_unlock_forks(philo);
		return (-1);
	}
	if (ft_check_status(philo) != 0)
	{
		ft_unlock_forks(philo);
		return (-1);
	}
	printf("[%7dms] %d has taken fork!\n", ft_get_time(philo), philo->num);
	return (0);
}

void	ft_lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->fork);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

