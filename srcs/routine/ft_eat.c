/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 15:46:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_eat.h"

int	ft_eat(t_philo *philo)
{
	if (ft_update_time(philo) != 0)
		return (ft_unlock_forks(philo), -1);
	if (ft_check_status(philo) != 0)
		return (ft_unlock_forks(philo), -1);
	printf("[%7dms] %d is eating\n", ft_get_time(philo), philo->num);
	philo->num_meal++;
	ft_update_time_last_meal(philo);
	if (usleep(philo->rules->time_eat * 1000) != 0)
		return (ft_unlock_forks(philo), -1);
	return (ft_unlock_forks(philo), 0);
}
